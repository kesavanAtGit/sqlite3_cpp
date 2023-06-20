#include "database.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

// actually create one or open an existing database
void Database::openDb() {
    rc = sqlite3_open_v2("inventory.sqlite3", &db, (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE), NULL);
    if(rc) {
        fprintf(stderr, "can't open the database: %s\n", sqlite3_errmsg(db));
        return;
    }else {
        fprintf(stdout, "opened the database successfully. \n");
    }
}

void Database::createTbl() {
    sql = "CREATE TABLE books("
              "NAME TEXT NOT NULL,"
              "ID INT NOT NULL,"
              "AUTHOR TEXT NOT NULL"
        ");";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_DONE) {
        fprintf(stderr, "Can't create a table. %s \n", sqlite3_errmsg(db));
        return;
    }else {
        fprintf(stdout, "Created the table successfully. \n");
    }
    sqlite3_reset(stmt);
}

void Database::insertValues() {
    sql = "INSERT INTO books (NAME, ID, AUTHOR) VALUES (:name, :id, :author)";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    int idx1, idx2, idx3;
    idx1 = sqlite3_bind_parameter_index(stmt, ":name");
    idx2 = sqlite3_bind_parameter_index(stmt, ":id");
    idx3 = sqlite3_bind_parameter_index(stmt, ":author");

    const char* bookName{"Half-girlfriend"};
    int bookId{69};
    const char* bookAuthor{"Kesavan"};

    Book purchasedBook{bookName, bookId, bookAuthor};

    sqlite3_bind_text(stmt, idx1, bookName, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, idx2, bookId);
    sqlite3_bind_text(stmt, idx3, bookAuthor, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    purchasedBooks.push_back(purchasedBook);

    if(rc != SQLITE_DONE) {
        fprintf(stderr, "Can't insert the values into the fields. %s \n", errorMessage);
        sqlite3_free(errorMessage);
    }

    sqlite3_reset(stmt);

    bookName = "Interpreter in Go";
    bookId = 420;
    bookAuthor = "Kesavan";

    purchasedBook = {bookName, bookId, bookAuthor};
    purchasedBooks.push_back(purchasedBook);

    sqlite3_bind_text(stmt, idx1, bookName, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, idx2, bookId);
    sqlite3_bind_text(stmt, idx3, bookAuthor, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_DONE) {
        fprintf(stderr, "Can't insert the values into the fields. %s \n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_reset(stmt);
}

void Database::makeQuery() {

    openDb();

    sql = "SELECT * FROM books";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Can't prepare the statement when making the query to display the results. %s \n", sqlite3_errmsg(db));
    }else {
        fprintf(stdout, "Queried successfully and the results are: \n");
    }

    const char* bookName{};
    const char* bookAuthor{};
    int bookId{};

    rc = sqlite3_step(stmt);

    while(rc == SQLITE_ROW) {
        bookName = (const char*)sqlite3_column_text(stmt, 0);
        bookId = sqlite3_column_int(stmt, 1);
        bookAuthor = (const char*)sqlite3_column_text(stmt, 2);

        fprintf(stdout, "%s | %d | %s \n", bookName, bookId, bookAuthor);
        rc = sqlite3_step(stmt);
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
}

void Database::getBook() {

    std::cout << "Enter the name of the book you want to search for: ";
    std::string bookName;
    std::getline(std::cin, bookName);

    const char* sql = "SELECT * FROM books WHERE NAME = :bookName";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "can't prepare the statement for getting a book. %s \n", sqlite3_errmsg(db));
        return;
    }else {
        fprintf(stdout, "Let's go get a book! \n");
    }

    const char* bookParam = bookName.c_str();
    int idx = sqlite3_bind_parameter_index(stmt, ":bookName");
    sqlite3_bind_text(stmt, idx, bookParam, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    int index = 0;

    while(rc == SQLITE_ROW) {
        const char* book = (const char*) sqlite3_column_text(stmt, 0);
        int id = sqlite3_column_int(stmt, 1);
        const char* author = (const char*) sqlite3_column_text(stmt, 2);

        Book deletedBook{book, id, author};
        delBooks.push_back(deletedBook);
        //++structCount;

        fprintf(stdout, "Deleted book: %s\n", delBooks[index].bookName);
        ++index;

        rc = sqlite3_step(stmt);
    }

    sqlite3_reset(stmt);

    sql = "DELETE FROM books WHERE NAME = :bookName";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error in preparing to delete the records. %s\n", sqlite3_errmsg(db));
        return;
    }

    idx = sqlite3_bind_parameter_index(stmt, ":bookName");
    sqlite3_bind_text(stmt, idx, bookParam, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if(rc == SQLITE_DONE) {
        fprintf(stdout, "Successfully deleted the row. \n");
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
}

void Database::returnBook() {
    std::cout << "Enter the book you want to return: ";
    std::string bookName{};
    std::getline(std::cin, bookName);

    int index{};
    for(int i{0}; i < delBooks.size(); ++i) {
        if(bookName == delBooks[i].bookName ) {
            fprintf(stdout, "Hell yeah. \n");
            index = i;
            break;
        }else {
            continue;
        }
    }

    const char* insertBook = delBooks[index].bookName;
    int insertId = delBooks[index].bookId;
    const char* insertAuthor = delBooks[index].bookAuthor;

    sql = "INSERT INTO books VALUES(:book, :id, :author)";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Preparation error while returning the book. %s\n", sqlite3_errmsg(db));
        return;
    }

    int idx1, idx2, idx3;
    idx1 = sqlite3_bind_parameter_index(stmt, ":book");
    idx2 = sqlite3_bind_parameter_index(stmt, ":id");
    idx3 = sqlite3_bind_parameter_index(stmt, ":author");

    sqlite3_bind_text(stmt, idx1, insertBook, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, idx2, insertId);
    sqlite3_bind_text(stmt, idx3, insertAuthor, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_DONE) {
        fprintf(stderr, "Can't return the book. %s\n", sqlite3_errmsg(db));
        return;
    }else {
        fprintf(stdout, "Returned the book successfully. \n");
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sqlite3_close(db);
}

void Database::queryBook() {
    std::cout << "Enter the keyword to search for the books: \n";
    std::string query{};
    std::getline(std::cin, query);

    std::vector<Book>::iterator it{};
    it = purchasedBooks.begin();

    int index{1};

    while(it != purchasedBooks.begin() + index && it != purchasedBooks.end()) {
        auto found{std::find_if(it, purchasedBooks.begin() + index, [=](Book& book) {
                std::string name{book.bookName};
                return(name.find(query) != std::string::npos);
        })};

        if(found != purchasedBooks.end()) {
            std::cout << found->bookName << '\n';
            it = purchasedBooks.begin() + index;
            break;
        }else {
            it = purchasedBooks.begin() + index;
        }
        ++index;
    }
}
