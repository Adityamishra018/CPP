#include <iostream>
using namespace std;

int main() {
   for(int i=0;i<100;++i)
    if((i & (i+1))== 0)
        cout<<i<<"\n";

    return 0;
}