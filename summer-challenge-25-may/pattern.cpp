#include <iostream>
using namespace std;

void printn(int n){
	for(int i=0;i<n-1;++i)
		cout<<"*";
	cout<<n;
}

void printPattern(int n){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)
			printn(j);
		cout<<"\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t,n;
	cin>>t;

	while(t--){
		cin>> n;
        printPattern(n);
        cout<<"\n";
	}
	return 0;
}