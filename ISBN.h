//
// Created by SAM on 17.04.2026.
//
#include <iostream>

#ifndef ISBN_ISBN_H
#define ISBN_ISBN_H


class ISBN {

    int max_string = 200;
    int min_string = 1;
    std::string author;
    std::string book_name;
    std::string isbn;
    int prefix;
    int region;
    int publisher;

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
    void get_clean_isbn();
    int get_isbn_length();
    std::string get_author();

    friend std::ostream& operator<<(std::ostream& os, const ISBN &isbn);
};


#endif //ISBN_ISBN_H