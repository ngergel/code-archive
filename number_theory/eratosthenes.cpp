/*
    Sieve of Eratosthenes
    ==================================

    Description:
        Finds all primes in range [2, n], for some n.
        Also grabs a prime divisor for composite numbers.
    
    Complexity:
        - Time: O(n log log n)
        - Space: O(n)

    (c) Noah Gergel 2020
*/


// Include statements.
#include <iostream> // iostream, iomanip are not necessary for the sieve.
#include <iomanip>

#include <vector>
#include <numeric>
using namespace std;


// Substitute with appropriate type.
using ll = long long;


/*
    Implementation of the sieve of Eratosthenes.

    Arguments:
        - primes: Array that will be turned into list of primes/divisors.
        - n: Upper bound of sieve.
*/
void eratosthenes(vector<ll>& primes, ll n) {
    primes.resize(n + 1); iota(begin(primes), end(primes), 0);

    for (ll i = 2; i * i <= n; i++) {
        if (primes[i] == i) {
            for (ll j = i + i; j <= n; j += i) {
                primes[j] = i;
            }
        }
    }
}


// Driver code.
int main() {
    vector<ll> pr;
    ll n;

    // Get the upper bound n.
    cout << "An upper bound n: ";
    cin >> n;

    // Run the sieve.
    eratosthenes(pr, n);

    // Print results. Nicely formatted up to n ~ 40.
    cout << " n:";
    for (ll i = 0; i <= n; i++) cout << setw(3) << i;
    cout << endl << "pr:";
    for (ll i = 0; i <= n; i++) cout << setw(3) << pr[i];
    cout << endl;

    return 0;
}