
#include "BigInt.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
	char x[12];
	char y[12];
	cout << numeric_limits<long long int>::max() << endl;
	cout << "Enter a numeric string" << endl;
	cin.getline(x, 12);
	BigInt* largeInteger = new BigInt(x);
	cout << "Enter a numeric string" << endl;
	cin.getline(y, 12);
	BigInt* largeInteger2 = new BigInt(y);
	*largeInteger += largeInteger2;
	for (vector<int>::const_iterator it = largeInteger->integerVector.begin(); it != largeInteger->integerVector.end(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 0;
}