//
// Created by SAM on 17.04.2026.
//
#include <iostream>

#ifndef ISBN_ISBN_H
#define ISBN_ISBN_H


class ISBN {

    const int max_string = 200;
    const int min_string = 1;
    const std::string author = "J. K. Rowlingová";
    const std::string book_name = "Harry Potter a tajemná komnata";
    const std::string isbn = "80-00-00898-X";
    const std::string prefix;
    const int region = 80;
    const int publisher = 00;

    bool check_isbn(std::string isbn);
    bool check_string(std::string str);
    bool check_number(int num);

public:
    ISBN();
    ISBN(ISBN &code);
    ISBN(std::string isbn,std::string name, std::string author);
    ~ISBN();

    //set
    void set_isbn(std::string isbn);
    void set_author(std::string author);
    void set_name(std::string name);
    void set_book(std::string isbn,std::string name, std::string author);

    //get
    int get_prefix();
    int get_region();
    int get_publisher();
    std::string get_clean_isbn();
    int get_isbn_length();

    friend std::ostream& operator<<(std::ostream& os, const ISBN &isbn);
};


#endif //ISBN_ISBN_H