
#include "BigInt.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
	string x;
	cout << numeric_limits<long long int>::max() << endl;
	cout << "Enter a numeric string" << endl;
	cin >> x;
	BigInt* largeInteger = new BigInt(x);
	largeInteger = largeInteger + 1;
	cin >> x;
}