#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	char str[100];
	cin.getline(str,100);

	int cnt=0;
	int len = strlen(str);

	//first chance
	if(str[0] > str[len-1])
        cnt += 123 - str[0];
    else
        cnt += 123 - str[len-1];

	for(int i=1;i<len/2;++i){
	    if(str[i] > str[len-1-i])
	      cnt += 123 - str[len-i-1];
	    else
	      cnt += 123 - str[i];
	}

	if(len % 2 == 1 && len >= 7)
        cnt += 123 - str[len/2];

	printf("%d",cnt);
	return 0;
}
