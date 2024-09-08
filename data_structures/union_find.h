/*
    Union Find
    ==================================

    Disjoint-set data structure which keeps track of a set of elements
    partitioned into a number of disjoint subsets.
    
    Complexity:
        - Time:
            * init: O(n)
            * find: O(alpha n)
            * merge: O(alpha n)
        - Space: O(n)

    Reliability:
        - unionfind, Kattis
        - count-sub-islands, LeetCode

    Reference:
        - https://en.wikipedia.org/wiki/Disjoint-set_data_structure

    (c) Noah Gergel 2020
*/


/*
    Implementation of the union find data structure.

    Initial Arguments:
        - n: Maximum number of elements. Also the initial number of disjoint sets.

    Methods:
        - find: Find and return the representative of a subset, given an element.
        - merge: Merge two disjoint subsets into one subset.
*/
struct union_find {
    using T = unsigned long long;
    std::vector<T> p, r;

    union_find(T n) {
        p.resize(n), r.resize(n);
        std::iota(std::begin(p), std::end(p), 0);
        std::fill(std::begin(r), std::end(r), 1);
    }

    T find(T x) {
        return p[x] = (x == p[x] ? x : find(p[x]));
    }

    bool merge(T x, T y) {
        x = find(x), y = find(y);
        if (x == y) return false;

        if (r[x] < r[y]) std::swap(x, y);
        r[x] += r[y], p[y] = x;
        return true;
    }
};