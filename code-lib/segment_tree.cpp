#include <bits/stdc++.h> 
using namespace std; 
 
int getMid(int s, int e) { 
    return s + (e -s)/2; 
} 

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) 
{
	if (qs <= ss && qe >= se) 
		return st[si]; 
 
	if (se < qs || ss > qe) 
		return 0; 
		
	int mid = getMid(ss, se); 
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
		getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) 
{ 

	if (i < ss || i > se) 
		return; 
 
	st[si] = st[si] + diff; 
	if (se != ss) 
	{ 
		int mid = getMid(ss, se); 
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
		updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
	} 
} 
 
void updateValue(int arr[], int *st, int n, int i, int new_val) 
{ 

	if (i < 0 || i > n-1) 
	{ 
		cout<<"Invalid Input"; 
		return; 
	} 

	int diff = new_val - arr[i]; 

	arr[i] = new_val; 

	updateValueUtil(st, 0, n-1, i, diff, 0); 
} 

int getSum(int *st, int n, int qs, int qe) 
{ 

	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		cout<<"Invalid Input"; 
		return -1; 
	} 

	return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 

int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
 
	if (ss == se) 
	{ 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 
 
	int mid = getMid(ss, se); 
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + 
			constructSTUtil(arr, mid+1, se, st, si*2+2); 
	return st[si]; 
} 

int *constructST(int arr[], int n) 
{ 

	int x = (int)(ceil(log2(n))); 

	int max_size = 2*(int)pow(2, x) - 1; 

	int *st = new int[max_size]; 

	constructSTUtil(arr, 0, n-1, st, 0); 

	return st; 
} 
 
int main() 
{ 
    int *arr , n , i , a , b ;
    cout << "Enter size of the array" << endl ;
    cin >> n ;
    arr = new int[n] ;
    cout << "Enter the elements of the array" << endl ;
    for ( i = 0 ; i < n ; i++ )
        cin >> arr[i] ;
	int *st = constructST(arr, n); 
	int k = 1 ;
	do{
        cout << "Enter 1 to find the sum of the values in the given range" << endl ;
        cout << "Enter 2 to update a value in the array" << endl ;
        cout << "Enter 0 to exit" << endl ;
        cout << "Enter your choice" << endl ;
        int k ;
        cin >> k ;
        switch(k){
            case 1 : cout << "Enter the range" << endl ;
                     cin >> a >> b ;
                     cout<<"Sum of values in given range = "<<getSum(st, n, a, b)<<endl;
            break ;
            
            case 2 : cout << "Enter the position to be updated and number to be inserted" << endl ;
                     cin >> a >> b ;
                     updateValue(arr, st, n, a, b);
                     cout << "Updated array is : " ;
                     for ( i = 0 ; i < n ; i++ )
                        cout << arr[i] << " " ;
                     cout << endl ;
            break ;
             
            case 0 : exit(0) ;
        }
	}
	while (1);
 


	return 0; 
} 
