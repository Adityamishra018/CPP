#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000000
#define K 25

int min(int a,int b){
   if(a<b)
    return a;
   return b;
}

int main(){
    int *log = (int *)malloc((MAXN+1)*sizeof(int));
    int *arr = (int *)malloc((MAXN+1)*sizeof(int));
    int **st;

    st = (int **)malloc(MAXN*sizeof(int*));
    for(int i=0;i<MAXN;++i){
        *(st+i) = (int*)malloc((K+1)*sizeof(int*));
    }

    int n,q;
    int L,R;

    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        log[i] = log[i/2] + 1;


    for (int i = 0; i < n; i++)
        *(*(st+i)+0) = arr[i];

    for (int j = 1; j <= K; j++)
       for (int i = 0; i + (1 << j) <= n; i++)
           *(*(st+i)+j) = min(*(*(st+i)+j-1), *(*(st+i+(1 << (j - 1))+j-1)));


    int j;
    for(int i=0;i<q;++i){
        scanf("%d%d",&L,&R);
        j = log[R - L + 1];
        printf("%d\n",min(*(*(st+L)+j), *(*(st+R - (1 << j) + 1)+j)));
    }

    return 0;
}
