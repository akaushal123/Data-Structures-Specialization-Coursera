#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isGreater(string digit, string maxDigit){
    string XY = digit + maxDigit;
    string YX = maxDigit + digit;
    return XY.compare(YX) > 0 ? 1:0;
}

string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(), a.end(), isGreater);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
    ret << a[i];
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
