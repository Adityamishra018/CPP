#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        long long total_0=0,total_1=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='1'){
                total_1++;
            }
            else{
                total_0++;
            }
        }
        vector<long long> factors;
        for(long long i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(n/i==i){
                    factors.push_back(i);
                }
                else{
                    factors.push_back(n/i);
                    factors.push_back(i);
                }
            }
        }
        long long ans = 1e9;
        for(auto fact:factors){
            vector<long long> freq(fact);
            for(long long i=0;i<fact;i++){
                for(long long j=i;j<n;j+=fact){
                    if(s[j]=='1'){
                        freq[i]++;
                    }
                }
            }
            long long req=n/fact;
            for(long long i=0;i<fact;i++){
                long long to_convert=req-freq[i];
                to_convert+=(total_1-freq[i]);
                ans=min(ans,to_convert);
            }

        }
        cout<<ans<<endl;
    }
}