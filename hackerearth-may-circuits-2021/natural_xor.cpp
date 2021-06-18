#include <cstdio>
#include <iostream>
#include <vector>
 
int main(){
   int t,k=0,r;
   long n;
 
   scanf("%d",&t);
   for(int i=0;i<t;++i){
       scanf("%ld",&n);
       if(n % 4 == 0){
         printf("1 %ld\n",n);
         continue;
       }
       r = n % 4;
       if(r==3){
         printf("0\n");
       }
       else if(r==2){
         printf("2 %ld 1\n",n);
       }
       else if(r == 1){
         printf("1 1\n");
       }
       else
       {
         printf("1 0\n");
       }
   }
}