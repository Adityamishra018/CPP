#include <iostream>
using namespace std;

int recursive_approach(int x, int y) {

	if (y == 0) {
		return x;
	}
	else {
		return recursive_approach(y, x % y);
	}
}

int non_recursive_approach(int x, int y) {
	while (y) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int main() {
    int first_number, second_number;
    cin >> first_number >> second_number;
	cout << recursive_approach(first_number, second_number) << endl;
	cout << non_recursive_approach(first_number, second_number) << endl;
	return 0;
}

/*
Sample Input:
--------------------
1188 220
Sample Output:
--------------------
44
44
 */