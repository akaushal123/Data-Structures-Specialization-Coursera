#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool is_bipartite_util(vector<vector<int> > &adj, int v, vector<int> &color){
    queue<int> q;
    q.push(v);
    color[v] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto w: adj[u]){
            if(color[w] == -1){
                color[w] = 1 - color[u];
                q.push(w);
            } else if(color[w] == color[u])
                return false;
        }
    }
    return true;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here

  //-1 indicates no color assigned
  //0 color 1 assigned
  //1 color 2 assigned
  vector<int> color(adj.size(), -1);
  for(int i = 0; i < adj.size(); i++)
    if(color[i] == -1)
        if(!is_bipartite_util(adj, i, color))
            return 0;
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
