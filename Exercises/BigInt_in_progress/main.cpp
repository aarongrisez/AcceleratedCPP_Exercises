
#include "BigInt.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
	char x[12];
	cout << numeric_limits<long long int>::max() << endl;
	cout << "Enter a numeric string" << endl;
	cin.getline(x, 12);
	BigInt* largeInteger = new BigInt(x);
	BigInt* largeInteger2 = new BigInt(x);
	*largeInteger += *largeInteger2;
	return 0;
}