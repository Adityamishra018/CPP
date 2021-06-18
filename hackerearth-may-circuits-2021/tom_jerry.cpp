#include<iostream>
#include<cstdio>
#include<vector>

int main(){

    long m,n,x,i,r1,r2,c1,c2,k;
    int q;
    int type;

    scanf("%ld%ld%ld%d",&m,&n,&x,&q);

    std::vector<long> cnt(m+n-1);

    if(m==n){
        i =0;
        while(i<n){
            cnt[i]=i+1;
            ++i;
        }
        while(i<m+n-1){
            cnt[i] = n+m-1-i;
            ++i;
        }

    }
    else if(m>n){
        i =0;
        while(i<n){
            cnt[i] = i+1;
            ++i;
        }
        while(i<(m+n-1)){
            cnt[i] = (m+n-1-i)>=n ? n :(m+n-1-i);
            ++i;
        }
    }
    else{
        i =0;
        while(i<n){
            if(i<m-1)
                cnt[i] = i+1;
            else
                cnt[i] = m;
            ++i;
        }
        while(i<m+n-1){
            cnt[i] = (m+n-1-i);
            ++i;
        }

    }

    while(q--){
        scanf("%d",&type);
        switch(type){
            case 1:

                scanf("%ld%ld%ld",&r1,&c1,&c2);
                for(i=c1;i<=c2;++i){
                    cnt[r1+i-2] -= 1;
                }
                break;

            case 2 :

                scanf("%ld%ld%ld",&c1,&r1,&r2);
                for(i=r1;i<=r2;++i){
                    cnt[c1+i-2] -= 1;
                }
                break;

            case 3:
                scanf("%ld",&k);
                i=-1;
                while(k>0){
                    if(cnt[++i] !=0){
                        --k;
                    }
                }
                printf("%ld\n",x+i+2);
                break;
        }
    }
}
