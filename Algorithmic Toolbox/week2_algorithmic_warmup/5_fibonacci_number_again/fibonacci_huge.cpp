#include <iostream>
#include <math.h>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisano_period(long long m){
    long long previous = 0;
    long long current = 1;
    for(int i = 0;i < (m*m); i++){
        long long temp = (previous + current)%m;
        previous = current;
        current = temp;
        if(previous == 0 && current == 1)
                return i+1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {

    n = n % pisano_period(m);

    long long previous = 0, current = 1, tmp_previous = n;

    for (long long i = 1; i < n; ++i) {
        tmp_previous = (previous + current)%m;
        previous = current;
        current = tmp_previous;
    }
    return tmp_previous % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
