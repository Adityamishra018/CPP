#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>

typedef std::pair<long long ,long long> pairs;

int main(){
    long long s,l,x;
    long double h,temp;
    int t;

    std::set<std::pair<long long,long long> > sol;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&x);
        s = x*x;
        l = (x*x - 1)/2;
        l += 1;
        sol.clear();

        for(long long int i=1;i<l+1;++i){
            h = sqrt(i*i + s);
            if(std::modf(h,&temp) == 0){
                if(i>h){
                    pairs x = std::make_pair(h,i);
                    sol.insert(x);

                }
                else{
                    pairs x = std::make_pair(i,h);
                    sol.insert(x);
                }
            }
        }

        l = x / 1.414;
        l+=1;

        for(long long int i = 1;i<l+1;++i){
            h = sqrt(s-(i*i));
            if(std::modf(h,&temp) == 0 && h != 0){
                if(i>h){
                    pairs x = std::make_pair(h,i);
                    sol.insert(x);

                }
                else{
                    pairs x = std::make_pair(i,h);
                    sol.insert(x);
                }
            }

        }

        printf("%lld\n",sol.size());
    }
}
