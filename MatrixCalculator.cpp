//Notes to me
//func inverse matrix doesn't work with 2x2 matrix
//delete
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

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

void inputMatrix(double **matrix, int matrixHeight, int matrixWight) {

    cout << "Now input the matrix itself" << endl;
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(double **matrix, int matrixHeight, int matrixWight) {
    for(int i = 0; i < matrixHeight; i++) {
        cout << "|| ";
        for(int j = 0; j < matrixWight; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << "||";
        cout << endl;
    }
    //cout << endl;
}

void multiplMatrixAndNum (double **matrix, int matrixHeight, int matrixWight, double num) {

    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix[i][j] = matrix[i][j]*num;
        }
    }
}

void divideMatrixByNum (double **matrix, int matrixHeight, int matrixWight, double num) {

    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix[i][j] = matrix[i][j]/num;
        }
    }
}

void transposeMatrix(double **matrix, int matrixHeight, int matrixWight) {
    double **matrix_copy = new double*[matrixHeight];
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
    for (int i = 0; i < matrixHeight; i++) {
         delete []matrix_copy[i];
    }
    delete []matrix_copy;
}

void multiplMatrixByMatrix (double **matrix, int matrixHeight, int matrixWight) {
    //Initializing and inputing the second matrix
    int matrix2Height = 0, matrix2Wight = 0;
    cout << "Now input the second matrix" << endl;
    cout << "Input matrix wight: ";
    cin >> matrix2Wight;
    cout << "Input matrix height: ";
    cin >> matrix2Height;

    //validation
    if (matrixWight != matrix2Height){
        cout << "Invalid value";
    }
    else{
        double **matrix2 = new double*[matrix2Height];
        for (int i = 0; i < matrix2Height; i++) {
            matrix2[i] = new double[matrix2Wight];
        }
        inputMatrix(matrix2, matrix2Height, matrix2Wight);

        //Initializing the matrix, which will store the result
        double **resultMatrix = new double*[matrixHeight];
        for (int i = 0; i < matrixHeight; i++) {
            resultMatrix[i] = new double[matrix2Wight];
        }
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
        for (int i = 0; i < matrixHeight; i++) {
             delete []resultMatrix[i];
        }
        delete []resultMatrix;
        for (int i = 0; i < matrix2Height; i++) {
             delete []matrix2[i];
        }
        delete []matrix2;
    }
}

double find_det_3_by_3(double **mat) {
    double det = 0;

    det = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1]
        - mat[0][2] * mat[1][1] * mat[2][0] - mat[0][0] * mat[1][2] * mat[2][1] - mat[0][1] * mat[1][0] * mat[2][2];

    return det;
}

double findDet (double **matrix, int matrixHeight, int matrixWight) {

    if (matrixHeight != 1) {

        double det = 0;

        if(matrixHeight == 2) {
            det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
            return det;
        }

        if(matrixHeight == 3) {
            det = find_det_3_by_3(matrix);
            return det;
        }

        double **cofMat = new double*[matrixHeight - 1];
        for (int i = 0; i < matrixHeight - 1; i++) {
            cofMat[i] = new double[matrixWight - 1];
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
        for (int i = 0; i < matrixHeight - 1; i++) {
             delete []cofMat[i];
        }
        delete []cofMat;
        return det;
    }

    else if (matrixHeight == 1) {
        return matrix[0][0];
    }
}

void findCofactor(double **matrix, double **cofMat, int matrixHeight, int matrixWight, int row, int col) {
    //cout << "row = " << row << endl;
    //cout << "col = " << col << endl;
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

void findInverseMatrix(double **matrix, int matrixHeight, int matrixWight) {
    double det = findDet(matrix, matrixHeight, matrixWight);

    //Initializing the matrix which will store the copy
    double **matrix_Copy = new double*[matrixHeight];
    for(int i = 0; i < matrixHeight; i++) {
        matrix_Copy[i] = new double[matrixWight];
    }
    //Copying matrix
    for(int i = 0; i < matrixHeight; i++) {
        for(int j = 0; j < matrixWight; j++) {
            matrix_Copy[i][j] = matrix[i][j];
        }
    }

    double **cofMat = new double*[matrixHeight - 1];
    for(int i = 0; i < matrixHeight - 1; i++) {
        cofMat[i] = new double[matrixWight - 1];
    }
    for(int i = 0; i < matrixHeight; i++) { //row
        for(int j = 0; j < matrixWight; j++) { //col
            findCofactor(matrix_Copy, cofMat, matrixHeight, matrixWight, i, j);
            matrix[i][j] = myPow(-1, i + j) * findDet(cofMat, matrixHeight - 1, matrixWight - 1);
        }
    }
    for (int i = 0; i < matrixHeight - 1; i++) {
         delete []cofMat[i];
    }
    delete []cofMat;
    for (int i = 0; i < matrixHeight; i++) {
         delete []matrix_Copy[i];
    }
    delete []matrix_Copy;
    transposeMatrix(matrix, matrixHeight, matrixWight);
    multiplMatrixAndNum(matrix, matrixHeight, matrixWight, 1/det);
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

    if(operation == 1) {
        cout << "Input matrix wight: "; //cols
        cin >> n;
        cout << "Input matrix height: "; //rows
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "invalid value";
        }
        else {
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            cout << "Please input the number" << endl;
            int num = 0;
            cin >> num;
            cout << "Here is the result" << endl;
            multiplMatrixAndNum(matrix, m, n, num);
            outputMatrix(matrix, m, n);
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }

    }

    if(operation == 2) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else{
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            multiplMatrixByMatrix(matrix, m, n);
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }
    }

    if(operation == 3) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;
        //validation
        if (n != m || n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            cout << "The determinant is: " << findDet(matrix, m, n);
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }

    }

    if (operation == 4) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            cout << "Please input the number" << endl;
            int num = 0;
            cin >> num;
            //validation for num
            if(num == 0){
                cout << "Can't divide by zero! Sorry :(" << endl;
            }
            else{
                divideMatrixByNum(matrix, m, n, num);
                outputMatrix(matrix, m, n);
            }
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }

    }

    if(operation == 5) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n != m || n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            findInverseMatrix(matrix, m, n);
            outputMatrix(matrix, m, n);
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }

    }

    if(operation == 6) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0){
            cout << "invalid value";
        }
        else {
            double **matrix = new double*[m];
            for(int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);
            transposeMatrix(matrix, m, n);
            outputMatrix(matrix, n, m);
            for (int i = 0; i < n; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
        }

    }



return 0;
}
/*1 2 3
-1 -2 5
0 1 1*/
