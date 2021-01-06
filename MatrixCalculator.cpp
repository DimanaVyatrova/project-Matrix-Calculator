#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;

double myPow (double a, double b){
    double res = 1;
    if(b >= 0){
       for(int i = 0; i < b; i++){
         res = res*a;
      }
    }
    else {
        b = -b;
        for(int i = 0; i < b; i++){
            res = res*(1/a);
        }
    }

    return res;
}

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
    cout << endl;
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

double find_det_3_by_3(double mat[][MAX_SIZE]) {
    double det = 0;

    det = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1]
        - mat[0][2] * mat[1][1] * mat[2][0] - mat[0][0] * mat[1][2] * mat[2][1] - mat[0][1] * mat[1][0] * mat[2][2];

    return det;
}

double findDet (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    double cofMat[MAX_SIZE][MAX_SIZE];
    double det = 0;

    for(int c = 0; c < matrixWight; c++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(j >= c){
                    cofMat[i][j] = matrix[i + 1][j + 1];
                }
                else {
                    cofMat[i][j] = matrix[i + 1][j];
                }
            }
        }
        //outputMatrix(cofMat, 3, 3);
        //cout << "det = " << find_det_3_by_3(cofMat) << endl;
        det = det + matrix[0][c]*myPow(-1, c + 2) * find_det_3_by_3(cofMat);
    }
    return det;
}

int main (){
    int n = 0, m = 0;
    cout << "Input matrix wight: ";
    cin >> n;

    cout << "Input matrix height: ";
    cin >> m;

    double matrix[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrix, m, n);
    //findDet(matrix, m, n);
    //outputMatrix(matrix, m, n);
    cout << findDet(matrix, m, n);


return 0;
}
/*5 1 -4 0
-1 2 0 3
1 1 -7 -2
5 -3 3 0*/
