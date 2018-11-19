#pragma once

#include <array>
#include <string>
#include <vector>

using namespace std;

class BigInt {
	string stringRepresentation;
	pair<int, int> addDecimalPlace(int i, BigInt j);
public:
	BigInt();
	BigInt(string stringRepresentation);
	vector<int> integerVector;
	BigInt& operator+= (const BigInt& rhs);
	BigInt& operator*= (const BigInt& rhs);
	BigInt& operator-= (const BigInt& rhs);
	BigInt& operator/= (const BigInt& rhs);
};