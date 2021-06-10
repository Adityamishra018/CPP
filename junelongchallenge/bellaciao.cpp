#include <iostream>
using namespace std;

int main() {
	long d,D,P,Q,t,sum;
	
	cin >> t;
	
	while(t--){
	    cin>>D>>d>>P>>Q;
	    sum = P*(D/d)*d + ((Q*((D/d)-1)*(D/d)/2) * d)+ (D%d)*(P + (D/d)*Q); 
	    cout<<sum<<"\n";
	}
	return 0;
}
