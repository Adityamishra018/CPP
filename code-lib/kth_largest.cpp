#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    int N = nums.size();
    for (auto &elem : nums) {
        pq.push(elem);
    }
    k -= 1;
    while (k--) {
        pq.pop();
    }
    cout << pq.top() << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
    
    int k;
    cin >> k;

	findKthLargest(input,2);
	return 0;
}

/*
Sample Input:
--------------------
6
3 2 1 5 6 4
2
Sample Output:
--------------------
5
 */