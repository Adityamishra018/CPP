#include<cstdio>
#include<iostream>
#include<cmath>


long func1(long a,long d,long x){
    long double n;
    n = ((x-a)/d) + 1;
    if((n-1)*d == (x-a))
        return n;
    return n + 1;
}

long func2(long a,long d,long x){
    return ceil(((x-a)/d));
}

int main(){
  long l,r,cnt,a,n1,n2;
  int t;

  scanf("%d",&t);
  for(;t>0;t--){
      scanf("%ld%ld",&l,&r);
      cnt=0;
      for(long i=1;i<ceil(sqrt(r));++i){

        a = i*i;
        n1=0;
        n2=0;
        if(l>=a)
            n1 = func1(a,2*i,l);
        if(r>=a)
            n2 = func2(a,2*i,r);
        else
            break;
        cnt += (n2-n1);
        if(n1 != 0)
            cnt+=1;
      }
      printf("%ld\n",cnt);
  }
}
