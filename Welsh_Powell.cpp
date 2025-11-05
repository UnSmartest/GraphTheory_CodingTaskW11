#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        getline(cin, nodes[i]);
        if (nodes[i].empty()) i--;
    }

    unordered_map<string,int> idx;
    for (int i = 0; i < n; i++) idx[nodes[i]] = i;

    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        string u, v; double cost;
        cin >> u >> v >> cost;
        adjList[idx[u]].push_back(idx[v]);
        adjList[idx[v]].push_back(idx[u]);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b){
        return adjList[a].size() > adjList[b].size();
    });

    vector<int> color(n, 0);
    int currentColor = 0;

    for (int v : order) {
        if (color[v] == 0) {
            currentColor++;
            color[v] = currentColor;
            for (int u : order) {
                if (color[u] == 0) {
                    bool safe = true;
                    for (int w : adjList[u])
                        if (color[w] == currentColor) safe = false;
                    if (safe) color[u] = currentColor;
                }
            }
        }
    }

    cout << "# Welsh-Powell Coloring Result\n";
    cout << "Total Colors Used: " << currentColor << "\n\n";

    for (int c = 1; c <= currentColor; c++) {
        cout << "Color " << c << ": ";
        for (int i = 0; i < n; i++)
            if (color[i] == c) cout << nodes[i] << " ";
        cout << "\n";
    }
    return 0;
}
