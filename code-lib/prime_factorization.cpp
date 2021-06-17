#include <bits/stdc++.h>

using namespace std;
vector<int> prime_factorise(int n){
    vector<int> factors;

    while(n%2 == 0){
        n >>= 1;
        factors.push_back(2);
    }
 
    for(int i=3 ; 1LL * i * i <= (long long)n ; i += 2){
        while(n%i == 0){
            n /= i;
            factors.push_back(i);
        }
    }
    if(n > 1) factors.push_back(n);

    return factors;
}

void print(int n, vector<int> &a){

    cout<<"The factorisation of "<<n<<" is -\n";
    for(int i : a) cout<<i<<' ';
    cout<<"\n";
    return;
}

int main(){
    int example1 = 500;
    int example2 = 45630;

    vector<int> ans1 = prime_factorise(example1);
    print(example1, ans1);

    vector<int> ans2 = prime_factorise(example2);
    print(example2, ans2);
    
    return 0;
}