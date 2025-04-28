#include "Callback.hpp"
#include <iostream>
#include <utility>

typedef std::pair<int, int> intpair;

void print(intpair p) {
    std::cout << p.first << " -> " << p.second << std::endl;
}

class C {
public:
    C() {}
    C(const C&) {
        std::cout << "copying C" << std::endl;
    }

    void print(intpair p) {
        std::cout << "C::print(): " << p.first << " -> " << p.second << std::endl;
    }
    void operator()(intpair p) {
        std::cout << "C::(): " << p.first << " -> " << p.second << std::endl;
    }
};

void hanoi(int i, int a, int b, int c, CallbackBase<intpair>& callback) {
    if (i > 0) {
        hanoi(i - 1, a, c, b, callback);
        // moving a to c
        callback.call(intpair(a, c));
        hanoi(i - 1, b, a, c, callback);
    }
}

int main() {
    // function callback
    FunctionCallback<intpair> cb1(print);
    hanoi(3, 1, 2, 3, cb1);

    // functor callback
    C c;
    FunctorCallback<intpair, C> cb2(c);
    hanoi(3, 1, 2, 3, cb2);

    // method callback
    MethodCallback<intpair, C> cb3(&C::print, &c);
    hanoi(3, 1, 2, 3, cb3);
}
