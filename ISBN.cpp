//
// Created by SAM on 17.04.2026.
//

#include "ISBN.h"
#include <iostream>
#include <string>
#include <cctype>

std::string ISBN::check_isbn(std::string isbn) {
    int digit = 0;
    int control_sum = 0;
    int control_digit = 1;
    std::string temp = get_clean_isbn(isbn);
    int x = 0;

    // kontrola isbn 10
    if (!prefix_present(isbn)) {

        // kontrola délky isbn
        if (get_isbn_length(isbn) > 10) {
            std::cout << "Vetsi delka, nez ma normalni isbn 10. Neplatne ISBN!" << std::endl;
            return "";
        }

        if (temp.length() != 10) {
            std::cout << "Spatna delka ISBN-10. Neplatne ISBN!" << std::endl;
            return "";
        }

        // kontrola intervalu skupin
        std::size_t position = 0;
        position = isbn.find('-');
        if (position > 4) {
            std::cout << "Skupina je mimo interval 1 - 99999!" << std::endl;
            return "";
        }

        for (int j = 0; j < 10; ++j) {
            int i = 10 - j; // váha

            char c = temp.at(j);

            if (std::isdigit((unsigned char)c)) {
                digit = c - '0';
                control_sum += digit * i;
            } else if (j == 9 && c == 'X') {
                control_sum += 10 * i; // X jako 10, váha i
            } else {
                std::cout << "Neprosla pocetni kontrola. Neplatne ISBN!" << std::endl;
                return "";
            }
        }

        // kontrola součtu isbn 10
        if (control_sum % 11 == 0) {
            return isbn;
        } else {
            std::cout << "Neprosla pocetni kontrola. Neplatne ISBN!" << std::endl;
            return "";
        }
    }

    // ISBN-13 část
    if (temp.length() < 3) {
        std::cout << "Neplatne ISBN!" << std::endl;
        return "";
    }

    int prefix_digits = std::stoi(temp.substr(0, 3));

    // kontrola správného prefixu
    if (prefix_digits == 978 || prefix_digits == 979) {

        if (temp.length() != 13) {
            std::cout << "Spatna delka ISBN-13. Neplatne ISBN!" << std::endl;
            return "";
        }

        // kontrola intervalu skupin
        std::size_t position = 0;
        position = isbn.find('-', 3);

        if (position > 8) {
            std::cout << "Skupina je mimo interval 1 - 99999!" << std::endl;
            return "";
        }

        while (x < (int)temp.length()) {

            char c = temp.at(x);
            if (!std::isdigit((unsigned char)c)) {
                std::cout << "Neprosla pocetni kontrola. Neplatne ISBN!" << std::endl;
                return "";
            }

            digit = c - '0';

            if (control_digit == 1) {
                control_sum += 1 * digit;
                control_digit = 3;
            } else {

                control_sum += 3 * digit;
                control_digit = 1;
            }

            x++;
        }

        if (control_sum % 10 == 0) {
            return isbn;
        }
        std::cout << "Neprosla pocetni kontrola. Neplatne ISBN!" << std::endl;
        return "";
    }

    std::cout << "Neplatne ISBN!" << std::endl;
    return "";
}

std::string ISBN::check_string(std::string str, bool contains_numbers, const std::string error_message) {
    if (contains_numbers) {
        return str;
    }
    for (int i = 0; i < (int)str.length(); i++) {
        if (isdigit((unsigned char)str[i])) {
            std::cout << error_message << std::endl;
            std::cout << "Byl nastavena prazdna hodnota" << std::endl;
            return "";
        }
    }
    return str;
}

/*
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
*/

ISBN::ISBN() {
    this->author = "J. K. Rowlingova";
    this->book_name = "Harry Potter a ohnivy pohar";
    this->isbn = "80-00-00994-3";
    read_isbn_parts(this->isbn);
}

ISBN::ISBN(ISBN &object)
        : author(object.get_author()),
          book_name(object.get_book_name()),
          isbn(object.get_isbn()),
          prefix(object.get_prefix()),
          region(object.get_region()),
          issue(object.get_issue()) {
}

ISBN::ISBN(std::string isbn, std::string name, std::string author) {
    this->isbn = isbn;
    read_isbn_parts(this->isbn);

    this->author = check_string(author, false, "Nazev autora nesmi obsahovat pismena");
    this->book_name = check_string(name, true, "");
}

ISBN::~ISBN() {
}

void ISBN::set_isbn(std::string isbn) {
    this->isbn = check_isbn(isbn);
    if (!this->isbn.empty()) {
        read_isbn_parts(this->isbn);
    } else {
        prefix.clear();
        region.clear();
        publisher.clear();
        issue.clear();
    }
}

void ISBN::set_author(std::string author) {
    this->author = check_string(author, false, "Nazev autora nesmi obsahovat pismena");
}

void ISBN::set_name(std::string name) {
    this->book_name = check_string(name, true, "");
}

void ISBN::set_book(std::string isbn, std::string name, std::string author) {
}

std::string ISBN::get_prefix() {
    return this->prefix;
}

std::string ISBN::get_region() {
    return this->region;
}

std::string ISBN::get_publisher() {
    return this->publisher;
}

std::string ISBN::get_clean_isbn(std::string isbn) {
    std::string temp = isbn;
    std::size_t position = 0;
    do {
        position = temp.find('-');

        if (position != std::string::npos) {
            temp.erase(position, 1);
        }

    } while (position != std::string::npos);
    return temp;
}

int ISBN::get_isbn_length(std::string isbn) {
    std::string temp = get_clean_isbn(isbn);
    return (int)temp.length();
}

std::string ISBN::get_author() {
    return this->author;
}

std::ostream &operator<<(std::ostream &os, const ISBN &isbn) {
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

void ISBN::read_isbn_parts(std::string isbn) {
    std::size_t position = 0;

    if (prefix_present(isbn)) {
        position = isbn.find('-');
        this->prefix = isbn.substr(0, position);
        isbn.erase(0, position + 1); // MINIMAL FIX: +1
    } else {
        this->prefix = "";
    }

    position = isbn.find('-');
    if (position == std::string::npos) return;
    this->region = isbn.substr(0, position);
    isbn.erase(0, position + 1); // MINIMAL FIX: +1

    position = isbn.find('-');
    if (position == std::string::npos) return;
    this->publisher = isbn.substr(0, position);
    isbn.erase(0, position + 1);

    position = isbn.find('-');
    if (position == std::string::npos) return;
    this->issue = isbn.substr(0, position);
    isbn.erase(0, position + 1);
}

std::string ISBN::get_issue() {
    return this->issue;
}

bool ISBN::prefix_present(std::string isbn) {
    int commas = 0;
    std::size_t position = 0;

    do {
        position = isbn.find('-');
        if (position == std::string::npos) break;


        isbn.erase(0, position + 1);
        commas++;
    } while (isbn.find('-') != std::string::npos);

    if (commas == 4) {
        return true;
    }
    return false;
}