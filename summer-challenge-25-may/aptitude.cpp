#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long lcm(long a, long b)
{
    return (a / gcd(a, b)) * b;
}

int main(){
	long t,n,x;
	long k,val,ans;
	vector<int> vec(101);
	cin>>t;

	while(t--){
		cin>>n>>k;
		vec.erase(vec.begin(),vec.end());
		while(n--){
		    cin>>x;
			vec.emplace_back(x);
		}

        val = vec[0];
		for(int i=1;i<vec.size();++i){
			val = lcm(vec[i],val);
		}

        ans = k/val;
        cout<<ans<<"\n";
	}
}