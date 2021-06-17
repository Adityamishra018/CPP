#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000
int n;
vector<int> BIT(SIZE, 0);

void add(int index, int delta){
  for(++index; index<=n; index+= (index&(-index))){
    BIT[index]+=delta;
  }
}

int sum(int index){
  int res=0;
  for(++index; index>0; index -= (index&(-index))){
    res += BIT[index];
  }

  return res;
}

int range_sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

int main(){
   cin>>n;
   vector<int> a(n);

   for(int i=0; i<n; i++){
    cin>>a[i];
    add(i, a[i]);
   }

   int q;
   cin>>q;
   while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
   
      int l;
      cin>>l;
      int newVal;
      cin>>newVal;
      add(l, newVal-a[l]);
    }else if(ch==2){
     
      int l, r;
      cin>>l>>r;

      cout<<range_sum(l, r)<<"\n";
    }
   }

   return 0;
}

/*
SAMPLE INPUT
5
1 2 3 4 5
4
1 1 3
2 2 4
1 3 3
2 0 3
OUTPUT
12
10
*/
