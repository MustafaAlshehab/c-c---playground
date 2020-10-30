/* This applies to square matices n x n 

1 0 0
1 1 0
1 r 1

we may allocate an array of size n(n+1)/2 only to save space
which is the formula of the sum of natural number instead 
of n * n size to store zeros. This program uses row-major mapping
to map values correctly as it should on a 2d array.
*/

#include <iostream>
#include <time.h>


class lower_triangular {
private:
    int *matrix;
    int deminsions;
    int size;
public:
    lower_triangular() {
        deminsions = 2;
        size = deminsions * (deminsions + 1) / 2;
        matrix = new int[size];
    }
    lower_triangular(int deminsions) {
        this->deminsions = deminsions;
        size = deminsions * (deminsions + 1) / 2;
        matrix = new int[size];
    }
    ~lower_triangular() {
        delete []matrix;
    }

    void set(int i, int j, int input);
    int get(int i, int j);
    int get_deminsions();
    int get_index_row_major_mapping(int i, int j);
    void display();
};

void lower_triangular::set(int i, int j, int input) {
    if (i <= j) {
        matrix[get_index_row_major_mapping(i,j)] = input;
    }
}

int lower_triangular::get(int i, int j) {
    if (i <= j) {
        return matrix[get_index_row_major_mapping(i,j)];
    } else {
        return 0;
    }
}

int lower_triangular::get_deminsions() {
    return deminsions;
}

int lower_triangular::get_index_row_major_mapping(int i, int j) {
    return (i * ( i + 1) / 2) + j;
}

void lower_triangular::display() {
    for(int i = 0; i < deminsions; i++) {
        for(int j = 0; j < deminsions; j++) {
            if (i <= j)
            {
                std::cout << matrix[get_index_row_major_mapping(i,j)]  << '\t';
            } else {
                std::cout << 0  << '\t';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    lower_triangular matrix1(5);

    srand(time(0));
    
    for(int i = 0; i < matrix1.get_deminsions(); i++) {
        for(int j = 0; j < matrix1.get_deminsions(); j++) {
            matrix1.set(i, j, (rand() % 999) + 1);
        }
    }

    matrix1.display();

    return 0;
}