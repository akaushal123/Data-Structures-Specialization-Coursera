#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;

  // write your code here
  double n = weights.size();
  vector< std::pair <double,double> > value_per_unit_weight(n);
  for(int i = 0;i < n; i++){
    double v_w = (double) (values[i])/weights[i];
    value_per_unit_weight.push_back(std::make_pair(v_w,weights[i]));
  }

  sort(value_per_unit_weight.begin(), value_per_unit_weight.end(), std::greater< std::pair<double, double> >());

  for (int i = 0;i < n; i++){
    if(capacity == 0)
        return value;
    double a = std::min(value_per_unit_weight[i].second, capacity);
    value += a * value_per_unit_weight[i].first;
    weights[i] -= a;
    capacity = capacity - a;
  }
  return value;
}

int main() {
  double n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
  return 0;
}
