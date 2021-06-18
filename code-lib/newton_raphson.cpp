#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void squareRoot(int number){

   double x, root;

   x = number;       

   while(1){
     
     root = (x + number/x)/2;      
     if(abs(root - x) < 0.0001)  
         break;

     x = root;
   }

   cout<<root;
}

int main(){
	system("cls");
	int n;

	cout<<"enter a number: ";
	cin>>n;
	fflush(stdin);
	squareRoot(n);
	getchar();
	return 0;
}