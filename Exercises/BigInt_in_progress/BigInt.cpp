
#include "BigInt.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

BigInt::BigInt() {
	this->stringRepresentation = "";
	this->integerVector = { 0 };
}

BigInt::BigInt(string stringRepresentation) {
	this->stringRepresentation = stringRepresentation;
	vector<int> integerVector;
	for (string::const_iterator it = --stringRepresentation.end(); it != stringRepresentation.begin(); --it) {
		integerVector.push_back((int)*it);
	}
}

pair<int, int> BigInt::addDecimalPlace(int i, BigInt j) {
	return make_pair(0, 0);
}

BigInt& BigInt::operator+= (const BigInt& rhs) {
	cout << "Adding" << endl;
	for (vector<int>::const_iterator it = --this->integerVector.end(); it != this->integerVector.begin(); --it) {
		// Iterate backwards through the vector
		cout << *it << endl;
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