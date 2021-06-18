#include <iostream>
using namespace std;

int main() {
	int t,x,flag;
	long n;
	cin>>t;
	
	while(t--){
	    cin>>n;
	    flag = 0;
	    do{
    	    x = n%10;
    	    if(x == 7 || x == 3 ){
    	        n /= 10;
    	    }
    	    else{
    	        flag = 1;
    	        break;
    	    }
	    }while(n);
	    
	    if(flag == 0)
	      printf("LUCKY\n");
	    else
	      printf("BETTER LUCK NEXT TIME\n");
	}
	
	
	return 0;
}
