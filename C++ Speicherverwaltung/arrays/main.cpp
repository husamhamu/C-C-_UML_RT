#include <cstddef>
#include <iostream>

// Task 2.2c
void printArray(const int* arr, size_t size) {
    std::cout << "printArray" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

// Task 2.2d
void printArrayPointer(const int* arr, size_t size) {
    std::cout << "printArrayPointer" << std::endl;
    for (const int* p = arr; p != arr + size; ++p) {
        std::cout << *p << std::endl;
    }
}

// Task 2.2j
void mmulC(int m[4][4], int c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] *= c;
        }
    }
}

void mmulC2(int* m, int c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *m *= c;
            m++;
        }
    }
}

/**
 * @brief Task d: Iterator-style implementation for printing an array
 * @param begin the point to the first array element to print
 * @param end the pointer to the array element behind the last array element to print
 */
void printArray(const int* begin, const int* end) {
    std::cout << "printArray" << std::endl;
    for (const int* p = begin; p != end; ++p) {
        std::cout << *p << std::endl;
    }
}

/**
 * @brief Task f: Reads a user-specified amount of numbers from standard input
 * @param size the output variable that stores the user-defined amount of numbers
 * @return a point to an array on the heap of the length stored in the output parameter size
 */
int* readNumbers(size_t* size) {
    size_t n;
    std::cout << "Geben Sie die Groesse ein: ";
    std::cin >> n;

    std::cout << "Geben Sie " << n << " Zahlen ein: " << std::endl;
    int* arr = new int[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    *size = n;
    return arr;
}

/**
 * @brief Task g: Reads the given amount of numbers from the standard input
 * @param n the amount of numbers to read
 * @return a point to an array on the heap of length n
 */
int* readNumbers(const size_t n) {
    std::cout << "Geben Sie " << n << " Zahlen ein: " << std::endl;

    int* arr = new int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    return arr;
}

/**
 * @brief Task p: Flips the given string
 * @param s the string to flip
 */
void drehen(std::string& s) {
    std::string temp = s;
    for (size_t i = 0; i < temp.length(); i++) {
        s[i] = temp[temp.length() - i - 1];
    }
}

/**
 * @brief Task q: Decodes the given string and prints it
 * @param b the string to decode
 */
void decoder(std::string b) {
    for (size_t i = 0; i < b.length(); i += 2) {
        char c = b[b.length() - 2 - i] - (b[b.length() - 1 - i] - 48);
        std::cout << c;
    }
}

int main(int argc, char** argv) {
    // Task 2.2a
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr[i] << std::endl;
    }

    // Task 2.2b
    int arr2[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int* pArr = arr2;

    *pArr = *pArr + 1;                   // 2, 2, 3, 4, 5, 6, 7
    *(pArr + 3) = arr2[4] + *pArr;       // 2, 2, 3, 7, 5, 6, 7
    *(pArr + 1) = *pArr + 2;             // 2, 4, 3, 7, 5, 6, 7
    arr2[2] = *(pArr + 5);               // 2, 4, 6, 7, 5, 6, 7
    *(pArr + 6) = *(pArr + 4) * *(pArr); // 2, 4, 6, 7, 5, 6, 10
    *(pArr++) = *pArr + *pArr++;         // 2, 4, 6, 7, 5, 6, 10

    printArray(arr2, 7);
    // Task 2.2c
    printArray(arr, 10);

    // Task 2.2d
    printArrayPointer(arr, 10);

    // Task 2.2e
    printArray(arr, arr + 10);

    // Task 2.2f
    printArray(arr + 3, arr + 7); // elements 4, 5, 6, 7

    // Task 2.2g
    {                                   // This brace defines a scope that allows to use the variable 'size' multiple times within 'main'.
        size_t size;                    // variable to store array size
        int* pArr = readNumbers(&size); // read some numbers

        printArray(pArr, pArr + size); // print the numbers

        delete[] pArr; // delete array
        pArr = NULL;   // avoid dangling pointer
    }

    // Task 2.2h
    {
        std::cout << "argv[0]: " << argv[0] << std::endl;
        if (argc >= 2) {
            size_t size = std::stoi(argv[1]); // convert C string to integer
            int* pArr = readNumbers(size);    // read size numbers

            printArray(pArr, pArr + size); // print the numbers

            delete[] pArr; // delete array
            pArr = NULL;   // avoid dangling pointer
        }
        else {
            // std::cerr is the standard error log
            std::cerr << "Not enough command-line parameters given. Expecting at least one parameter." << std::endl;
        }
    }

    // Task 2.2i
    int M[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    int* ptrE = *M;
    std::cout << *(ptrE + 1);
    std::cout << *(ptrE + 4);
    std::cout << *(ptrE + 15);
    //auf M[n][m] kann man durch ptrE + 4*n + m zugreifen.

    // Task 2.2j
    int I[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                I[i][j] = 1;
            }
            else {
                I[i][j] = 0;
            }
        }
    }

    // Task 2.2k
    std::string hallo1("Hallo Welt");
    std::cout << hallo1.length() << std::endl;

    mmulC(I, 4);
    int* firstElement = *I;
    mmulC2(firstElement, 2);
    printArrayPointer(firstElement, 16);
}
