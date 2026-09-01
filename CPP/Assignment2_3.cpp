#include <iostream>
using namespace std;

int main()
{
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    // -----------------------------------------
    // regPtr1: pointer to const int
    // -----------------------------------------

    const int* regPtr1 = &statusReg;

    cout << "Status Register : " << *regPtr1 << endl;

    // *regPtr1 = 10;
    // ERROR: Cannot modify the value through
    // a pointer-to-const.

    // regPtr1 = &dataReg;
    // This is actually allowed because the pointer
    // itself is NOT const.


    // -----------------------------------------
    // regPtr2: const pointer to int
    // -----------------------------------------

    int* const regPtr2 = &controlReg;

    *regPtr2 = 100;

    cout << "Control Register : " << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // ERROR: regPtr2 is a const pointer.
    // It cannot point to another address.


    // -----------------------------------------
    // regPtr3: const pointer to const int
    // -----------------------------------------

    const int* const regPtr3 = &statusReg;

    cout << "Register 3 : " << *regPtr3 << endl;

    // *regPtr3 = 50;
    // ERROR: Cannot modify the value.

    // regPtr3 = &dataReg;
    // ERROR: Cannot change the address.


    return 0;
}