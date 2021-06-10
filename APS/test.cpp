#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,x,a,b,s;
	cin>>t;
	while(t--){
	    cin>>x>>a>>b;
	    s=10*(a+(b*(100-x)));
	    cout<<s<<endl;
	}
	return 0;
}
