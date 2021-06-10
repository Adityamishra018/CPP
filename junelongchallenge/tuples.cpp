#include<iostream>
#define ll long long

using namespace std;

int checkprod(int a,int b){
    return 0;
}

int valuefor(){
    return 0;
}

ll raiseto(ll x,ll y,ll p){
    ll ans = 1;
    x = x% p;
    while(y>0){
        if(y&1){
            ans = (ans*x) % p;
        }
        y = y>>1;
        x = (x*x) %p;

    }
    return ans;
}

int main(){
    ll x,y,r,ret;
    int t;

    cin>>t;
    while(t--){
        cin>>x>>y;
        r = raiseto(2,x,1000000007) - 1;
        ret = raiseto(r,y,1000000007);
        cout<<ret<<"\n";
    }
    return 0;
}