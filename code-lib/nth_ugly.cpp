# include<stdio.h> 
# include<stdlib.h> 
int maxDivide(int a,int b);

int isUgly(int num) 
{ 
  num = maxDivide(num, 2); 
  num = maxDivide(num, 3); 
  num = maxDivide(num, 5); 
    
  if(num==1)
  return 1;
  else return 0;
}     

int maxDivide(int a, int b) 
{ 
  while (a%b == 0) 
   a = a/b;  
  return a; 
}     


int getNthUglyNo(int n) 
{ 
  int i = 1;  
  int count = 1;  
  

  while (n > count) 
  { 
    i++;       
    if (isUgly(i)) 
      count++;  
  } 
  return i; 
} 

int main() 
{ 
    int n;
    scanf("%d",&n);
    unsigned no = getNthUglyNo(n); 
    printf("%dth ugly no. is %d ",n,no); 
    getchar(); 
    return 0; 
}