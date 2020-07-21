#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int Parent(int i){
    return floor((i-1)/2);
  }

  int LeftChild(int i){
    return 2 * i + 1;
  }

  int RightChild(int i){
    return 2 * i + 2;
  }

  void ShiftDown(int i){
    int minIndex = i;
    int l = LeftChild(i);
    if(l < data_.size() && data_[l] < data_[minIndex])
        minIndex = l;

    int r = RightChild(i);
    if(r < data_.size() && data_[r] < data_[minIndex])
        minIndex = r;

    if(i != minIndex){
        swap(data_[i], data_[minIndex]);
        swaps_.push_back(make_pair(i, minIndex));
        ShiftDown(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    int n = data_.size();

    for(int i = (n-1)/2; i+1 != 0; i--)
        ShiftDown(i);

    /*for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
