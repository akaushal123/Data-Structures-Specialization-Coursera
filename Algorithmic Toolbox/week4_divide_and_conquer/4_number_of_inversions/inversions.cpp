#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right){
    int i = left, j = mid, k = left;
    int inversion_count = 0;

    while((i < mid) && (j <= right)){
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            inversion_count += (mid - i);
        }
    }

    while(i < mid)
        b[k++] = a[i++];

    while(j <=  right)
        b[k++] = a[j++];

    for(int i = left;i <= right; i++)
        a[i] = b[i];

    return inversion_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if ( left < right){
      size_t ave = left + (right - left) / 2;

      number_of_inversions += get_number_of_inversions(a, b, left, ave);
      number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
      //write your code here
      number_of_inversions += merge(a, b,left, ave + 1, right);
  }
  return number_of_inversions;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, n - 1) << '\n';
}
