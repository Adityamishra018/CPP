#include<iostream>
#include<vector>
#include<climits>

const int max_s = 1E5;
using namespace std;

int main(){

   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);std::cout.tie(NULL);

    int t,n,m,x,r,l,j;
    vector<int> as(max_s),bs(max_s),ms(max_s);
    cin >> t;

    while(t--){
        cin>>n>>m;
        as.erase(as.begin(),as.end());
        bs.erase(bs.begin(),bs.end());
        ms.erase(ms.begin(),ms.end());

        for(int i=0;i<n;i++){
            cin >>x;
            as.push_back(x);
            if(i==0)
                ms.push_back(0);
            else if(as[i] != 0)
                ms.push_back(0);
            else
                ms.push_back(INT_MAX);
        }

        for(int i=0;i<m;i++){
            cin >>x;
            bs.push_back(x);
        }

        r = -1;
        for(int i=0;i<as.size();++i){
           if(as[i]==1) 
                r=i;
           if(r!=-1){
               if(as[i]==0) ms[i]=min(ms[i],i-r);
           }
       }

       l  =-1; 
       for(int i=n-1;i>=0;i--){
           if(as[i]==2) 
                l=i; 
           if(l!=-1)
               if(as[i]==0) ms[i]=min(ms[i],l-i);
           
       }
       for(int i=0;i<bs.size();++i){
           j = bs[i]-1;
           if(ms[j]!=INT_MAX) 
                cout<<ms[j]<<" ";
           else cout<<-1<<" ";
       }
       cout<<"\n";
    }
}