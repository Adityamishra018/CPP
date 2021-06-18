#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R, L;
    cin >> L >> R;
    vector<bool> isPrime(R - L + 1, true); //created a vector of size R-L and intitially setting all elements to true
    long long int lim = sqrt(R);
    for (long long int i = 2; i * i <= R; i++)
    {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        {
            isPrime[j - L] = false;
        }
    }
    if (L == 1)
    {
        isPrime[0] = false;
    }
    for (int i = 0; i <= R - L; i++)
    {
        if (isPrime[i])
        {
            cout << i + L << " ";
        }
    }

}