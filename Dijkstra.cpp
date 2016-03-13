#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> PII;

int main () {
    int n, m, c, t, k;
    cin >> n >> m;                  // n = number of vertices; m = number of edges;
    vector < vector < PII > > v(n); // adjacency list of the graph. In this pair: "first" = vertex number; "second" = weight of the edge
    for (int i = 0; i < m; i++) { 
        cin >> c >> t >> k;
        v[c].push_back(make_pair(t ,k));
    }
    vector < int > visited (n, -1); // vector where the weight of the path is stored. It stores -1 if it hasn't been visited yet
    priority_queue <PII> cua;       //priority queue for Dijsktra's implementation. In this pair: "first" = vertex number; "second" = weight
    cua.push(make_pair(0,0));       //inicialization of the priority queue with vertex 0 and weight 0
    while (not cua.empty()) {
        t = cua.top().first;
        k = cua.top().second;
        cua.pop();
        if (visited[k] == -1) {     // if the vertex has not yet been visited...
            visited[k] = -t;        // we store the weight of the path, which we know to be the minimum
            for (int i = 0; i < v[k].size(); i++) { // Then add to the priority queue all the vertices adjacent to the actual vertex
                if (visited[v[k][i].first] == -1) cua.push(make_pair(t - v[k][i].second, v[k][i].first)); // that have not been visited yet
            }                                   
        }
    }
    for (int i = 1; i < n; i++) {
        if (visited[i] == -1) cout << i << " : not connected" << endl;
        else cout << i << " : " << visited[i] << endl;
    }
}
