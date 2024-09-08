/*
    Kruskal's Algorithm
    ==================================

    Finds the minimum spanning tree of an undirected, weighted graph.
    
    Complexity:
        - Time: O(E log V)
        - Space: O(V + E)

    Reliability:
        - min-cost-to-connect-all-points, LeetCode

    Reference:
        - https://en.wikipedia.org/wiki/Kruskal%27s_algorithm

    (c) Noah Gergel 2024
*/


/*
    Implementation of Kruskal's Algorithm.

    Initial Arguments:
        - ve: Vector of vertices for the graph.
        - ed: Vector of edges in the form of (u, v, c), for edge uv, with cost c.

    Methods:
        - mst: Returns the minimum spanning tree of the graph.
*/
struct kruskal {
    using T = unsigned long long;
    using C = unsigned long long;
    using edge = std::tuple<T, T, C>;
    static inline auto edge_lt = [](edge const &a, edge const &b) -> bool {
        return get<2>(a) < get<2>(b);
    };

    std::vector<edge> e;
    std::vector<T> v;

    kruskal(std::vector<T>& ve, std::vector<edge>& ed) {
        v = std::vector<T>(ve), e = std::vector<edge>(ed);
    }

    std::vector<edge> mst() {
        union_find uf(v.size());
        std::sort(std::begin(e), std::end(e), edge_lt);

        std::vector<edge> mst;

        for (edge a : e) {
            if (uf.find(get<0>(a)) != uf.find(get<1>(a)))
                uf.merge(get<0>(a), get<1>(a)), mst.push_back(a);
        }

        return mst;
    }
};