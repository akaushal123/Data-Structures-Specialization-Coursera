#include <iostream>

int get_change(int m) {
  int denomination[] = {1 , 3, 4};
  int minNumCoins[m + 1];
  minNumCoins[0] = 0;

  for(int i = 1; i <= m + 1; i++){
    minNumCoins[i] = minNumCoins[i - 1] + 1;
    for (int j = 0; j < 3; j++){
        if (i >= denomination[j]){
            int numCoins = minNumCoins[i - denomination[j]] + 1;
            minNumCoins[i] = std::min(numCoins, minNumCoins[i]);
        }
    }
  }

  return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
