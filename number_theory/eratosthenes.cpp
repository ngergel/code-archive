/*
    Sieve of Eratosthenes
    ==================================

    Finds all primes in range [2, n], for some n.
    Also grabs a prime divisor for composite numbers.
    
    Complexity:
        - Time: O(n log log n)
        - Space: O(n)

    Reference:
        - https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>
using namespace std;


// Substitute with appropriate type.
using T = long long;


/*
    Implementation of the sieve of Eratosthenes.

    Arguments:
        - primes: Array that wiT be turned into list of primes/divisors.
        - n: Upper bound of sieve.
*/
void eratosthenes(vector<T>& primes, T n) {
    primes.resize(n + 1); iota(begin(primes), end(primes), 0);

    for (size_t i = 2; i * i <= n; i++) {
        if (primes[i] == i) {
            for (size_t j = i + i; j <= n; j += i) primes[j] = i;
        }
    }
}


// Driver code.
int main() {
    vector<T> pr;
    T n;

    // Get the upper bound n.
    cout << "An upper bound n: "; cin >> n;

    // Run the sieve.
    eratosthenes(pr, n);

    // Write results. Nicely formatted up to n ~ 40.
    cout << " n:"; for (size_t i = 0; i <= n; i++) cout << setw(3) << i; cout << endl;
    cout << "pr:"; for (size_t i = 0; i <= n; i++) cout << setw(3) << pr[i]; cout << endl;
    return 0;
}