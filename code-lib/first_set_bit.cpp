#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
       unsigned int v=log2(n&-n)+1;
       cout<<v<<'\n';
	    
    } 
	        
	return 0;
}