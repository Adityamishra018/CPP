#include <iostream>
using namespace std;
long long memo[100];
long long fab(long long n){
  if (n==2)
  return 1;
  else{
    if (n==1)
     return 0;
     else{
       if (memo[n]==0)
      { memo[n]= (fab( n-1)+fab(n-2));
      }
      return memo[n];
    }  } }


int main()
{ long long n=5;
  cout << fab(n);
}