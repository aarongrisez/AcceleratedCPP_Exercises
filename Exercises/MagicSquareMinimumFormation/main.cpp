#include <bits/stdc++.h>

using namespace std;

// Background
//
// A 3x3 Magic square is a matrix of integers such that the following are true
//
//      a b c
//      d e f
//      g h i
//
//      a + b + c = K
//      d + e + f = K
//      g + h + i = K
//      a + d + g = K
//      b + e + h = K
//      c + f + i = K
//      a + e + i = K
//      c + e + g = K
//
// This is a simple linear system with 9 independent parameters and 8 constraining equations. Therefore,
// a one-parameter family of solutions exist satisfying the system. By arbitrarily introducing an additional
// constraint, the solution is uniquely identified.
//
// We use the standard variational distance between two matrices (viewed as two column vectors where column major
// ordering is used, for example) as the sum of the absolute distances between the elements. That is, 
//
//      d(M1, M2) := |a1 - a2| + |b1 - b2| + |c1 - c2| + ...
//
// where d(M1, M2) is the variational distance between two matrices M1 and M2 having elements a1, b1, c1, ... and
// a2, b2, c2, ... respectively.
//
// Given two arbitrary 3x3 matrices, one can find the minimum variational distance to a magic square by the following
// construction:
//
//      for (each element in matrix, X) {
//          add X = its given value to the list of constraints*
//          Solve the system of constraints
//          Calculate the variational distance, D
//          Keep track of D in an array, A
//      }
//
//      return min(A)
//
// *This step "fixes" a value from the original matrix--that is, we choose an element of the original matrix, assign
// it a value, and solve the system
//
//
// Note: For higher dimensional problems, there will be additional arbitrary parameters over which to optimize. This
// can be achieved through a linear program which is outside the scope of this problem.
//

template <typename T>
vector<vector<T> > getMSCoefficients(int pos, int val, int squareSum, vector<vector<T> > coeffs) {
    // pos - the position of the current fixed element
    // val - the value of the current fixed element
    // i.e.: in standardCoefficients, the element at "pos" is replaced with the value "val"
    // squareSum - the last element of each row of coefficients is changed to be this value
    
    // Sanity bounds check--ensure that pos is in the size of a row of coeffs
    // the minus 1 is to check that the last column is not affected, this is set
    // with "squareSum"
    int cols = coeffs[0].size();
    if (pos > cols - 1) {
        throw "Position out of bounds";
    }

    for (int i = 0; i < coeffs.size(); ++i) {
        coeffs[i][pos] = val;
        coeffs[i][cols - 1] = squareSum; 
    } 

    return coeffs;
}

template <typename T>
void displayMatrix(vector<vector<T> > matrix) {
    int cols = matrix[0].size();
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<float> > solveSystem(vector<vector<float> >& coefficients) {

}

void firstTriangular(vector<vector<float> >& coefficients) {
    int cols = coefficients[0].size();
    for (int i = 0; i < coefficients.size(); ++i) {
    // Row iterator
        if (coefficients[i][i] == 0) {
            throw "Setup error";
        }
        if (coefficients[i][i] != 1) {
            for (int j = 0; j < cols; ++j) {
                coefficients[i][j] = (float)coefficients[i][j] / coefficients[i][i];
            }
        }
        for (int k = 0; k < coefficients.size() - i; ++k) {
            for (int j = 0; j < cols; ++j) {
                coefficients[k][j] = coefficients[k][j] - (coefficients[i][j] * coefficients[i][i]);
            }
        }
    }
}


int formingMagicSquare(vector<vector<int> > s) {
// Given two arbitrary 3x3 matrices, find the minimum variational distance to a magic square
    for (int i = 0; i < 9; ++i) {
        // Get coefficient matrix
        // Solve
    }

    return 0;
}

int main()
{

    vector<vector<int> > s(3);
    /*
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    */
    int result = formingMagicSquare(s);

     vector<vector<float> > standardCoefficients {{ 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
                                               { 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 },
                                               { 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
                                               { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
                                               { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
                                               { 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 },
                                               { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 }, 
                                               { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 }};

    auto x = getMSCoefficients(3, 5, 2, standardCoefficients);
    firstTriangular(x);
    displayMatrix(x);

    cout << result << "\n";

    return 0;
}
