#include <iostream>
#include <vector>
using namespace std;

int KnapsackProblem(vector<int> const &values, vector<int> const &weights, const int noOfElements, const int maxCapacity) {

	int memo[noOfElements + 1][maxCapacity + 1];

	for (int i = 0; i <= noOfElements; ++i) {
		for (int j = 0; j <= maxCapacity; ++j) {

			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}

			
			else if (weights[i - 1] <= j) {
				memo[i][j] = max(values[i - 1] + memo[i - 1][j - weights[i - 1]], memo[i - 1][j]);
			}

			else {
				memo[i][j] = memo[i - 1][j];
			}
		}
	}

	return memo[noOfElements][maxCapacity];
}

int main() {
	int noOfElements;
	cin >> noOfElements;
	vector<int> values(noOfElements), weights(noOfElements);


	for (int i = 0; i < noOfElements; ++i)
		cin >> values[i];

	for (int i = 0; i < noOfElements; ++i)
		cin >> weights[i];

	int maxCapacity;
	cin >> maxCapacity;

	cout << KnapsackProblem(values, weights, noOfElements, maxCapacity) << endl;
	return 0;
}

/*
Sample Input:
--------------------
5
50 120 110 70 40
5 40 50 20 10
80
Sample Output:
--------------------
280
 */