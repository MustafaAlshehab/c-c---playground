#include <iostream>
#include <unordered_map>


// time O(2^n) since each function will call 2 functions 
// space O(n) since the call stack will have (n) functions at a time
unsigned long nth_fibonacci_rec(int n) {
    if (n == 1){
        return 0;
    } else if (n == 2){
        return 1;
    } else {
        return nth_fibonacci_rec(n - 1) + nth_fibonacci_rec(n - 2);
    }
}

// optimized recursive solution that will cache up the values of
// every visited function using memoization or memoisation which 
// is an optimization technique used primarily to speed up computer 
// programs by storing the results of expensive function calls and
// returning the cached result when the same inputs occur again. 
// time O(n) since every value will be cached 
// returning the cached result when the same inputs occur again
// space O(n) since the call stack will have (n) function and 
// we are using memoisation/cashing to store results
long unsigned nth_fibonacci_rec_optimized(int n, std::unordered_map<int, long unsigned> &fib_result);

long unsigned nth_fibonacci_rec_optimized(int n){
    std::unordered_map<int, long unsigned> fib_result({{1,0}, {2,1}});
    return nth_fibonacci_rec_optimized(n, fib_result);
}

long unsigned nth_fibonacci_rec_optimized(int n, std::unordered_map<int, long unsigned> &fib_result) {
    if (fib_result.find(n) != fib_result.end()) {
        return fib_result[n];
    }
    else {
        fib_result[n] = nth_fibonacci_rec_optimized(n - 1, fib_result) + nth_fibonacci_rec_optimized(n - 2, fib_result); 
        return fib_result[n];
    }
}

// iterative version, note that in this case we don't have
// save all the previous calcs as the recessive method
// instead we could use only an array of size 2
// Time complexity will be O(n) 
// Space complexity O(1) we are only using an array of size 2 
unsigned long nth_fibonacci_iterative(int n) {
    unsigned long fib_result[2] = {0, 1};
    int counter = 3;
    while (counter <= n) {
        unsigned long next_fib = fib_result[0] + fib_result[1];
        fib_result[0] = fib_result[1];
        fib_result[1] = next_fib;
        counter++;
    }
    return n > 1 ? fib_result[1] : fib_result[0];
}
    
int main() {
    int input = 0;
    std::cout << "enter a number" << '\n';
    std::cin >> input;
    //unsigned long result = nth_fibonacci_rec(input);
    unsigned long result = nth_fibonacci_rec_optimized(input);
    //unsigned long result = nth_fibonacci_iterative(input);
    std::cout << result << '\n';

    return 0; 
}