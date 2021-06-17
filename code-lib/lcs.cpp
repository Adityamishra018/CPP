#include <iostream>
#include <vector>
using namespace std;

void LongestCommonSubsequence(string const &firstString, string const &secondString) {

	int M = firstString.length(), N = secondString.length();

	vector<vector<int> > memo(M + 1, vector<int>(N + 1));
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}

			else {

				if (firstString[i - 1] == secondString[j - 1]) {
					memo[i][j] = memo[i - 1][j - 1] + 1;
				}

				else {
					memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
				}
			}
		}
	}

	int lengthOfLCS = memo[M][N];
	string resultantLCS = "\0";

	int i = M, j = N;
	while (i > 0 && j > 0) {

		if (firstString[i - 1] == secondString[j - 1]) {

		
			resultantLCS = firstString[i - 1] + resultantLCS;
			--i; --j;
		}
		else {
			if (memo[i - 1][j] > memo[i][j - 1]) {

				--i;
			}
			else {

				--j;
			}
		}
	}

	cout << "Length of LCS: " << lengthOfLCS << endl;
	cout << "Resultant LCS: " << resultantLCS << endl;
}

int main() {
	string firstString, secondString;
	cin >> firstString >> secondString;
	LongestCommonSubsequence(firstString, secondString);
	return 0;
}

/*
Sample Input:
--------------------
SAFOWAQMNXQOA
ESPOFNSSXAOQA
Sample Output:
--------------------
Length of LCS: 6
Resultant LCS: SONXOA
 */