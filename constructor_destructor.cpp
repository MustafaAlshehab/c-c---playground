#include <iostream>
using namespace std;

class mustafa {
public:
    mustafa(){
        cout << "I am a constructor" << endl;
    }
    ~mustafa(){
        cout << "I am a de-constructor" << endl;
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    mustafa a;

    return 0;
}