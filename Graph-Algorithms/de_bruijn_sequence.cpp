/*
Problem Link: https://cses.fi/problemset/task/1692

Approach:

- Model the problem as an Eulerian path over a directed graph:
    - Nodes: all binary strings of length n-1
    - Edges: append 0 or 1 to a node and move to the suffix of length n-1
- Perform DFS to simulate Hierholzer’s algorithm and record the path.
- Reconstruct the de Bruijn sequence from the traversal.

*/

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> seen;
vector<int> edges;

void dfs (string startNode, string& Chars) {
    for (size_t i = 0; i < Chars.size(); i++) {
        string newNode = startNode + Chars[i];
        if (!seen.count(newNode)) {
            seen.insert(newNode);
            dfs(newNode.substr(1), Chars);
            edges.push_back(i);
        }
    }
}

void deBruijn() {
    int n;
    cin >> n;

    string Chars = "01";

    string startNode = string(n - 1, Chars[0]);
    dfs(startNode, Chars);

    string seq;
    for (size_t i = 0; i < edges.size(); i++) {
        seq += Chars[edges[i]];
    }
    seq += startNode;

    cout << seq << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deBruijn();
    return 0;
}