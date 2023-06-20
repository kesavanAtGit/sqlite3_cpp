#include <iostream>
#include <string>
#include <cassert>
#include "Database/database.h"

int main() {

    Database db{};
    db.openDb();
    db.createTbl();
    db.insertValues();

    std::cout << "What do you want to do? \n"
                << "Press g to get a book. \n"
                << "Press r to return a book. \n"
                << "Press m to make query. \n"
                << "Press q to query for a book using a keyword. \n";

    char ch{};
    std::cin >> ch;

    while(true) {
        switch(ch) {
            case 'g':
                db.getBook();
            case 'r':
                db.returnBook();
            case 'm':
                db.makeQuery();
            case 'q':
                db.queryBook();

            default:
                std::cerr << "Give a valid input. ";
                break;
        }
    }
    return 0;
}
