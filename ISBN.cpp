//
// Created by SAM on 17.04.2026.
//

#include "ISBN.h"

bool ISBN::check_isbn(std::string isbn) {
}

bool ISBN::check_string(std::string str) {
}

bool ISBN::check_number(int num) {
}

ISBN::ISBN() {
}

ISBN::ISBN(ISBN &code) {
}

ISBN::ISBN(std::string isbn, std::string name, std::string author) {
}

ISBN::~ISBN() {
}

void ISBN::set_isbn(std::string isbn) {
}

void ISBN::set_author(std::string author) {
}

void ISBN::set_name(std::string name) {
}

void ISBN::set_book(std::string isbn, std::string name, std::string author) {
}

int ISBN::get_prefix() {
    return prefix;
}

int ISBN::get_region() {
    return region;
}

int ISBN::get_publisher() {
    return publisher;
}

std::string ISBN::get_clean_isbn() {

    std::string character ("-");

    // different member versions of find in the same order as above:
    std::size_t found = str.find(str2);
    if (found!=std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';

}

int ISBN::get_isbn_length() {
}

std::ostream & operator<<(std::ostream &os, const ISBN &isbn) {
    os << "ISBN     " << isbn.isbn << std::endl
           << "Autor:   " << isbn.author << std::endl
           << "Nazev:   " << isbn.book_name << std::endl;
    return os;
}
