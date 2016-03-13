#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> PII;

vector < int > pare;

int par(int x) {
    if(pare[x] == x) return x;
    if(pare[x] == -1) {
        pare[x] = x;
        return pare[x];
    }
    pare[x] = par(pare[x]);
    return pare[x];
}

int main () {
    int n, m;
    cin >> n >> m;
    pare = vector < int > (n, -1);
    int x, y, z;
    priority_queue < pair < int, PII > > cua;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--;
        y--;
        cua.push(make_pair(-z, make_pair(x, y)));
    }
    pair < int, PII > p;
    int cont = n;
    int cont2 = 0;
    while (cont != 1 and not cua.empty()) {
        p = cua.top();
        cua.pop();
        if (par(p.second.first) != par(p.second.second)) {
            pare[par(p.second.first)] = pare[p.second.second];
            cont--;
            cont2+=p.first;
        }
    }
    cout << -cont2 << endl;
}
