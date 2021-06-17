#include <iostream>
#include <vector>
using namespace std;

int MaximumContiguousSubsequenceSum(vector<int> const &a, const int noOfElements) {

	int memo = a[0];
	int sum = memo;
	
	for (int i = 1; i < noOfElements; ++i) {

		memo = max(a[i], memo + a[i]);
		sum = max(sum, memo);
	}
	return sum;
}

int main() {
	int noOfElements;
	cin >> noOfElements;
	vector<int> a(noOfElements);
	for (int i = 0; i < noOfElements; ++i) {
		cin >> a[i];
	}
	cout << MaximumContiguousSubsequenceSum(a, noOfElements);
	return 0;
}

/*
Sample Input:
--------------------
7
20 -17 34 11 -5 20 -5 2
Sample Output:
--------------------
63
 */