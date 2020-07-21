#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  if(A.size() < 3) return 0;

  long long sum = 0;

  for(int x:A)
    sum += x;

  if(sum %3) return 0;

  sum = sum/3;

  int partition_array[sum + 1][A.size() + 1];

  for(int i = 0; i < sum + 1; i++)
    partition_array[i][0] = 0;

  for(int i = 0; i < A.size() + 1; i++)
    partition_array[0][i] = 0;

  int count = 0;

  for(int i = 1; i <sum +1; i++){
    for(int j = 1; j < A.size() + 1; j++){
        partition_array[i][j] = partition_array[i][j-1];
        if(i >= A[j-1])
            partition_array[i][j] = std::max(partition_array[i][j], partition_array[i- A[j-1]][j-1] + A[j-1]);
        if (partition_array[i][j] == sum)
            count++;
    }
  }
  return count < 3 ? 0:1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
