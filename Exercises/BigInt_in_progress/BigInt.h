#pragma once

#include <array>
#include <string>
#include <vector>

using namespace std;

class BigInt {
	string stringRepresentation;
	int carryValue;
	bool isNegative;
	int addDigit(vector<int>::reverse_iterator it, BigInt j);
public:
	BigInt();
	BigInt(string stringRepresentation);
	vector<int> integerVector;
	BigInt& operator+= (const BigInt& rhs);
	BigInt& operator*= (const BigInt& rhs);
	BigInt& operator-= (const BigInt& rhs);
	BigInt& operator/= (const BigInt& rhs);
};