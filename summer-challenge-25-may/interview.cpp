#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	getchar();
	string str;
	std::size_t found;
	while(t--){
		getline(cin,str);
        //found = str.find("CoDe");
        if(std::count(str.begin(),str.end(),'C') >= 1 && std::count(str.begin(),str.end(),'e') >= 1  && std::count(str.begin(),str.end(),'D') >= 1 && std::count(str.begin(),str.end(),'o') >= 1  ){
        	if(std::count(str.begin(),str.end(),'e') >= 1 && std::count(str.begin()+1,str.end()-1,'E') >= 1)
        		  cout<<"SELECTED\n";
        	else
        		cout<<"REJECTED\n";
        }
		
	}
}