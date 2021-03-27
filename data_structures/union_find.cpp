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

    Reference:
        - https://en.wikipedia.org/wiki/Disjoint-set_data_structure

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type.
using T = long long;


/*
    Implementation of the union find data structure.

    Initial Arguments:
        - n: Maximum number of elements. Also the initial number of disjoint sets.

    Methods:
        - find: Find and return the representative of a subset, given an element.
        - merge: Merge two disjoint subsets into one subset.
*/
struct union_find {
    vector<T> a;

    union_find(T n) {
        a.resize(n);
        iota(begin(a), end(a), 0);
    }

    T find(T x) {
        return a[x] = (x == a[x] ? x : find(a[x]));
    }

    void merge(T x, T y) {
        a[find(x)] = find(y);
    }
};


// Driver code.
int main() {
    // Suppose the type is ints and their are 6 elements.
    union_find uf(6);

    // // Merge some subsets.
    uf.merge(0, 1); uf.merge(4, 5);
    uf.merge(2, 3); uf.merge(0, 2);

    // Check if two elements are in the same subset.
    T a, b;
    cout << "Check if two elements a, b are in the same subset: "; cin >> a >> b;
    if (uf.find(a) == uf.find(b)) cout << "a, b are in the same subset." << endl;
    else cout << "a, b are not in the same subset." << endl;

    // Write all elements and their representatives.
    cout << "elements: ";
    for (size_t i = 0; i < 6; i++) cout << setw(3) << i << ' '; cout << endl;
    cout << "     rep: ";
    for (size_t i = 0; i < 6; i++) cout << setw(3) << uf.find(i) << ' '; cout << endl;

    return 0;
}