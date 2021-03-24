#include <iostream>

using namespace std;

int main() {
    int numberOfDigits, digit, temp;
    int number = 0, numberReverse = 0;

    cout << "Enter number of digits\n";
    cin >> numberOfDigits;
    
    cout << "Enter each digit\n";
    for (int i = 0; i < numberOfDigits; i++) {
        cin >> digit;
        number = (number * 10) + digit;
    }

    temp = number;

    while (temp) {
        numberReverse = (numberReverse * 10) + temp % 10;
        temp /= 10;
    }

    cout << "Number is: " << number << "\n";
    cout << "Reverse number is: " << numberReverse << "\n";

    return 0;
}