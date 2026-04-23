#include <iostream>
#include "ISBN.h"


int main() {
    ISBN object1;

    // Objekt k1 - vychozi konstruktor
    std::cout << "Objekt k1 vytvoreny vychozim konstruktorem" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "ISBN  "<< object1.get_isbn() <<"  Prefix: "<<  object1.get_prefix() << "  Region: "
    << object1.get_region() << "  Vydavatel: "<< object1.get_publisher() <<"  Vydani: "
    << object1.get_issue() << std::endl;

    std::cout << "Autor: "<< object1.get_author() << std::endl;
    std::cout << "Nazev: "<< object1.get_book_name() << std::endl;

    std::cout << std::endl;

    ISBN object2("80-00-00951-X", "Harry Potter a vezen z Azkabanu","J. K. Rowlingova");
    // Objekt k2 - konstruktor s parametry
    std::cout << "Objekt k2 vytvoreny konstruktorem s parametry" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "ISBN  "<< object2.get_isbn() <<"  Prefix: "<<  object2.get_prefix() << "  Region: "
    << object2.get_region() << "  Vydavatel: "<< object2.get_publisher() <<"  Vydani: "
    << object2.get_issue() << std::endl;

    std::cout << "Autor: "<< object2.get_author() << std::endl;
    std::cout << "Nazev: "<< object2.get_book_name() << std::endl;

    std::cout << std::endl;

    ISBN object3(object1);
    // Objekt k3 - kopirovaci konstruktor
    std::cout << "Objekt k3 vytvoreny kopirovacim konstruktorem" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "ISBN  "<< object3.get_isbn() <<"  Prefix: "<<  object3.get_prefix() << "  Region: "
              << object3.get_region() << "  Vydavatel: "<< object3.get_publisher() <<"  Vydani: "
              << object3.get_issue() << std::endl;

    std::cout << "Autor: "<< object3.get_author() << std::endl;
    std::cout << "Nazev: "<< object3.get_book_name() << std::endl;

    std::cout << std::endl;

    // Zadani udaju o knize
    std::cout << "Zadani udaju o knize" << std::endl;
    std::cout << "--------------------" << std::endl;

    std::string isbn, author, name;

    std::cout << "ISBN              : ";
    std::cin >> isbn;
    object1.set_isbn(isbn);

    std::cout << "Autor (3 az 100) znaku: ";
    std::cin.ignore();
    std::getline(std::cin, author);
    object1.set_author(author);

    std::cout << "Nazev (3 az 100) znaku: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    object1.set_name(name);


    std::cout << std::endl;

    // Objekt k1 po zmene
    std::cout << "Objekt k1 po zmene" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ISBN  "<< object1.get_isbn() <<"  Prefix: "<<  object1.get_prefix() << "  Region: "
              << object1.get_region() << "  Vydavatel: "<< object1.get_publisher() <<"  Vydani: "
              << object1.get_issue() << std::endl;

    std::cout << "Autor: "<< object1.get_author() << std::endl;
    std::cout << "Nazev: "<< object1.get_book_name() << std::endl;


    return 0;

}