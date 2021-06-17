#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_DIGIT_LENGTH = 200;


void FactorialOfLargeNumber(const int N) {

    vector<int> product(MAX_DIGIT_LENGTH);

 
    product[0] = 1;

    int digitLength = 0;
    for (int i = 1; i < N + 1; ++i) {

        int carry = 0;

       
        for (int j = 0; j <= digitLength; ++j) {

            product[j] *= i;


            product[j] += carry;


            carry = product[j] / 10;

            product[j] %= 10;
        }

        while (carry) {

            ++digitLength;
            product[digitLength] = carry % 10;
            carry /= 10;
        }   
    }
    
    for (int i = digitLength; i >= 0; --i) {
        cout << product[i];
    }
    cout << endl;
}

int main() {
    int input;
    cin >> input;
    assert(("Input should be at least 0.", input >= 0));
    FactorialOfLargeNumber(input);
    return 0;
}

/*
Sample Input:
--------------------
30
Sample Output:
--------------------
265252859812191058636308480000000
 */