//
// Created by SAM on 17.04.2026.
//

#include "ISBN.h"
#include <iostream>
#include <string>

bool ISBN::check_isbn(std::string isbn) {
}

bool ISBN::check_string(std::string str) {
}

bool ISBN::check_number(int num) {
}

ISBN::ISBN(){
    this->author =  "J. K. Rowlingová";
    this->book_name = "Harry Potter a tajemná komnata";
    this->isbn = "80-00-00898-X";
    this->region = 80;
    this->publisher = 00;
    this->prefix = 0;
}

ISBN::ISBN(ISBN &object): author(object.get_author()){
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
    return this->prefix;
}

int ISBN::get_region() {
    return this->region;
}

int ISBN::get_publisher() {
    return this->publisher;
}

void ISBN::get_clean_isbn() {
    std::string temp = this->isbn;
    std::size_t position;
    do {
        position = isbn.find('-');

        // different member versions of find in the same order as above:
        if (position !=std::string::npos) {
            temp.erase(position, 1);
        }

    }while (position !=std::string::npos);
    std::cout << "Ciste ISBN: " << temp <<std::endl;
}

int ISBN::get_isbn_length() {
}

std::string ISBN::get_author() {
    return this->author;
}

std::ostream & operator<<(std::ostream &os, const ISBN &isbn) {
    os << "ISBN     " << isbn.isbn << std::endl
           << "Autor:   " << isbn.author << std::endl
           << "Nazev:   " << isbn.book_name << std::endl;
    return os;
}
