#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> myvector = {3, 7, 2, 14, 8};
    make_heap(myvector.begin(), myvector.end());
    cout << "Before sort";
    for (int i=0; i<myvector.size(); i++) {
        cout << ' ' << myvector[i];
    }
    sort_heap(myvector.begin(), myvector.end());
    cout << "\nAfter sort";
    for (int i=0; i<myvector.size(); i++) {
        cout << ' ' << myvector[i];
    }
}