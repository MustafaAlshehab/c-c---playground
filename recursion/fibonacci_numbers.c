#include <stdio.h>
#include <stdlib.h>


int fib_rec_memoization_helper(int n, int fib_results[]);

// Time complexity here is O(2^n)
// Space complexity will be O(n)
int fib_rec (int n) {
    if (n < 2) {
        return n;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}

// make use of dynamic programming
// time complexity O(n)
// Space complexity will be O(n)
int fib_rec_memoization (int n) {
    int *fib_results = (int *)malloc(sizeof(int) * n + 1);
    for(int i = 0; i <= n; i++) {
        fib_results[i] = -1;
    }
    fib_results[0] = 0;
    fib_results[1] = 1;
    return fib_rec_memoization_helper(n, fib_results);
}

int fib_rec_memoization_helper(int n, int fib_results[]) {
    if (fib_results[n] != -1) {
        return fib_results[n];
    } else {
        fib_results[n] = fib_rec_memoization_helper(n - 1, fib_results) + fib_rec_memoization_helper(n - 2, fib_results);
        return fib_results[n];
    }
}

// Time complexity here is O(n)
// Space complexity will be O(1)
int fib_iterative(int n) {
    int a = 0, b = 1;
    int i = 2, nextFib = 0;
    while (i <= n) {
        nextFib = a + b;
        a = b;
        b = nextFib;
        i++;
    }
    return n >= 1 ? b : a;
}

int main() {

    int input;
    scanf("%d", &input);
    
    int result =  fib_iterative(input);
    printf("result is: %d\n", result);
    
    return 0;
}