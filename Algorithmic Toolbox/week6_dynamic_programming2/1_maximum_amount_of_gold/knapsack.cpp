#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here

  vector< vector<int> > weight(w.size() +1 , vector<int> (W+1));

  for(int i = 0; i < W + 1; i++)
    weight[0][i] = 0;

  for(int i = 0; i < w.size() + 1; i++)
    weight[i][0] = 0;


  for (int i = 1; i < w.size() + 1; i++){
    for (int j = 1; j < W + 1; j++){
        if(w[i - 1] <= j)
            weight[i][j] = std::max(weight[i-1][j], weight[i-1][j-w[i-1]] + w[i - 1]);
        else
            weight[i][j] = weight[i-1][j];
    }
  }

  return weight[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
