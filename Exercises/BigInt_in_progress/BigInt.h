#pragma once

#include <array>
#include <string>
#include <vector>

using namespace std;

class BigInt {
	string stringRepresentation;
	int carryValue;
	bool isNegative;
	void addDigit(int d1, int d2, vector<int>& tempSum);
public:
	BigInt();
	BigInt(string stringRepresentation);
	vector<int> integerVector;
	BigInt& operator+= (BigInt* rhs);
	BigInt& operator*= (const BigInt* rhs);
	BigInt& operator-= (const BigInt* rhs);
	BigInt& operator/= (const BigInt* rhs);
};