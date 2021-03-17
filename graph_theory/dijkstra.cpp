/*
    Dijkstra's Algorithm
    ==================================

    Finds the shortest path in a weighted graph from a source.
    Also finds the minimum cost for nodes along those paths.
    
    Complexity:
        - Time: O(V + E log V), where V is # of vertices, and E # of edges.
        - Space: O(V)

    Notes:
        - It's expected that vertices will be in range [0, V), where V is # of vertices.
        - In the driver code it's assumed that the graph is directed; for an
          undirected graph just insert both (v, u) and (u, v) with the same cost.

    Reliability:
        - shortestpath1, Kattis

    Reference:
        - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type and comparison for priority queue.
using T = long long;
using comp = greater<pair<T, T> >;


// Infinity.
const T INF = 1e9;


/*
    Implementation of Dijkstra's Algorithm.

    Arguments:
        - s: Source vertex in the graph.
        - v: Number of vertices in the graph.
        - d: Array of minimum distance to any given vertex. Defaults to INF if not reachable.
        - prev: Array of parents for every vertex. Defaults to -1 if it's not reachable.
        - al: Adjacency list representation of the graph. In the pair, it goes (vertex, cost).
*/
void dijkstra(T s, T v, vector<T>& d, vector<T>& prev, vector<vector<pair<T, T> > >& al) {
    priority_queue<pair<T, T>, vector<pair<T, T> >, comp> qu;
    vector<bool> marked(v, false);
    
    d.clear(); d.resize(v, INF);
    prev.clear(); prev.resize(v, -1);

    d[s] = 0;
    qu.push(make_pair(0, s));

    while (!qu.empty()) {
        pair<T, T> entry = qu.top(); qu.pop();
        T cur = entry.second;

        if (marked[cur]) continue;

        for (auto nbr : al[cur]) {
            if (marked[nbr.first]) continue;

            if (d[cur] + nbr.second < d[nbr.first]) {
                d[nbr.first] = d[cur] + nbr.second;
                prev[nbr.first] = cur;
                qu.push(make_pair(d[nbr.first], nbr.first));
            }
        }

        marked[cur] = true;
    }
}


// Driver code.
int main() {
    vector<vector<pair<T, T> > > al;
    vector<T> dist, parents;
    T v, e;

    // Get number of vertices and edges.
    cout << "Number of vertices: "; cin >> v;
    cout << "Number of edges: "; cin >> e;

    al.resize(v);

    // Read in each edge.
    T a, b, c;
    while (e--) {
        cout << "Edge from a -> b, with cost c: "; cin >> a >> b >> c;
        al[a].push_back(make_pair(b, c));
    }

    // Run dijkstra's. Suppose 0 is the source vertex.
    dijkstra(0, v, dist, parents, al);

    // Write results.
    cout << "Edges in shortest path tree:" << endl;
    for (size_t i = 0; i < v; i++) cout << setw(3) << parents[i] << " -> " << i << endl;
    cout << "Minimum cost of each vertex:" << endl;
    for (size_t i = 0; i < v; i++) cout << setw(3) << i << ": " << dist[i] << endl;

    return 0;
}