//Notes to me
//func inverse matrix doesn't work with 2x2 matrix
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

double myPow (double a, double b) {
    double res = 1;
    if(b >= 0) {
       for(int i = 0; i < b; i++) {
         res = res*a;
      }
    }
    else {
        b = -b;
        for(int i = 0; i < b; i++) {
            res = res*(1/a);
        }
    }

    return res;
}

void inputMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {

    cout << "Now input the matrix itself" << endl;
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    cout << "Here is the result" << endl;
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void multiplMatrixAndNum (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight, double num) {

    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix[i][j] = matrix[i][j]*num;
        }
    }
}

void divideMatrixByNum (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight, double num) {

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
    for(int i = 0; i < matrixWight; i++) {
        for(int j = 0; j < matrixHeight; j++) {
           //matrix[j][i] = matrix_copy[i][j];
           matrix[i][j] = matrix_copy[j][i];
        }
    }
}

void multiplMatrixByMatrix (double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    //Initializing and inputing the second matrix
    double matrix2[MAX_SIZE][MAX_SIZE];
    int matrix2Height = 0, matrix2Wight = 0;
    cout << "Now input the second matrix" << endl;
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

    if(matrixHeight == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        return det;
    }

    if(matrixHeight == 3) {
        det = find_det_3_by_3(matrix);
        return det;
    }

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
        outputMatrix(cofMat, 3, 3);
        det = det + matrix[0][c]*myPow(-1, c + 2) * find_det_3_by_3(cofMat);
    }
    return det;
}

void findCofactor(double matrix[][MAX_SIZE], double cofMat[][MAX_SIZE], int matrixHeight, int matrixWight, int row, int col) {
        cout << "row = " << row << endl;
        cout << "col = " << col << endl;
        for(int i = 0; i < matrixWight - 1; i++) {
            for(int j = 0; j < matrixHeight - 1; j++) {
                if(i < row && j < col) {
                    cofMat[i][j] = matrix[i][j];
                }
                else if(i >= row && j < col) {
                    cofMat[i][j] = matrix[i + 1][j];
                }
                else if(i >= row && j >= col) {
                    cofMat[i][j] = matrix[i + 1][j + 1];
                }
                else if(i < row && j >= col) {
                    cofMat[i][j] = matrix[i][j + 1];
                }
            }
        }
}

void findInverseMatrix(double matrix[][MAX_SIZE], int matrixHeight, int matrixWight) {
    double det = findDet(matrix, matrixHeight, matrixWight);
    double matrix_Copy[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix_Copy[i][j] = matrix[i][j];
        }
    }

    double cofMat[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < matrixHeight; i++) { //row
        for(int j = 0; j < matrixWight; j++) { //col
            findCofactor(matrix_Copy, cofMat, matrixHeight, matrixWight, i, j);
            matrix[i][j] = myPow(-1, i + j) * findDet(cofMat, matrixHeight - 1, matrixWight - 1);
        }
    }

    transposeMatrix(matrix, matrixHeight, matrixWight);
    multiplMatrixAndNum(matrix, matrixHeight, matrixWight, 1/det);
    outputMatrix(matrix, matrixHeight, matrixWight);
}

int main (){
    const size_t STRING_SIZE = 100;
    char str[STRING_SIZE];
    ifstream inputFile;
    string filename;
    cout << "Please input 'menu.txt' to open the file with instructions" << endl;

    cin >> filename;

    inputFile.open(filename);

    if(!inputFile){
      cout << "Such file doesn't exist" << endl;
      return 0;
    }


    while(!inputFile.eof()){
        inputFile.getline(str, STRING_SIZE);
        cout << str << endl;
    }

    inputFile.close();

    int operation = 0;
    cout << "Please input the number of the operation you wish to perform" << endl;
    cin >> operation;

    int m = 0, n = 0;
    double matrix[MAX_SIZE][MAX_SIZE];

    if(operation == 1) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        cout << "Please input the number" << endl;
        int num = 0;
        cin >> num;
        multiplMatrixAndNum(matrix, m, n, num);
        outputMatrix(matrix, m, n);
    }

    if(operation == 2) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        multiplMatrixByMatrix(matrix, m, n);
    }

    if(operation == 3) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        cout << "The determinant is: " << findDet(matrix, m, n);
    }

    if (operation == 4) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        cout << "Please input the number" << endl;
        int num = 0;
        cin >> num;
        if(num == 0){
            cout << "Can't divide by zero! Sorry :(" << endl;
        }
        else{
            divideMatrixByNum(matrix, m, n, num);
            outputMatrix(matrix, m, n);
        }
    }

    if(operation == 5) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        findInverseMatrix(matrix, m, n);
    }

    if(operation == 6) {
        cout << "Input matrix wight: ";
        cin >> n;

        cout << "Input matrix height: ";
        cin >> m;
        inputMatrix(matrix, m, n);
        transposeMatrix(matrix, m, n);
        outputMatrix(matrix, n, m);
    }



return 0;
}
/*1 2 3
-1 -2 5
0 1 1*/
