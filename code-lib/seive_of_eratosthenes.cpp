/**
 * 
 * Title: Sieve Of Eratosthenes [Value limited]
 * Description: Display all primes numbers up to a given value N as a limiter.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero 
 * 
 */

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

void SieveOfEratosthenes(const int N) {
    
    bool store[N + 1];

    memset(store, true, sizeof(store));
    for (int i = 2; i * i <= N; ++i) {

        if (store[i]) {
            for (int j = i * 2; j <= N; j += i) {
                store[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (store[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int limit;
    cin >> limit;
    assert(("Limit should be at least 2.", limit >= 2));
    SieveOfEratosthenes(limit);
    return 0;
}

/*
Sample Input:
--------------------
200
Sample Output:
--------------------
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 
 */