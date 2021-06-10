#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int getScore(string &str){
    int cnt;
    if(str[0]== 'W')
        cnt = 1;
    for(int i=1;i<str.size();++i){
        if(str[i] == 'W' && str[i-1]=='W')
            cnt += 2;
        else if(str[i] == 'W')
            cnt += 1;
    }
    return cnt;
}

int countLs(string &str){
    int cnt;
    for(auto i : str)
      if(i == 'L')
        cnt += 1;
    return cnt;
}

int main() {
	string str;
	int t,k,n,i,j,cnt,p,q;

	scanf("%d",&t);
	for(int j=0;j<t;++j){
	    scanf("%d%d",&n,&k);
	    cin>>str;
	    i = str.size()-1;
	    cnt = 0;
	    while(k > 0 && i > 0){
	        if(str[i] == 'W' && str[i-1] == 'L' ){
	            k -= 1;
	            str[i-1]='W';
	            i--;
	        }
	        else if(str[i] == 'L' && str[i-1] == 'W'){
	            k -= 1;
	            str[i] = 'W';
	            i--;
	        }
	        else
                i--;
	    }
        q = getScore(str);
	    if(k>0){
	        p = countLs(str);
	        if(k > p){
	            q += p;
	        }
	        else{
	            q += k;
	        }
	    }

	    printf("%d\n",q);
	}
	return 0;
}
