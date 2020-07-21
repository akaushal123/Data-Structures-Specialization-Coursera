#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    int max;

  public:

    void Push(int value) {
        if(stack.empty()){
            max = value;
            stack.push_back(value);
            return;
        }

        if(value > max){
            stack.push_back(2 * value - max);
            max = value;
        } else {
            stack.push_back(value);
        }

    }

    void Pop() {
        assert(stack.size());
        int last = stack.back();
        stack.pop_back();
        if(last > max){
            max = 2 * max - last;
        }
    }

    int Max() const {
        assert(stack.size());
        return max;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
