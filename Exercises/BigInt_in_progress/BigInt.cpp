
#include "BigInt.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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
		this->isNegative = false;
	}
	else {
		this->isNegative = true;
	}
	for (int i = 0; i < stringRepresentation.size(); i++) {
		this->integerVector.push_back((int)stringRepresentation[i] - 48);
	}
	this->carryValue = 0;
}

void BigInt::addDigit(int d1, int d2, vector<int>& tempSum) {
	int temp = d1 + d2 + this->carryValue;
	if (temp >= 10) {
		// Handle carry overflow
		this->carryValue = temp / 10;
		temp = temp % 10;
	}
	tempSum.insert(tempSum.begin(), temp);
}

BigInt& BigInt::operator+= (BigInt* rhs) { 
	cout << "Adding" << endl;
	vector<int> temp;
	vector<int>::reverse_iterator rhsMarker = rhs->integerVector.rbegin();
	for (vector<int>::reverse_iterator it = this->integerVector.rbegin(); it != this->integerVector.rend(); ++it) {
		// Iterate backwards through the vector

		// Case 1: Same size
		if (rhsMarker != rhs->integerVector.rend()) {
			addDigit(*rhsMarker, *it, temp);
			++rhsMarker;
		}
		// Case 2: Second int shorter (i.e.: lhs has more digits)
		else if (rhsMarker == rhs->integerVector.rend()) {
			addDigit(*it, 0, temp);
		}
	}
	// Case 3: Second int string longer (i.e.: rhs has more digits)
	while (rhsMarker != rhs->integerVector.rend()) {
		addDigit(*rhsMarker, 0, temp);
		++rhsMarker;
	}
	this->integerVector = temp;
	do {
		if (this->carryValue > 10) {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue % 10);
		}
		else {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue);
		}
		this->carryValue = this->carryValue / 10;
	} while (this->carryValue > 0);
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

long long int BigInt::integerRepresentation() {
	long long int temp = 0;
	for (int i = 0; i < this->integerVector.size(); i++) {
		temp += this->integerVector[i] * pow(10, this->integerVector.size() - i - 1);
	}
	return temp;
}

void BigInt::testAddition() {

}