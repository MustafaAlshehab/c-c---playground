#include <iostream>

using namespace std;

int output1() {
    string t = "623";
    //return value should be true as the decimal value of string 6 is 54
    return t[0] != 0;
}

void output2() {
    int x[4][3] = {{1,2,3}, {4,5,6,}, {7,8,9}, {10,11,12}};
    cout << x+3 << ' ' << *(x+3) << ' ' << *(x+2)+3 << endl;
}


int main() {
    cout << output1() << endl;
    output2();
    
    return 0;
}
