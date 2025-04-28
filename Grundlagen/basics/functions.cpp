#include "functions.hpp"
#include <iostream>
#include <limits> // necessary to clear cin state (if invalid because of bad input)

static void clearStandardInputErrorFlags();

namespace fun {

    void printSpaces(int n) {
        // Print necessary spaces to right-align the figure
        for (int i = 0; i < n; ++i) {
            std::cout << ' ';
        }

        // Alternative version:
        // You may encounter this programming style especially in embedded code.
        // As it is harder to read, it is not recommended.
        //
        // while (n-- > 0) {
        //     std::cout << ' ';
        // }
    }

    void printStars(int n) {
        //Print required number of stars
        for (int i = 0; i < n; ++i) {
            std::cout << '*';
        }
        //Print the new line
        std::cout << std::endl;
    }

    void printFigure(int width, Direction d) {
        //Print the upper part of the figure
        for (int i = width; i > 1; --i) {
            if (d == right) {
                printSpaces(width - i);
            }
            printStars(i);
        }
        //Print the lower part of the figure
        for (int i = 1; i <= width; ++i) {
            if (d == right) {
                printSpaces(width - i);
            }
            printStars(i);
        }
    }

    void task2_6_input() {
        std::cout << "Muster mit Sternen." << std::endl;
        int width;
        //Keep asking until a valid value has been entered
        do {
            std::cout << "Geben Sie die Breite ein (zwischen 1 und 75): ";
            clearStandardInputErrorFlags();
            std::cin >> width;
        } while (width < 1 || width > 75);

        //Keep asking until a valid value has been entered
        int input;
        do {
            std::cout << "Geben Sie die Richtung ein (" << Direction::left << "=linksbündig, " << Direction::right << "=rechtsbündig): ";
            std::cin >> input;
        } while (input < 0 || input > 1);

        Direction d;
        // Alternative 1: Cast if values match.
        d = (Direction)input;
        // Alternative 2: Explicit if-else
        if (input == 0) {
            d = left;
        }
        else {
            d = right;
        }

        //Print the figure with the user-defined settings
        printFigure(width, d);
    }

    char nextChar() {
        static char c = 'z';
        if (c >= 'z') {
            //Reset char to a
            c = 'a';
        }
        else {
            //Increment the char to the next one
            c++;
        }
        return c;
    }

    void printChar(int n) {
        while (n-- > 0) {
            std::cout << nextChar();
        }
        std::cout << std::endl;
    }

    void printCharFigure() {
        std::cout << "Muster mit Buchstaben." << std::endl;
        int width;
        do {
            std::cout << "Geben Sie die Breite ein (zwischen 1 und 75): ";
            clearStandardInputErrorFlags();
            std::cin >> width;
        } while (width < 1 || width > 75);

        for (int i = width; i > 1; --i) {
            printChar(i);
        }
        for (int i = 1; i <= width; ++i) {
            printChar(i);
        }
    }

} // namespace fun

/**
 * @brief Clears error flags and buffered invalid values of std::cin
 * 
 * Solution thanks to https://stackoverflow.com/questions/5864560#5864560
 */
void clearStandardInputErrorFlags() {
    if (std::cin.fail()) {                                                  // Check validity of cin state
        std::cin.clear();                                                   // Clear cin internal error state, that is set if input is no int or exceeds
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear current buffer of cin
    }
}