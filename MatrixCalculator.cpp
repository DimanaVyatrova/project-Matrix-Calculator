#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;

void inputMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplMatrixAndNum (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    double num = 0;
    cout << "Input number: ";
    cin >> num;
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix[i][j] = matrix[i][j]*num;
        }
    }
}

void divideMatrixByNum (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    double num = 0;
    cout << "Input number: ";
    cin >> num;
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix[i][j] = matrix[i][j]/num;
        }
    }
}

void transposeMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    double matrix_copy[MAX_SIZE][MAX_SIZE];
    //Copying matrix
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
           matrix_copy[i][j] = matrix[i][j];
        }
    }
    //Transposing matrix
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
           matrix[j][i] = matrix_copy[i][j];
        }
    }
}

void multiplMatrixByMatrix (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    //Initializing and inputing the second matrix
    double matrix2[MAX_SIZE][MAX_SIZE];
    int matrix2Height = 0, matrix2Wight = 0;
    cout << "Input matrix wight: ";
    cin >> matrix2Wight;
    cout << "Input matrix height: ";
    cin >> matrix2Height;
    inputMatrix(matrix2, matrix2Height, matrix2Wight);

    //Initializing the matrix, which will store the result
    double resultMatrix[MAX_SIZE][MAX_SIZE];
    //Setting it's values to zero
    for(int i = 0; i < matrix2Wight; i++) {
        for(int j = 0; j < matrixHeight; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    //Multiply both matrices and store the result is the result matrix
    for(int i = 0; i < matrix2Wight; i++) {
        for(int j = 0; j < matrixHeight; j++) {
            for(int k = 0; k < matrix2Height; k ++) {
                resultMatrix[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    outputMatrix(resultMatrix, matrixHeight, matrix2Wight);
}

int main (){
    int n = 0, m = 0;
    cout << "Input matrix wight: ";
    cin >> n;

    cout << "Input matrix height: ";
    cin >> m;

    double matrix[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrix, m, n);
    multiplMatrixByMatrix(matrix, m, n);
    //outputMatrix(matrix, m, n);


return 0;
}
