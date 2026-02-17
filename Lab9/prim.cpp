#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi taken;
priority_queue<ii> pq;  // max heap (we use negative weight)

void process(int u) {
    taken[u] = 1;
    for (int i = 0; i < AL[u].size(); i++) {
        int v = AL[u][i].first;
        int w = AL[u][i].second;
        if (!taken[v]) {
            pq.push(ii(-w, -v));  // push negative to simulate min-heap
        }
    }
}

int main() {

    int V, E;
    cin >> V >> E;

    AL.assign(V, vii());

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].push_back(ii(v, w));
        AL[v].push_back(ii(u, w));
    }

    taken.assign(V, 0);
    process(0);

    int mst_cost = 0;
    int num_taken = 0;

    while (!pq.empty()) {
        ii top = pq.top(); 
        pq.pop();

        int w = -top.first;
        int u = -top.second;

        if (taken[u]) continue;

        mst_cost += w;
        process(u);
        num_taken++;

        if (num_taken == V - 1) break;
    }

    if (num_taken != V - 1)
        cout << "Graph is not connected\n";
    else
        cout << "MST cost = " << mst_cost << " (Prim's)\n";

    return 0;
}
