#include <iostream>
#include <cassert>
#include<string>
#include <cstring>
#include <vector>
#include <climits>
#include<cmath>

using std::vector;
using std::string;
using std::max;
using std::min;

long long max(long long a, long long b, long long c, long long d, long long e){
    return max(a, max(b, max(c, max(d,e))));
}

long long min(long long a, long long b, long long c, long long d, long long e){
    return min(a, min(b, min(c, min(d,e))));
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int n = exp.size();
  int number_of_digits = (n + 1)/2;
  long long min_values[number_of_digits][number_of_digits];
  long long max_values[number_of_digits][number_of_digits];

  memset(min_values, 0 , sizeof(min_values));
  memset(max_values, 0 , sizeof(max_values));
  for(int i = 0; i < number_of_digits; i++){
    min_values[i][i] = std::stoll(exp.substr(2 * i,1));
    max_values[i][i] = std::stoll(exp.substr(2 * i,1));
  }

  for (int s = 0; s < number_of_digits - 1; s++){
    for (int i = 0; i < number_of_digits - s - 1; i++){
        int j = s + i + 1;
        long long min_val = LLONG_MAX;
        long long max_val = LLONG_MIN;
        for(int k = i; k < j; k++){
            long long a = eval(min_values[i][k], min_values[k+1][j], exp[2*k + 1]);
            long long b = eval(min_values[i][k], max_values[k+1][j], exp[2*k + 1]);
            long long c = eval(max_values[i][k], min_values[k+1][j], exp[2*k + 1]);
            long long d = eval(max_values[i][k], max_values[k+1][j], exp[2*k + 1]);
            min_val = min(min_val, a, b, c, d);
            max_val = max(max_val, a, b, c, d);
        }
        min_values[i][j] = min_val;
        max_values[i][j] = max_val;
    }
  }
  return max_values[0][number_of_digits-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
