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
    std::string issue;
    std::string prefix;
    std::string region;
    std::string publisher;


    std::string check_isbn(std::string isbn);

    std::string check_string(std::string str, bool contains_numbers, std::string error_message);

    //int check_number(int num,int min, int max);
    void read_isbn_parts(std::string isbn);

    bool prefix_present(std::string isbn);

public:
    ISBN();

    ISBN(ISBN &object);

    ISBN(std::string isbn, std::string name, std::string author);

    ~ISBN();

    //set
    void set_isbn(std::string isbn);

    void set_author(std::string author);

    void set_name(std::string name);

    void set_book(std::string isbn, std::string name, std::string author);

    //get
    std::string get_prefix() const;

    std::string get_region() const;

    std::string get_publisher() const;

    std::string get_issue() const;

    std::string get_clean_isbn(std::string isbn) const;

    int get_isbn_length(std::string isbn) const;

    std::string get_author() const;

    std::string get_book_name() const;

    std::string get_isbn() const;

    friend std::ostream &operator<<(std::ostream &os, const ISBN &isbn);

};


#endif //ISBN_ISBN_H