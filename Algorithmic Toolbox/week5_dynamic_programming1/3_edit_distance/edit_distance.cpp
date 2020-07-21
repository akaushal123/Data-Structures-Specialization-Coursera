#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {

  int n = str1.size();
  int m = str2.size();

  int ed[n+1][m+1];

  for(int i = 0; i <= n ;i++){
    for (int j = 0; j <= m; j++){
        if(i == 0)
            ed[i][j] = j;
        else if(j == 0)
            ed[i][j] = i;
        else if(str1[i - 1] == str2[j - 1])
            ed[i][j] = ed[i-1][j-1];
        else
            ed[i][j] = std::min(ed[i-1][j], std::min(ed[i][j-1], ed[i-1][j-1])) + 1; // std::min(ed[i-1][j - 1], std::min(ed[i][j-1], ed[i-1][j-1]) + 1);
    }
  }
  return ed[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
