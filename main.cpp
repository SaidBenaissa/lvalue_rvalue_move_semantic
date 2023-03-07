/*
 *  by using the rvalue references, we can use function overloading to
 *  determine whether function parameters are lvalues or rvalues by having
 *  one overloaded function taking an lvalue reference and another taking
 *  an rvalue reference. In other words, C++11 introduces a new non-const
 *  reference type called an rvalue reference, identified by T&&. This refers
 *  to temporaries that are permitted to be modified after they are
 *  initialized, which is the cornerstone of move semantics.
 *  */

/* rvalue summary:
 * 1. int &&a;: new (C++11) declaration rvalue reference.
 * 2. non-const lvalue reference binds to an object.
 * 3. rvalue reference binds to a temporary object which typically will not be used again.
 * */

#include <iostream>

using namespace std;

void printReference (int& value) // lvalue reference as parameter - C++98 and C++11
{
    cout << "lvalue: value = " << value << endl;
}

void printReference (int&& value) // rvalue reference as parameter - C++11
{
    cout << "rvalue: value = " << value << endl;
}

int getValue () // return rvalue
{
    int temp_ii = 99;
    return temp_ii;
}

int main()
{
    int ii = 11;
    printReference(ii); // lvalue ii is passed to printReference(int& value)
    printReference(getValue());  //  printReference(99); // rvalue is passed to printReference(int&& value)
    return 0;
}