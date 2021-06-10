#include <iostream>
using namespace std;

int main() {
	long d,D,P,Q,t,sum;
	
	cin >> t;
	
	while(t--){
	    cin>>D>>d>>P>>Q;
	    sum = 0;
	    for(long i=0;i<D;i+=d,P+=Q){
	        if(i + d <= D)
	            sum += P*d;
	        else
	            sum += P*(D-i);
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
