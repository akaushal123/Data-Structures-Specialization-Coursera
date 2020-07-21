#include <iostream>
#include <math.h>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long cal_fib(long long n){
    if(n<=1) return n;

    n %= 60;
    long long a = 0, b = 1, c;
    for(int i = 2; i<= n; i++){
        c = (a + b);
        a = b;
        b = c;
    }
    return c%10;
}

int fibonacci_sum_squares_fast(long long n){
    return (cal_fib(n) * cal_fib(n + 1))%10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
