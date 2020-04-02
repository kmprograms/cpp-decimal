#include <iostream>
#include "decimal.h"

using namespace dec;

int main() {

    // Typ decimal w C++
    // https://github.com/vpiotr/decimal_for_cpp

    // decimal z dwoma miejscami po przecinku
    decimal<2> d1(32.4575);
    std::cout << "d1 = " << d1 << std::endl;

    decimal<2> d2(32);
    std::cout << "d2 = " << d2 << std::endl;

    decimal<2> d3("32.388");
    std::cout << "d3 = " << d3 << std::endl;

    decimal<2> d4("32.384");
    std::cout << "d4 = " << d4 << std::endl;

    d4 += d1;
    std::cout << "d4 = " << d4 << std::endl;

    d4 -= d1;
    std::cout << "d4 = " << d4 << std::endl;

    d4 *= d1;
    std::cout << "d4 = " << d4 << std::endl;

    d4 /= d1;
    std::cout << "d4 = " << d4 << std::endl;

    // stosowanie int po prawej stronie dla mnozenia oraz dzielenia dziala automatycznie
    d4 *= 10;
    std::cout << "d4 = " << d4 << std::endl;

    d4 /= 10;
    std::cout << "d4 = " << d4 << std::endl;

    auto d5 = d1 + d2 * d3;
    std::cout << "d5 = " << d5 << std::endl;

    // kiedy chcesz zastosowac inny typ niz decimal po prawej stronie musisz rzutowac
    std::string dec_value1 = "12.22";
    int dec_value2 = 12;
    double dec_value3 = 12.22;

    auto d6 = decimal_cast<3>(dec_value1);
    std::cout << "d6 = " << d6 << std::endl;

    auto d7 = decimal_cast<3>(dec_value2);
    std::cout << "d7 = " << d7 << std::endl;

    auto d8 = decimal_cast<3>(dec_value3);
    std::cout << "d8 = " << d8 << std::endl;

    // przejscie z decimal o jednej precyzji na decimal o innej precyzji
    auto d9 = decimal_cast<2>(decimal_cast<5>("32.43525435"));
    std::cout << "d9 = " << d9 << std::endl;

    // okreslanie sposobow zaokraglania
    // https://github.com/vpiotr/decimal_for_cpp#supported-rounding-modes
    decimal <2, half_down_round_policy> d10; // domyslna wartosc 0.00
    d10 += decimal<4>("23.4333");
    // d10 += decimal<4>("23.4353");
    std::cout << "d10 = " << d10 << std::endl;

    return 0;
}
