#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> &temp){
    
    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}
void helper(int input[],int n,vector<int> &temp){
    
    if(n==0){
        printVector(temp);
        return;
    }
    
    temp.push_back(input[0]);
    helper(input+1,n-1,temp);
    
    temp.pop_back();
    helper(input+1,n-1,temp);
}


void printSubsetsOfArray(int input[], int size) {
    vector<int>temp;
    
    helper(input,size,temp);
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}