#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> PII;

int main () {
    int n, m, c, t, k;
    cin >> n >> m;
    priority_queue <PII> cua;
    vector < int > visited (n, -1);
    vector < vector < pair < int, int > > > v(n);
    for (int i = 0; i < m; i++) {
        cin >> c >> t >> k;
        v[c].push_back(make_pair(k ,t));
    }
    cua.push(make_pair(0,0));
    while (not cua.empty()) {
        t = cua.top().first;
        k = cua.top().second;
        cua.pop();
        if (visited[k] == -1) {
            visited[k] = -t;
            for (int i = 0; i < v[k].size(); i++) {
                if (visited[v[k][i].second] == -1) cua.push(make_pair(t - v[k][i].first, v[k][i].second));
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (visited[i] == -1) cout << "not connected" << endl;
        else cout << visited[i] << endl;
    }
}
