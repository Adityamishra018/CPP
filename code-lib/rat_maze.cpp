#include<iostream>
using namespace std;

bool ratInaMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
	if (i == m and j == n) {
		soln[m][n] = 1;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}

	if (i > m or j > n) {
		return false;
	}
	if (maze[i][j] == 'X')
	{
		return false;
	}

	soln[i][j] = 1;
	bool rightsuccess = ratInaMaze(maze, soln, i, j + 1, m, n);
	bool downsuccess = ratInaMaze(maze, soln, i + 1, j, m , n );

	soln[i][j] = 0;

	if (rightsuccess or downsuccess)
		return true;

	return false;
}




int main() {

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int soln[10][10] = {0};
	int n = 4, m = 4;
	bool ans = ratInaMaze(maze, soln, 0, 0, m - 1, n - 1);
	if (!ans)
		cout << "Path doesn't exist" << endl;
	return 0;

}