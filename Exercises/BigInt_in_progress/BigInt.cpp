
#include "BigInt.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

BigInt::BigInt() {
	this->stringRepresentation = "";
	this->integerVector = { 0 };
	this->carryValue = 0;
	this->isNegative = false;
}

BigInt::BigInt(string stringRepresentation) {
	this->stringRepresentation = stringRepresentation;
	string::const_iterator negative = find(stringRepresentation.begin(), stringRepresentation.end(), '-');
	if (negative == stringRepresentation.end()) {
		cout << "Not Negative" << endl;
		this->isNegative = false;
	}
	else {
		this->isNegative = true;
	}
	string::const_iterator decimal = find(stringRepresentation.begin(), stringRepresentation.end(), '.');
	for (int i = 0; i < stringRepresentation.size(); i++) {
		cout << (int)stringRepresentation[i] - 48 << endl;
		this->integerVector.push_back((int)stringRepresentation[i] - 48);
	}
	this->carryValue = 0;
}

BigInt& BigInt::operator+= (BigInt* rhs) { 
	cout << "Adding" << endl;
	vector<int>::reverse_iterator rhsMarker = rhs->integerVector.rbegin();
	for (vector<int>::reverse_iterator it = this->integerVector.rbegin(); it != this->integerVector.rend(); ++it) {
		// Iterate backwards through the vector

		// Case 1: Same size
		if (rhsMarker != rhs->integerVector.rend()) {
			cout << "rhs " << *rhsMarker << endl;
			cout << "lhs " << *it << endl;
			++rhsMarker;
		}
		// Case 2: Second int shorter (i.e.: lhs has more digits)
		else if (rhsMarker == rhs->integerVector.rend()) {
			cout << "case 2, lhs " << *it << endl;
		}
	}
	// Case 3: Second int string longer (i.e.: rhs has more digits)
	while (rhsMarker != rhs->integerVector.rend()) {
		cout << "case 3, lhs " << *rhsMarker << endl;
		++rhsMarker;
	}
	return *this;
}

BigInt& BigInt::operator-= (const BigInt* rhs) {
	return *this;
}

BigInt& BigInt::operator*= (const BigInt* rhs) {
	return *this;
}

BigInt& BigInt::operator/= (const BigInt* rhs) {
	return *this;
}