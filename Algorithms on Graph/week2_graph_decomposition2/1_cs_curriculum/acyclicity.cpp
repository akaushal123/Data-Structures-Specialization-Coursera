#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, int v, vector<bool> &visited, std::unordered_set<int> &s){
    visited[v] = true;
    //insert node into set
    s.insert(v);

    for(auto w: adj[v])
        if(!visited[w] && explore(adj, w, visited, s))
            return 1;
        //search if node is already processed
        else if(s.find(w)!=s.end())
            return 1;
    //remove node after processing from set
    s.erase(v);
    return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  std::unordered_set<int> s;

  for(int v = 0; v < adj.size(); v++)
    if(!visited[v])
        if(explore(adj, v, visited, s))
            return 1;

  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
