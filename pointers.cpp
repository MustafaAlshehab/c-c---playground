#include <iostream>

using namespace std;

int main () {
    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;

    cout << "Value of X is: " << x << endl;
    cout << "Address of X is: " << &x << endl;
    cout << "Address of p1 is: " << &p1 << endl;
    cout << "Address of p2 is: " << &p2 << endl;

    cout << "The address of where p1 is pointing to: " << p1 << endl;
    cout << "The value of where p1 is pointing to: " << *p1 << endl;

    cout << "The address of where p2 is pointing to: " << p2 << endl;
    cout << "The address of where the pointer pointed to by p2 is: " << *p2 << endl;
    cout << "The value of where the pointer pointed to by p2 is: " << **p2 << endl;

    return 0;
}