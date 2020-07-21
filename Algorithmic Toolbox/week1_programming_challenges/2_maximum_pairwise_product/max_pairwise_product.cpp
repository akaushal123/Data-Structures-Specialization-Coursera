#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_numindex1 = -1;
    int max_numindex2 = -1;
    int n = numbers.size();
    for(int i = 0; i < n; ++i)
        if(max_numindex1 == -1 || (numbers[i] > numbers[max_numindex1]))
            max_numindex1 = i;

    for(int i = 0; i < n; ++i)
        if((i != max_numindex1) &&(max_numindex2 == -1 || (numbers[i] > numbers[max_numindex2])))
            max_numindex2 = i;

    return ((long long)numbers[max_numindex1] * numbers[max_numindex2]);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
