#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <math.h>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

long get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;
    n %= 60;
    long long a = 0, b = 1, c;
    for(int i = 2; i<= n; i++){
        c = (a + b)%10;
        a = b;
        b = c;
    }
    return c%10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
