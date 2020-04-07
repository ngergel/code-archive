/*
    Dijkstra's Algorithm
    ==================================

    Finds the shortest path in a weighted graph from a source.
    Also finds the minimum cost for nodes along those paths.
    
    Complexity:
        - Time: O(V + E log V), where V is # of vertices, and E # of edges.
        - Space: O(V)

	Reference:
		- https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type and comparison for priority queue.
using ll = long long;
using comp = greater<pair<ll, ll> >;


// Infinity.
const ll INF = 1e9;


/*
    Implementation of Dijkstra's Algorithm.

    Arguments:
        - s: Source vertex in the graph.
        - v: Number of vertices in the graph.
        - dist: Array of minimum distance to any given vertex.
        - parent: Array of parents for every vertex.
             Defaults to -1 if there's no parent.
        - al: Adjacency list representation of the graph.
*/
void dijkstra(ll s, ll v, vector<ll>& dist, vector<ll>& parent,
			  const vector<vector<pair<ll, ll> > > al) {
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, comp> qu;
	vector<bool> marked(v, false);
	
	d.clear(); d.resize(v, INF);
	p.clear(); p.resize(v, -1);
}


// Driver code.
int main() {

	dijkstra(s, d, p, v, al);

	return 0;
}