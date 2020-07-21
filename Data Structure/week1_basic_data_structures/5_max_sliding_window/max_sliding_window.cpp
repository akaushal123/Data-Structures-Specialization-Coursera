#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    deque<int> dq(w); // for storing index of max elements in window
    for(int i= 0; i< w; i++){
        //remove element which are smaller than current element
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(int i = w; i < A.size(); i++){
        cout<<A[dq.front()]<<" ";
        //remove element which are out of window
        while(!dq.empty() && dq.front() <= (i - w))
            dq.pop_front();
        //remove element which are smaller than current element
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<A[dq.front()];
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
