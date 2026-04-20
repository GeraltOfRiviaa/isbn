//
// Created by SAM on 17.04.2026.
//

#include "ISBN.h"
#include <iostream>
#include <string>

std::string ISBN::check_isbn(std::string isbn, std::string error_message) {

}

std::string ISBN::check_string(std::string str, bool contains_numbers, std::string error_message) {
    if (contains_numbers){
        return str;
    }
    for (int i = 0; i < str.length(); i++){
        if(isdigit(str[i])){
            std::cout << error_message << std::endl;
            std::cout << "Byl nastavena prazdna hodnota" << std::endl;
            return "";
        }
    }
    return str;
}

int ISBN::check_number(int num,int min, int max) {
    if (!isdigit(num)){
        std::cout << "Cislo nesmi obsahovat pismena ci jine znaky" << std::endl;
        std::cout << "Byl nastavena prazdna hodnota" << std::endl;
        return 0;
    }
    else if (num < min || num > max){
        std::cout << "Cislo neni v intervalu od " << min << "do " << max << std::endl;
    }
    return num;
}

ISBN::ISBN(){
    this->author =  "J. K. Rowlingová";
    this->book_name = "Harry Potter a tajemná komnata";
    this->isbn = "80-00-00898-X";
    this->region = 80;
    this->publisher = 00;
    this->prefix = 0;
}

ISBN::ISBN(ISBN &object): author(object.get_author()), book_name(object.get_book_name()), isbn(get_isbn()){
}

ISBN::ISBN(std::string isbn, std::string name, std::string author) {
}

ISBN::~ISBN() {
}

void ISBN::set_isbn(std::string isbn) {
}

void ISBN::set_author(std::string author) {
    this->author = check_string(author, false, "Nazev autora nesmi obsahovat pismena");
}

void ISBN::set_name(std::string name) {
    this->book_name = check_string(name, true, "");
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

std::string ISBN::get_clean_isbn() {
    std::string temp = this->isbn;
    std::size_t position = 0;
    do {
        position = temp.find('-');

        if (position != std::string::npos) {
            temp.erase(position, 1);
        }

    }while (position !=std::string::npos);
    std::cout << "Ciste ISBN: " << temp <<std::endl;
    return temp;
}

int ISBN::get_isbn_length() {
   std::string temp = get_clean_isbn();
    return temp.length();
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

std::string ISBN::get_book_name() {
    return this->book_name;
}

std::string ISBN::get_isbn() {
    return this->isbn;
}
