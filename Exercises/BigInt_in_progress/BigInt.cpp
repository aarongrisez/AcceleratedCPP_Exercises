
#include "BigInt.h"
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

BigInt::BigInt() {
	this->stringRepresentation = "";
    vector<int> empty {};
	this->integerVector = empty;
	this->carryValue = 0;
	this->isNegative = false;
}

BigInt::BigInt(string stringRepresentation) {
	this->stringRepresentation = stringRepresentation;
    auto negative = stringRepresentation.find("-");
	if (negative != string::npos) {
		this->isNegative = true;
        cout << "Negative Number" << endl;
        this->stringRepresentation.erase(0, 1);
	}
	else {
		this->isNegative = false;
	}
    cout << this->stringRepresentation << endl;
	for (int i = 0; i < this->stringRepresentation.size(); i++) {
		this->integerVector.push_back((int)this->stringRepresentation[i] - 48);
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
	auto rhsMarker = rhs->integerVector.rbegin();
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
	while (this->carryValue > 0) {
		if (this->carryValue > 10) {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue % 10);
		}
		else {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue);
		}
		this->carryValue = this->carryValue / 10;
    }
	return *this;
}

void BigInt::subDigit(int d1, int d2, vector<int>& tempSum) {
    cout << "Digit one: " << d1 << endl;
    cout << "Digit two: " << d2 << endl;
	int temp = d1 - d2 + this->carryValue;
	if (temp < 0) {
		// Handle carry overflow
		this->carryValue = temp / 10;
		temp = temp % 10 + 10;
	}
    cout << "Diff of digits: " << temp << endl;
    cout << "Current carry value: " << this->carryValue << endl;
	tempSum.insert(tempSum.begin(), temp);
}

BigInt& BigInt::operator-= (const BigInt* rhs) {
	cout << "Subtracting" << endl;
	vector<int> temp;
    auto rhsMarker = rhs->integerVector.rbegin();
	for (vector<int>::reverse_iterator it = this->integerVector.rbegin(); it != this->integerVector.rend(); ++it) {
		// Iterate backwards through the vector

		// Case 1: Same size
		if (rhsMarker != rhs->integerVector.rend()) {
			subDigit(*rhsMarker, *it, temp);
			++rhsMarker;
		}
		// Case 2: Second int shorter (i.e.: lhs has more digits)
		else if (rhsMarker == rhs->integerVector.rend()) {
			subDigit(*it, 0, temp);
		}
	}
	// Case 3: Second int string longer (i.e.: rhs has more digits)
	while (rhsMarker != rhs->integerVector.rend()) {
		subDigit(*rhsMarker, 0, temp);
		++rhsMarker;
	}
	this->integerVector = temp;
	while (this->carryValue > 0) {
		if (this->carryValue > 10) {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue % 10);
		}
		else {
			this->integerVector.insert(this->integerVector.begin(), this->carryValue);
		}
		this->carryValue = this->carryValue / 10;
    }
	return *this;
}

BigInt& BigInt::operator*= (const BigInt* rhs) {
    BigInt temp = *rhs;
    while (rhs > 0) {
        *this += temp;
        --rhs;
    }
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
