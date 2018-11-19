
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

int BigInt::addDigit(vector<int>::reverse_iterator it, BigInt rhs) {
	// i is the INDEX of the digit, with the end of the vector being the rightmost place
	cout << *it << endl;
	cout << rhs.stringRepresentation << endl;
	return 0;
}

BigInt& BigInt::operator+= (const BigInt& rhs) {
	cout << "Adding" << endl;
	for (vector<int>::reverse_iterator it = this->integerVector.rbegin(); it != this->integerVector.rend(); ++it) {
		// Iterate backwards through the vector
		this->addDigit(it, rhs);
	}
	return *this;
}

BigInt& BigInt::operator-= (const BigInt& rhs) {
	return *this;
}

BigInt& BigInt::operator*= (const BigInt& rhs) {
	return *this;
}

BigInt& BigInt::operator/= (const BigInt& rhs) {
	return *this;
}