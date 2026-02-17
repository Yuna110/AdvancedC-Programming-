#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi taken;
priority_queue<ii> pq;   // max heap (we use negative weight)

void process(int u) {
    taken[u] = 1;
    for (auto &[v, w] : AL[u]) {
        if (!taken[v]) {
            pq.push({-w, -v});  // simulate min heap
        }
    }
}

int main() {

    int V, E;
    cin >> V >> E;   // 🔥 read from terminal

    AL.assign(V, vii());

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }

    taken.assign(V, 0);
    process(0);

    int mst_cost = 0, num_taken = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        w = -w;
        u = -u;

        if (taken[u]) continue;

        mst_cost += w;
        process(u);
        ++num_taken;

        if (num_taken == V - 1) break;
    }

    cout << "MST cost = " << mst_cost << " (Prim's)" << endl;

    return 0;
}
