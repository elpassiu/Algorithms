#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s, m;
    cin >> s >> m;
    string k = s+"%"+m;
    int n = int(k.size());
    vector <int> v (n+1);
    v[0] = -1;
    for (int i = 0; i < n; i++) {
        int j = v[i];
        while (j >= 0 and k[i]!=k[j]) j =v[j];
        v[i+1] = j+1;
    }
}