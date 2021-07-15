#include <iostream>
#include <vector>
using namespace std;

void swapValues(int &valueOne, int &valueTwo) {
    int tempValue = valueOne;
    valueOne = valueTwo;
    valueTwo = tempValue;
}

void printMatrix(vector<vector<int> > matrix) {
    for (int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int halfN = n / 2;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i != j && j > i) {
                swapValues(matrix[i][j], matrix[j][i]);
            }
        }

        for (int j=0; j<halfN; j++) {
            swapValues(matrix[i][j], matrix[i][n-1-j]);
        }
    }

    printMatrix(matrix);
}

int main() {
    vector<vector<int> > matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotate(matrix);

    return 0;
}
