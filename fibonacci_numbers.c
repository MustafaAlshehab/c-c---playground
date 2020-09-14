#include <stdio.h>
#include <stdlib.h>


int fib_rec_memoization_helper(int n, int fib_results[]);

// Time complexity here is O(2^2)
// Space complexity will be O(n)
int fib_rec (int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}

// make use of dynamic programming
// time complexity O(n)
// Space complexity will be O(n)
int fib_rec_memoization (int n) {
    int *fib_results = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        fib_results[i] = -1;
    }
    fib_results[0] = 0;
    fib_results[1] = 1;
    return fib_rec_memoization_helper(n, fib_results);
}

int fib_rec_memoization_helper(int n, int fib_results[]) {
    if (fib_results[n - 1] != -1) {
        return fib_results[n - 1];
    } else {
        fib_results[n - 1] = fib_rec_memoization_helper(n - 1, fib_results) + fib_rec_memoization_helper(n - 2, fib_results);
        return fib_results[n - 1];
    }
}

// Time complexity here is O(n)
// Space complexity will be O(1)
int fib_iterative(int n) {
    int a = 0, b = 1;
    if ( n == 1) {
        return a;
    } else if ( n == 2) {
        return b;
    } else {
        int i = 3, temp = 0;
        while (i <= n) {
            temp = a;
            a = b;
            b = temp + b;
            i++;
        }
        return b;
    }
}

int main() {
    
    int result =  fib_rec_memoization(5);
    printf("result is: %d\n", result);
    
    return 0;
}