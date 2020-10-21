/* This applies to square matices n x n 

1 0 0
0 1 0
0 0 1

we may allocate an array of size n only to save space
instead of n * n size to store zeros
*/

#include <iostream>
#include <time.h>


class diagonal {
private:
    int *matrix;
    int deminsions;
public:
    diagonal() {
        deminsions = 2;
        matrix = new int[deminsions];
    }
    diagonal(int deminsions) {
        this->deminsions = deminsions;
        matrix = new int[deminsions];
    }
    ~diagonal() {
        delete []matrix;
    }

    void set(int i, int j, int input);
    int get(int i, int j);
    int get_deminsions();
    void display();
};

void diagonal::set(int i, int j, int input) {
    if (i == j) {
        matrix[i] = input;
    }
}

int diagonal::get(int i, int j) {
    if (i == j) {
        return matrix[i];
    } else {
        return 0;
    }
}

int diagonal::get_deminsions() {
    return deminsions;
}

void diagonal::display() {
    for(int i = 0; i < deminsions; i++) {
        for(int j = 0; j < deminsions; j++) {
            if (i == j)
            {
                std::cout << matrix[i]  << ' ';
            } else {
                std::cout << 0  << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    diagonal matrix1(5);

    srand(time(0));
    
    for(int i = 0; i < matrix1.get_deminsions(); i++) {
        matrix1.set(i, i, (rand() % 99) + 1);
    }

    matrix1.display();

    return 0;
}