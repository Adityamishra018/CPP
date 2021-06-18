#include<iostream>
#include<vector>

int countPrimes(int n) {
        int cnt=0;
        std::vector<int> vec(n,1);
        for(int i=2;i<n;i++){
            if(vec[i]==1){
                cnt++;
                for(int j=2;j*i<n;j++){
                    if(vec[j*i]==1)
                        vec[j*i] = 0;
                }
            }
        }
        return cnt;
    }

int main(){
    std::cout<<countPrimes(10);
}