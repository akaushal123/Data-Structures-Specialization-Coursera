#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore_connected_components(vector<vector<int> > &adj, int v, vector<bool> &visited){
    visited[v] = true;
    for(auto w: adj[v])
        if(!visited[w])
            explore_connected_components(adj, w, visited);
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector<bool> visited(adj.size(), false);

  for(int v = 0; v < adj.size(); v++){
    if(!visited[v]){
        explore_connected_components(adj, v, visited);
        res += 1;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
