#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  /*n = m / 10;
  m %= 10;
  n += m/5;
  m %= 5;
  n += m/1;
  m %= 1;
  */
  n = (m/10)+ (m%10)/5 + ((m%10)%5)/1;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
