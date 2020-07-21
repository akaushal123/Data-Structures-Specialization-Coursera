#include <iostream>
#include <vector>
#include <math.h>

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){

    from = from%60;
    to = to%60;
    if(to < from)
        to += 60;

    int sum = 0;
    long long previous = 0;
    long long current = 1;

    for(int i = 0; i <= to; i++){
        if(i >= from){
            sum = (sum + previous)%10;
        }
        long long new_current = current;
       current = previous + current;
        previous = new_current;
    }

    return sum%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
