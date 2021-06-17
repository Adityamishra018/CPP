  
#include<bits/stdc++.h>
using namespace std;
bool checkBalanced(string s){
	
    stack<char> st; 
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() || st.top()!='('){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]=='}'){
            if(st.empty() || st.top()!='{'){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==']'){
            if(st.empty() || st.top()!='['){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    
    if(!st.empty()){
        return false;
    }
    
    return true;
}
int main()
{
	string s;
    cin>>s;
    if(checkBalanced(s)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
}