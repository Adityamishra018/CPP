#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>

typedef unsigned long long int ull;

int main(){

   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);

   ull num=1,b,c,x;
   long double a,t,ans;

   std::cout.setf(std::ios::fixed, std::ios::floatfield);
   std::cout.precision(17);
   scanf("%Le%llu%llu",&a,&b,&c);

   if(a<=1){
	  ans = log2(1+b*c);
      if(std::modf(ans,&t) == 0.0)
        std::cout<<long(ans);
      else
        std::cout<<ans;
   }
   else if(a>b){
	  ans = c*log2(a);
      if(std::modf(ans,&t) == 0.0)
        std::cout<<long(ans);
      else
        std::cout<<ans;
   }
   else{
       x = ceil((1+b-a)/(b*(a-1)));
       ans = log2(1+(x*b)) + (c-x)*log2(a);
       if(std::modf(ans,&t) == 0.0)
        std::cout<<long(ans);
       else
        std::cout<<ans;
   }
   return 0;
}
