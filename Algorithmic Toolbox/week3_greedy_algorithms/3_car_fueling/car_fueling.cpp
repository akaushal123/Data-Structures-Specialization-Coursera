#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    stops.insert(stops.begin(),0);
    int n = stops.size();
    int numRefill = 0, curRefill = 0, lastRefill = 0;
    while(stops[curRefill] + tank < dist){
        lastRefill = curRefill;
        while(curRefill < n && (stops[curRefill + 1] - stops[lastRefill] <= tank))
            curRefill += 1;
        if (curRefill < n)
            numRefill += 1;
        if (curRefill == lastRefill)
            return -1;
    }
    return numRefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
