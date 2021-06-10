#include <cstdio>
#include <iostream>
int cntWinner(char arr[9]){
   int ret=0;
   //check for X
   for(int i=0;i<9;i += 3){
       if((arr[i] == 'X' )&& (arr[i] == arr[i+1]) && (arr[i+1] == arr[i+2])){
           ret++;
           break;
       }
       else{
           if(i==0){
               if((arr[0] == 'X' ) && (arr[4] == 'X' ) && (arr[8] == 'X' )){
                   ret++;
                   break;
               }
               else if((arr[0] == 'X' ) && (arr[3] == 'X' ) && (arr[6] == 'X')){
                   ret++;
                   break;
               }
           }
           else if(i == 3){
               if((arr[1] == 'X' ) && (arr[4] == 'X' ) && (arr[7] == 'X')){
                   ret++;
                   break;
               }
           }
           else if(i == 6){
               if((arr[2] == 'X' ) && (arr[4] == 'X' ) && (arr[6] == 'X' )){
                   ret++;
                   break;
               }
               else if((arr[2] == 'X' ) && (arr[5] == 'X' ) && (arr[8] == 'X')){
                   ret++;
                   break;
               }
           }
       }
   }

   //check for O
   for(int i=0;i<9;i += 3){
       if((arr[i] == 'O' )&& (arr[i] == arr[i+1]) && (arr[i+1] == arr[i+2])){
           ret+=2;
           break;
       }
       else{
           if(i==0){
               if((arr[0] == 'O' ) && (arr[4] == 'O' ) && (arr[8] == 'O' )){
                   ret+=2;
                   break;
               }
               else if((arr[0] == 'O' ) && (arr[3] == 'O' ) && (arr[6] == 'O')){
                   ret+=2;
                   break;
               }
           }
           else if(i == 3){
               if((arr[1] == 'O' ) && (arr[4] == 'O' ) && (arr[7] == 'O')){
                   ret+=2;
                   break;
               }
           }
           else if(i == 6){
               if((arr[2] == 'O' ) && (arr[4] == 'O' ) && (arr[6] == 'O' )){
                   ret+=2;
                   break;
               }
               else if((arr[2] == 'O' ) && (arr[5] == 'O' ) && (arr[8] == 'O')){
                   ret+=2;
                   break;
               }
           }
       }
   }
   return ret;
}

int main(void) {
	int t,wcnt;
	char arr[12];
	char x;
	scanf("%d ",&t);

	for(int k=0;k<t;++k){
	    for(int i=0;i<9;i+=3){
            scanf("%c %c %c",&arr[i],&arr[i+1],&arr[i+2]);
            getchar();
	    }

	    arr[9] = arr[10] = arr[11] = 0;

	    for(int i= 0;i<9;++i){
	       if(arr[i] == 'X')
	            arr[9] +=1;
	       else if(arr[i] == 'O')
	            arr[10] += 1;
	       else
	            arr[11] += 1;
	    }

	    if((arr[9] - arr[10]) == 1 || (arr[9] == arr[10])){
	        wcnt = cntWinner(arr);
	        if( (wcnt == 0) && (arr[11] == 0))
	            printf("1\n");
	        else if( (wcnt == 0) && (arr[11] != 0)){
	            printf("2\n");
	        }
	        else if(wcnt == 1 && (arr[9] - arr[10] == 1)){
	            printf("1\n");
	        }
	        else if(wcnt == 1 && (arr[9] == arr[10])){
	            printf("3\n");
	        }
	        else if(wcnt == 2 && (arr[9] == arr[10])){
	            printf("1\n");
	        }
	        else if(wcnt == 2 && (arr[9] - arr[10])==1){
	            printf("3\n");
	        }
	        else if(wcnt == 3){
	            printf("3\n");
	        }
	    }
	    else
	      printf("3\n");
	}
	return 0;
}

