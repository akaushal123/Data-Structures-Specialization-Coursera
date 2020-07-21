#include <iostream>
#include <cstdlib>
#include <math.h>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fib_cal(int n){
    if(n==1 || n==2) return 1;
    long long a = 0, b = 1, c;
    for(int i = 2; i<= n; i++){
        c = (a + b);
        a = b;
        b = c;
    }
    return c%10;
}


long long fibonacci_sum_fast(long long n){
    //Using the property S(n) = Fib(n+2) - 1
    //Last digit in fib series repeat after every 60 terms
    n = (n)%60;
    n += 2;
    int sum = (fib_cal(n)%10 + 10)%10;
    if(sum == 0) return 9;
    return sum - 1;
}
/*
for testing purposes
void test_solution(){
    int n = 50;
    for(int i = 1; i<= n;i++){
        std::cout<<i<<" "<<fibonacci_sum_fast(i)<<" "<<fibonacci_sum_naive(i)<<std::endl;
        assert(fibonacci_sum_fast(i) == fibonacci_sum_naive(i));
    }
}
*/
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    //test_solution();
}
