#include "functions.hpp"
#include <iostream>
#include <limits>

void print_easy() {
    /**
     * @brief easy version of solution of 2.1
     * Prints size in bytes of int, unsigned int, double, unsigned short, bool
     * to the standard output, as well as their minimum and maximum value.
     *
     * @return void
     */

    int a;
    unsigned int b;
    double c;
    unsigned short d;
    bool e;

    std::cout << sizeof(a) << "\t"
              << std::numeric_limits<int>::min() << "\t"
              << std::numeric_limits<int>::max() << "\t"
              << std::endl;

    std::cout << sizeof(b) << "\t"
              << std::numeric_limits<unsigned int>::min() << "\t"
              << std::numeric_limits<unsigned int>::max() << "\t"
              << std::endl;

    std::cout << sizeof(c) << "\t"
              << std::numeric_limits<double>::min() << "\t"
              << std::numeric_limits<double>::max() << "\t"
              << std::endl;

    std::cout << sizeof(d) << "\t"
              << std::numeric_limits<unsigned short>::min() << "\t"
              << std::numeric_limits<unsigned short>::max() << "\t"
              << std::endl;

    std::cout << sizeof(e) << "\t"
              << std::numeric_limits<bool>::min() << "\t"
              << std::numeric_limits<bool>::max() << "\t"
              << std::endl;
}

template <typename T>
void print_info_advanced() {
    /**
     * @brief advanced version of solution of 2.1
     * helper function for advanced solution
     * will be explained in detail on day 4
     *
     * @return void
     */
    std::cout << sizeof(T) << "\t"
              << std::numeric_limits<T>::min() << "\t"
              << std::numeric_limits<T>::max() << "\t"
              << std::endl;
}

void print_advanced() {
    /**
     * advanced solution using the helper function print_info_advanced
     * prints the same information as print_easy to the standard output
     * 
     * @return void
     */
    print_info_advanced<int>();
    print_info_advanced<unsigned int>();
    print_info_advanced<double>();
    print_info_advanced<unsigned short>();
    print_info_advanced<bool>();
}


int main() {
    print_easy();
    fun::task2_6_input();
    fun::printCharFigure();

    //Aufgabe 1.2i
    struct Product {
        int gewicht;
        float preis;
    };

    Product banane;
    Product apfel;
    Product wassermelone;

    banane.gewicht = 200;
    apfel.gewicht = 150;
    wassermelone.gewicht = 1000;

    banane.preis = 1.5;
    apfel.preis = 0.75;
    wassermelone.preis = 4.0;

    std::cout << "Gewicht Banane: " << banane.gewicht << "g" << std::endl;
    std::cout << "Preis Banane: " << banane.preis << "E";
    std::cout << "Gewicht Apfel: " << apfel.gewicht << "g" << std::endl;
    std::cout << "Preis Apfel: " << apfel.preis << "E";
    std::cout << "Gewicht Wassermelone: " << wassermelone.gewicht << "g" << std::endl;
    std::cout << "Preis Wassermelone: " << wassermelone.preis << "E" << std::endl;
}
