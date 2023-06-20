#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>
#include <vector>

class Database {
private:

    typedef struct InventoryBook {
        const char* bookName{};
        int bookId{};
        const char* bookAuthor{};
    }Book;

    sqlite3* db{};
    sqlite3_stmt* stmt{};
    int rc{};
    char* errorMessage{0};
    const char* sql{};
    std::vector<Book> purchasedBooks{};
    std::vector<Book> delBooks{};

public:
    void openDb();
    void createTbl();
    void insertValues();
    void makeQuery();

    void getBook();
    void returnBook();
    void queryBook();
};

#endif
