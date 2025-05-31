#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq; // store indices of negative numbers
    vector<int> result;

    for (int i = 0; i < n; i++) {
        // If current element is negative, add its index
        if (arr[i] < 0)
            dq.push_back(i);

        // Remove elements out of current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // If window has formed
        if (i >= k - 1) {
            if (!dq.empty())
                result.push_back(dq.front()+1); // first negative
            else
                result.push_back(-1); // no negative in window
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 1, 2, -1, 3, 2, -3, -4, 2};
    int k = 3;

    vector<int> res = firstNegativeInWindow(arr, k);

    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}
