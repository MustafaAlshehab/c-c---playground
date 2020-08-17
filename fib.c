#include <stdio.h>

// Time complexity here is O(2^2)
// Space complixty will be O(n)
int fib_rec (int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}
// time complexity O(n)
// you will have n + 1 function function calls
// Space complixty will be O(n)
int fib_rec_memoization (int n) {
    static int result[50] = {0,1};
    if (n == 1) {
        return result[0];
    } else if (n == 2) {
        return result[1];
    } else if (result[n] > 0) {
        return result[n];
    } else {
        result[n] = fib_rec_memoization(n - 1) + fib_rec_memoization(n - 2);
        return result[n];
    }
}
// Time complexity here is O(n)
// Space complixty will be O(1)
int fib_itirative(int n){
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
    
    int result =  fib_itirative(12);
    printf("result is: %d\n", result);
    
    return 0;
}