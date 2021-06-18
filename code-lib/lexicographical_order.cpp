#include <iostream>
#include <string>
using namespace std;

void help(int x,int n){
    
    if(x>n)
        return;
    for(int i=0;i<=9;i++){
        x=x*10+i;
        if(x==0)
            continue;
        if(x<=n)
            cout<<x<<endl;
        help(x,n);
        x=(x-i)/10;
    }
    
}


void lexicographicalOrder(int num){
    int x=0;
    help(x,num);

}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}