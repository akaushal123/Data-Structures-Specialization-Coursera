#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  vector<int> min_steps(n + 1, 0);
  for(int i = 1; i < min_steps.size(); i++){
    min_steps[i] = min_steps[i-1] + 1;
    if(i%2 == 0)
        min_steps[i] = std::min(min_steps[i/2] + 1, min_steps[i]);
    if(i%3 == 0)
        min_steps[i] = std::min(min_steps[i/3] + 1, min_steps[i]);
  }

  for(int i = n; i > 1; ){
    sequence.push_back(i);
    if(min_steps[i - 1] == min_steps[i] - 1)
        i = i-1;
    else if(i%2 == 0 && (min_steps[i/2] == min_steps[i] - 1))
        i /= 2;
    else if(i%3 == 0 && (min_steps[i/3] == min_steps[i] - 1))
        i /= 3;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
