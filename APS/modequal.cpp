#include <iostream>
typedef unsigned long long int ll;
using namespace std;

ll factorsLessThan(ll x,ll k){
    ll i = 1;
    ll cntr = 0;
    while(i*i < x){
        if((x%i == 0) && i<k){
          cntr++;
          if((x/i != i) && (x/i < k))
             cntr++;
        }
        i++;
    }
    return cntr;
}

int main() {
	ll t,n,m;
	ll a,y;
	ll ans;

	scanf("%uld",&t);
	for(ll i=0;i<t;++i){
	   scanf("%uld%uld",&n,&m);
	   ans = 0;
	   for(ll j=n; j>1;--j){
	       y = m%j ;
	       ans += factorsLessThan(m-y,j);
	   }
	   printf("%uld\n",ans);
	}
	return 0;
}
