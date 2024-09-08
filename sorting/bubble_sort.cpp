/*
    Bubble Sort
    ==================================

    Given an array of values, it sorts them.
    
    Complexity:
        - Time: O(n^2)
        - Space: O(n)

    Notes:
        - Assumes > operator is implemented for the given type.
        - Including this algorithm was inspired in every respect by Ian DeHaan.

    Reference:
        - https://en.wikipedia.org/wiki/Bubble_sort

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type.
using T = long long;


void bubble_sort(vector<T>& arr) {
    size_t n = arr.size(), new_n;
    T temp;

    do {
        new_n = 0;

        for (size_t i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i], arr[i] = temp, new_n = i;
            }
        }

        n = new_n;
    } while (n > 1);
}


// Driver code.
int main() {
    vector<T> a; T n;

    // Read in array of values.
    cout << "Size of array: "; cin >> n;

    a.resize(n);

    cout << "Space-seperated array values: ";
    for (size_t i = 0; i < n; i++) cin >> a[i];

    // Run bubble sort.
    bubble_sort(a);
    
    // Write the results.
    cout << "Sorted array:" << endl;
    for (T i : a) cout << i << ' ';
    cout << endl;

    return 0;
}
