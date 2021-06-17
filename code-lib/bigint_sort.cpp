#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

bool customComparator(string a, string b) {
 
    if (a[0] == '-' && b[0] != '-') {
        return true;
    }

   
    if (a[0] != '-' && b[0] == '-') {
        return false;
    }
    if (a[0] == '-' && b[0] == '-') {
        if (a.length() == b.length()) {
            return a > b;
        }
        return a.length() > b.length();
    }

    
    if (a.length() == b.length()) {
        return a < b;
    }
  
    return a.length() < b.length();
}

int main() {
    int noOfNumbers;
    cin >> noOfNumbers;
    vector<string> BigIntegers;

    for (int i = 0; i < noOfNumbers; ++i) {
        string currNumber;
        cin >> currNumber;
        BigIntegers.push_back(currNumber);
    }

    sort(BigIntegers.begin(), BigIntegers.end(), customComparator);

    for (string number : BigIntegers) {
        cout << number << endl;
    }
    return 0;
}

/*
sample input
4
999999999999999999999999999
-999999999999999999999999999
56584811425369978558466998629
34183682863148623287364532568384314852

sample output
-999999999999999999999999999
999999999999999999999999999
56584811425369978558466998629
34183682863148623287364532568384314852
*/