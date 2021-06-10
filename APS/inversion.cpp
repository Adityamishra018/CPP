#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

int main(){
    ull n,a,flag=0;
    ull x;

    scanf("%llu%llu%llu",&n,&a,&x);

    ull bubble = 0;
    ull start = a-1;

    if(x <= (n-a)*a){

            while( (start+x) > (n-1)-bubble){
                //printf("\nstart = %d, x = %d, bubble = %d",start,x,bubble);
                x -= (n-1-bubble)-start;
                bubble++;
                start--;
            }

            for(ull i=0;i<start;++i){
                printf("0 ");
                flag++;
            }

            if(flag > 0){
                for(ull i=0;i<x;++i)
                    printf("1 ");
            }
            else{
                printf("0 ");
                for(ull i=0;i<x;++i)
                    printf("1 ");
            }
            printf("0 ");

            for(ull i=0; i<((n-1-bubble)-(start+x));++i)
                printf("1 ");
            for(ull i=0;i<bubble;++i)
                printf("0 ");
    }
    else
        printf("-1");
}
