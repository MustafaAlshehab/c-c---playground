// ncr = n! / r! (n-r)!
// ncr formula is to find a combination of possible subset of an object 
// where order of the object doesn't matter 
// you can use this in situations where you want to know how many you could have 
// of 4 pizza with the option of 2 toppings  where 4 is n and  2 is r (r=0 to r<=n)

#include <stdio.h>

// Time O(n)
// Space O(n)
int factorial(int n) {
    if ( n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Time O(n)
// Space O(n)
// this function uses this formula ncr = n! / r! (n-r)!
int ncr (int n, int r) {
    int n_factorial = factorial(n);
    int r_factorial = factorial(r);
    int n_minus_r_factorail = factorial(n-r);

    return (n_factorial) / (r_factorial * n_minus_r_factorail);
}

// Time O(n)
// Space O(n)
// this function uses pascal's triangle
int ncr_pascals_triangle(int n, int r) {
    if (r == n || r == 0) {
        return 1;
    } else {
        return ncr_pascals_triangle(n-1, r-1) + ncr_pascals_triangle(n-1, r);
    }
}
int main() {

    int result = ncr_pascals_triangle(5,3);
    printf("%d \n", result);
    
    return 0;
}