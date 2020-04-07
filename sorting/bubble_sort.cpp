/*
    Bubble Sort
    ==================================

    Given an array of values, sorts them.
    
    Complexity:
        - Time: O(n^2)
        - Space: O(n)

    Notes:
        - Assumes > operator is implemented for the given type.

    Reference:
        - https://en.wikipedia.org/wiki/Bubble_sort

    (c) Noah Gergel, Ian DeHaan 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type.
using ll = long long;


void bubble_sort(vector<ll>& arr) {
    size_t n = arr.size(), new_n;
    ll temp;

    do {
        new_n = 0;

        for (size_t i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                temp = arr[i - 1]; arr[i - 1] = arr[i]; arr[i] = temp;
                new_n = i;
            }
        }

        n = new_n;
    } while (n > 1);
}


// Driver code.
int main() {
    vector<ll> a; ll n;

    // Read in array of values.
    cout << "Size of array: "; cin >> n;

    a.resize(n);

    cout << "Space-seperated array values: ";
    for (size_t i = 0; i < n; i++) cin >> a[i];

    // Run bubble sort.
    bubble_sort(a);
    
    // Write the results.
    cout << "Sorted array:" << endl;
    for (ll i : a) cout << i << ' ';
    cout << endl;

    return 0;
}