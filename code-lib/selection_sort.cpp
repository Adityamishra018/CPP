#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	cout << "Enter number of elements: \n";
	int N; cin >> N;
	vector<int> a(N);
	int i, j, min_idx;
	
	cout << "Enter elements of array: \n";
	for(i = 0; i < N; i++){
		cin >> a[i];
	}
	
	for(i = 0; i < N; i++){
		min_idx = i;
		for(j = i + 1; j < N; j++){
			if(a[j] < a[min_idx])
				min_idx = j;             
		}
		swap(a[i], a[min_idx]);         
	}
	
	for(i = 0; i < N; i++)
		cout << a[i] << " ";
}