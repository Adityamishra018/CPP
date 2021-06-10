#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
    int t,n,a[53];
    cin>>t;

    while(t--){
        cin>>n;
        n*=2;

        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        std::sort(a+1,a+n+1);

        for(int i=2;i<=n/2;i+=2){
            std::swap(a[i],a[n+1-i]);
        }
        for(int i=1;i<=n;++i){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    

}