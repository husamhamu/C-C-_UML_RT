#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>    // for std::sin, std::asin
#include <iomanip>  // for advanced output formatting, e.g., std::setw, std::left
#include <iterator> // for std::back_inserter, std::back_insert_iterator

////////////////////////////////////////////////////////////////////////////////
// Exercise 17.2 map, filter, reduce
////////////////////////////////////////////////////////////////////////////////

template <typename InIt, typename OutIt>
OutIt map_funcpointer(InIt first, InIt last,
    OutIt out_first, double (*func)(double i)) {
    for (; first != last; ++out_first, ++first) {
        *out_first = func(*first);
    }

    // An alternative solution uses a while loop. This is not recommended though
    // as the expression *first++ is harder to read:
    //
    // while (first != last) {
    //     *out_first++ = func(*first++);
    //

    return out_first;
}

template <typename InIt, typename OutIt>
OutIt filter_funcpointer(InIt first, InIt last,
    OutIt out_first, bool (*pred)(int i)) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            *out_first = *first;
            ++out_first;
        }
    }
    return out_first;
}

template <typename InIt, typename T, typename U>
T reduce_funcpointer(InIt first, InIt last, T init, T (*func)(T i, U j)) {
    T result = init;
    for (; first != last; ++first) {
        result = func(result, *first);
    }
    return result;
}

// for map
double square(double i) { return i * i; }

// for filter
bool is_odd(int i) { return i % 2 == 1 ? true : false; }

// for reduce
double sum(double i, double j) { return i + j; }

template <class T>
std::string to_string(std::string str, const T j) {
    std::ostringstream stm;
    if (!str.empty()) {
        stm << str << ", ";
    }
    stm << j;
    return stm.str();
}

////////// Function for testing function pointers //////////
void functionpointer() {
    std::vector<double> numbers = { 1, 2, 3, 4, 5 };

    std::cout << "Function Pointer:" << std::endl;

    std::cout << "Init:\t[ "
              << reduce_funcpointer(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    map_funcpointer(numbers.begin(), numbers.end(), numbers.begin(), square);

    std::cout << "Map:\t[ "
              << reduce_funcpointer(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    std::vector<double> filteredNumbers;
    filter_funcpointer(numbers.begin(), numbers.end(), std::back_inserter(filteredNumbers), is_odd);

    std::cout << "Filter:\t[ "
              << reduce_funcpointer(filteredNumbers.begin(), filteredNumbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    std::cout << "Reduce:\t"
              << reduce_funcpointer(numbers.begin(), numbers.end(), 0.0, sum)
              << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Exercise 17.3 Functors
////////////////////////////////////////////////////////////////////////////////

// for map
class Square {
public:
    Square() {}
    double operator()(double i) {
        return i * i;
    }

    /*
    * used for 17.6
    */
    double squareroot(double i) {
        return std::sqrt(i);
    }
};

// for filter
class Odd {
public:
    Odd() {}
    bool operator()(int i) {
        return i % 2 == 1 ? true : false;
    }
};

// for reduce
class Sum {
public:
    Sum() {}
    int operator()(int i, int j) {
        return i + j;
    }
};

template <typename InIt, typename OutIt>
OutIt map_functor(InIt first, InIt last, OutIt out_first, Square s) {
    for (; first != last; ++out_first, ++first) {
        *out_first = s(*first);
    }
    return out_first;
}

template <typename InIt, typename OutIt>
OutIt filter_functor(InIt first, InIt last, OutIt out_first, Odd pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            *out_first = *first;
            ++out_first;
        }
    }
    return out_first;
}

template <typename InIt, typename T>
T reduce_functor(InIt first, InIt last, T init, Sum s) {
    for (; first != last; ++first) {
        init = s(init, *first);
    }
    return init;
}

void functors() {
    std::vector<double> numbers = { 1, 2, 3, 4, 5 };

    std::cout << "Functors:" << std::endl;

    std::cout << "Init:\t[ " << reduce_funcpointer(numbers.begin(), numbers.end(), std::string{}, to_string<double>) << " ]"
              << std::endl;

    map_functor(numbers.begin(), numbers.end(), numbers.begin(), Square());

    std::cout << "Map:\t[ " << reduce_funcpointer(numbers.begin(), numbers.end(), std::string{}, to_string<double>) << " ]"
              << std::endl;


    std::vector<double> filteredNumbers;
    filter_functor(numbers.begin(), numbers.end(), std::back_inserter(filteredNumbers), Odd());

    std::cout << "Filter:\t[ " << reduce_funcpointer(filteredNumbers.begin(), filteredNumbers.end(), std::string{}, to_string<double>) << " ]"
              << std::endl;

    std::cout << "Reduce:\t" << reduce_functor(numbers.begin(), numbers.end(), 0, Sum()) << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Exercise 17.4 Templates
////////////////////////////////////////////////////////////////////////////////

template <typename InIt, typename OutIt, typename FuncType>
OutIt map_template(InIt first, InIt last, OutIt out_first, FuncType func) {
    for (; first != last; ++out_first, ++first) {
        *out_first = func(*first);
    }
    return out_first;
}

template <typename InIt, typename OutIt, typename FuncType>
OutIt filter_template(InIt first, InIt last, OutIt out_first, FuncType pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            *out_first = *first;
            ++out_first;
        }
    }
    return out_first;
}

template <typename InIt, typename T, typename FuncType>
T reduce_template(InIt first, InIt last, T init, FuncType func) {
    for (; first != last; ++first) {
        init = func(init, *first);
    }
    return init;
}


////////////////////////////////////////////////////////////////////////////////
// Exercise 17.5 Methodpointers (optional)
////////////////////////////////////////////////////////////////////////////////

template <typename InIt, typename OutIt, typename ObjType>
OutIt map_method(InIt first, InIt last,
    OutIt out_first, ObjType* object, double (ObjType::*method)(double)) {
    for (; first != last; ++out_first, ++first) {
        *out_first = (object->*method)(*first);
    }
    return out_first;
}

class Sine {
public:
    double operator()(double i) {
        return std::sin(i);
    }

    double squareroot(double i) {
        return std::asin(i);
    }
};

void methodpointers() {
    std::vector<double> numbers = { .1, .2, .3, .4, .5 };

    std::cout << "Method pointers:" << std::endl;

    Square* square = new Square();
    Sine* sine = new Sine();

    std::cout << std::left << std::setw(18)
              << "Init:"
              << "\t[ "
              << reduce_template(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    map_method(numbers.begin(), numbers.end(), numbers.begin(), square, &Square::operator());

    std::cout << std::left << std::setw(18)
              << "Square::operator():"
              << "\t[ "
              << reduce_template(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    map_method(numbers.begin(), numbers.end(), numbers.begin(), square, &Square::squareroot);

    std::cout << std::left << std::setw(18)
              << "Square::squareroot:"
              << "\t[ "
              << reduce_template(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    map_method(numbers.begin(), numbers.end(), numbers.begin(), sine, &Sine::operator());

    std::cout << std::left << std::setw(18)
              << "Sine::operator():"
              << "\t[ "
              << reduce_template(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    map_method(numbers.begin(), numbers.end(), numbers.begin(), sine, &Sine::squareroot);

    std::cout << std::left << std::setw(18)
              << "Sine::squareroot:"
              << "\t[ "
              << reduce_template(numbers.begin(), numbers.end(), std::string{}, to_string<double>)
              << " ]"
              << std::endl;

    delete square;
    delete sine;
}

int main() {
    functionpointer();
    std::cout << std::string(40, '-') << std::endl;
    functors();
    std::cout << std::string(40, '-') << std::endl;
    methodpointers();
}
