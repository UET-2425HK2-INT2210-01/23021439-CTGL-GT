#include <iostream>
#include<fstream>
using namespace std;

struct Edge {
    int u, v, cost;
};

Edge edges[1000];
Edge mst[1000];
int parent[1000], rank_set[1000];
int n, m;

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank_set[i] = 0;
    }
}

int findSet(int u) {
    if (parent[u] != u)
        parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u != v) {
        if (rank_set[u] < rank_set[v])
            swap(u, v);
        parent[v] = u;
        if (rank_set[u] == rank_set[v])
            rank_set[u]++;
    }
}

void sortEdges() {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < m - i - 1; ++j) {
            if (edges[j].cost > edges[j + 1].cost) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    ifstream infile("F:\\CODE\\input.txt");
    ofstream outfile("F:\\CODE\\output.txt");
    infile >> n >> m;

    for (int i = 0; i < m; ++i) {
        infile >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    init();
    sortEdges();

    int totalCost = 0, edgeCount = 0;

    for (int i = 0; i < m && edgeCount < n - 1; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            mst[edgeCount++] = edges[i];
            totalCost += edges[i].cost;
        }
    }

    outfile << totalCost << endl;
    for (int i = 0; i < edgeCount; ++i) {
        outfile << mst[i].u << " " << mst[i].v << " " << mst[i].cost << endl;
    }

    return 0;
}
