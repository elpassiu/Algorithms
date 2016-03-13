#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    vector < int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int right = n, left = 0;
    while (left + 1 < right) {
        int mid = (left+right)/2;
        if (v[mid] > x) right = mid;
        else left = mid;
    }
    if (v[left] == x) cout << left+1 << endl;
    else cout << "It is not in the list" << endl;
}
