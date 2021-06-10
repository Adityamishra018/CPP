#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

int solver(int arr[],int size,int *ret){
  int max,curr,mstart,mend,start,end;
  int cntr=0;

  max = INT_MIN;
  curr = 0;

  for(int i=0;i<size;++i){

    if(curr + arr[i] > 0){
        curr = curr + arr[i];
        cntr++;
    }
    else{
        curr = curr + arr[i];
    }

    if(curr > max){
        max = curr;
        mend = i;
        mstart = mend-cntr+1;
    }

    if(curr < 0){
        curr = 0;
        cntr = 0;
    }
  }

  ret[0] = max;
  ret[1] = mstart;
  ret[2] = mend;

  return ret[0];
}

int main(){
    int arr[8] = {2,-9,4,-1,-2,1,5,-3};
    int ret[3] = {0};

    printf("%d\n",solver(arr,8,ret));

    for(int i=ret[1];i<=ret[2];++i){
        arr[i] = 0;
    }

    printf("%d \n",solver(arr,8,ret));
    return 0;
}
