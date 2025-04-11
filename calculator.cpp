#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > std::numeric_limits<int>::max() - b)) {
        throw std::overflow_error("addition overflow");
    }
    if ((b < 0) && (a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("addition underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0) && (a > std::numeric_limits<int>::max() + b)) {
        throw std::overflow_error("subtraction overflow");
    }
    if ((b > 0) && (a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("subtraction underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<int>::max() / b) {
                throw std::overflow_error("multiplication overflow");
            }
        } else {
            if (b < std::numeric_limits<int>::min() / a) {
                throw std::overflow_error("multiplication underflow");
            }
        }
    } else {
        if (b > 0) {
            if (a < std::numeric_limits<int>::min() / b) {
                throw std::overflow_error("multiplication underflow");
            }
        } else {
            if ((a != 0) && (b < std::numeric_limits<int>::max() / a)) {
                throw std::overflow_error("multiplication overflow");
            }
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("division by zero");
    }
    if ((a == std::numeric_limits<int>::min()) && (b == -1)) {
        throw std::overflow_error("division overflow");
    }
    return a / b;
}
