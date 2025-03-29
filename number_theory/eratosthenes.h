/*
    Sieve of Eratosthenes
    ==================================

    Finds all primes in range [2, n], for some n.
    Also grabs a prime divisor for composite numbers.
    
    Complexity:
        - Time: O(n log log n)
        - Space: O(n)

    Reliability:
        - count-primes, LeetCode

    Reference:
        - https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

    (c) Noah Gergel 2020
*/


#include <bits/stdc++.h>


/*
    Implementation of the sieve of Eratosthenes.

    Initial Arguments:
        - n: Upper bound of sieve.

    Methods:
        - sieve: Run the Sieve of Eratosthenes algorithm. Stores result/prime factors in `pf`.
*/
struct eratosthenes {
    using T = long long;

    size_t n;
    std::vector<T> pf;

    eratosthenes(T lim) {
        n = lim, pf.resize(n + 1);
        std::iota(std::begin(pf), std::end(pf), 0);
    }

    std::vector<T>* sieve() {
        for (size_t i = 2; i * i <= n; i++) {
            if (pf[i] == i) {
                for (size_t j = i * i; j <= n; j += i) pf[j] = i;
            }
        }

        return &pf;
    }
};