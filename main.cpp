#include <iostream>
#include <limits>
#include "ISBN.h"

int main() {
    char again = 'y';

    do {
        ISBN object1;

        // Objekt k1 - vychozi konstruktor
        std::cout << "Objekt k1 vytvoreny vychozim konstruktorem\n";
        std::cout << "------------------------------------------\n";
        std::cout << "ISBN  " << object1.get_isbn()
                  << "  Prefix: " << object1.get_prefix()
                  << "  Region: " << object1.get_region()
                  << "  Vydavatel: " << object1.get_publisher()
                  << "  Vydani: " << object1.get_issue() << "\n";
        std::cout << "Autor: " << object1.get_author() << "\n";
        std::cout << "Nazev: " << object1.get_book_name() << "\n\n";

        ISBN object2("80-00-00951-X", "Harry Potter a vezen z Azkabanu", "J. K. Rowlingova");

        // Objekt k2 - konstruktor s parametry
        std::cout << "Objekt k2 vytvoreny konstruktorem s parametry\n";
        std::cout << "------------------------------------------\n";
        std::cout << "ISBN  " << object2.get_isbn()
                  << "  Prefix: " << object2.get_prefix()
                  << "  Region: " << object2.get_region()
                  << "  Vydavatel: " << object2.get_publisher()
                  << "  Vydani: " << object2.get_issue() << "\n";
        std::cout << "Autor: " << object2.get_author() << "\n";
        std::cout << "Nazev: " << object2.get_book_name() << "\n\n";

        ISBN object3(object1);

        // Objekt k3 - kopirovaci konstruktor
        std::cout << "Objekt k3 vytvoreny kopirovacim konstruktorem\n";
        std::cout << "------------------------------------------\n";
        std::cout << "ISBN  " << object3.get_isbn()
                  << "  Prefix: " << object3.get_prefix()
                  << "  Region: " << object3.get_region()
                  << "  Vydavatel: " << object3.get_publisher()
                  << "  Vydani: " << object3.get_issue() << "\n";
        std::cout << "Autor: " << object3.get_author() << "\n";
        std::cout << "Nazev: " << object3.get_book_name() << "\n\n";

        // Zadani udaju o knize
        std::cout << "Zadani udaju o knize\n";
        std::cout << "--------------------\n";

        std::string isbn, author, name;

        // opakování ISBN dokud není validní
        do {
            std::cout << "ISBN              : ";
            std::cin >> isbn;

            object1.set_isbn(isbn);

            if (object1.get_isbn().empty()) {
                std::cout << "Zadali jste neplatne ISBN, zkuste to znovu.\n";
            }
        } while (object1.get_isbn().empty());

        // vyčistit zbytek řádku po >> isbn
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Autor
        std::cout << "Autor (3 az 100) znaku: ";
        std::getline(std::cin, author);
        object1.set_author(author);

        // Název
        std::cout << "Nazev (3 az 100) znaku: ";
        std::getline(std::cin, name);
        object1.set_name(name);

        std::cout << "\n";

        // Objekt k1 po zmene
        std::cout << "Objekt k1 po zmene\n";
        std::cout << "------------------------------------------\n";
        std::cout << "ISBN  " << object1.get_isbn()
                  << "  Prefix: " << object1.get_prefix()
                  << "  Region: " << object1.get_region()
                  << "  Vydavatel: " << object1.get_publisher()
                  << "  Vydani: " << object1.get_issue() << "\n";
        std::cout << "Autor: " << object1.get_author() << "\n";
        std::cout << "Nazev: " << object1.get_book_name() << "\n\n";

        // opakování celého programu
        std::cout << "Chcete spustit program znovu? (y/n): ";
        std::cin >> again;

        // vyčistit zbytek řádku po >> again (pro jistotu)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n";

    } while (again == 'y' || again == 'Y');

    return 0;
}