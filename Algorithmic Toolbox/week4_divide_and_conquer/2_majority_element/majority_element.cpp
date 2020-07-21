#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  std::unordered_map<int,int> m;
  for(int i = 0; i< a.size(); i++)
    m[a[i]]++;
  for(auto i:m)
    if(i.second > (a.size())/2)
        return 1;
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1)) << '\n';
}
