/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Dimana Vyatrova
* @idnumber 62516
* @compiler gcc
*
* <file with the code for the whole project>
*
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double myPow (double a, double b) {
    double res = 1;
    if (b >= 0) {
       for (int i = 0; i < b; i++) {
         res = res*a;
      }
    }
    else {
        b = -b;
        for (int i = 0; i < b; i++) {
            res = res*(1/a);
        }
    }

    return res;
}

void inputMatrix(double **matrix, int matrixHeight, int matrixWidth) {

    cout << "Now input the matrix itself" << endl;
    for (int i = 0; i < matrixHeight; i++) {
        for (int j = 0; j < matrixWidth; j++) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(double **matrix, int matrixHeight, int matrixWidth) {
    for (int i = 0; i < matrixHeight; i++) {
        cout << "| ";
        for (int j = 0; j < matrixWidth; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << " |";
        cout << endl;
    }
}

//Output a matrix multiplied by a number with operands
void outputWithMultipl (double **matrix_copy, double **matrix, int matrixHeight, int matrixWidth, double num) {
    for (int i = 0; i < matrixHeight; i++) {
        cout << "| ";
        for (int j = 0; j < matrixWidth; j++) {
            cout << setw(3) << matrix_copy[i][j];
        }
        cout << " |";
        if (i == 0) {
            cout << " * " << num << " = ";
        }
        else {
            cout << "       ";
        }

        cout << "| ";
        for (int j = 0; j < matrixWidth; j++) {
            cout << setw(3) << matrix[i][j];
        }
        cout << " |";
        cout << endl;
    }

}

//Output a matrix divided by a number with operands
void outputWithDivide (double **matrix_copy, double **matrix, int matrixHeight, int matrixWidth, double num) {

    for (int i = 0; i < matrixHeight; i++) {
        cout << "| ";
        for (int j = 0; j < matrixWidth; j++) {
            cout << setw(4) << matrix_copy[i][j];
        }
        cout << " |";
        if (i == 0) {
            cout << " / " << num << " = ";
        }
        else {
            cout << "       ";
        }

        cout << "| ";
        for (int j = 0; j < matrixWidth; j++) {
            cout << setw(3) << matrix[i][j];
        }
        cout << " |";
        cout << endl;
    }
}

//Output a matrix multiplied by a matrix with operands
void outputMatrixByMatrix (double **matrix, double **matrix2, double **resultMatrix, int mHeight, int mWidth, int m2Height, int m2Width) {
    int maxH = mHeight, maxW = mWidth;
    if (mHeight < m2Height) {
        maxH = m2Height;
    }
    if (mWidth < m2Width) {
        maxW = m2Width;
    }

    for (int i = 0; i < maxH; i++) {
        if (i < mHeight) {
            cout << "| ";
            for (int j = 0; j < mWidth; j ++) {
                cout << setw(4) << matrix[i][j];
            }
            cout << " |";
        }
        if (i == 0) {
            cout << " * ";
        }
        else {
            cout << "   ";
        }

        if (i < m2Height) {
            if (i >= mHeight) {
                cout << setw(4*mWidth + 3 + 3);
            }
            cout << "| ";
            for (int j = 0; j < m2Width; j++) {
                cout << setw(4) << matrix2[i][j];
            }
            cout << " |";
        }
        if (i == 0) {
            cout << " = ";
        }
        else {
            cout << "   ";
        }

        if (i < mHeight) {
            cout << "| ";
            for (int j = 0; j < m2Width; j++) {
                cout << setw(4) << resultMatrix[i][j];
            }
            cout << " |";
        }
        cout << endl;
    }


}

void multiplMatrixAndNum (double **matrix, int matrixHeight, int matrixWidth, double num) {

    for (int i = 0; i < matrixHeight; i++) {
        for (int j = 0; j < matrixWidth; j++) {
            matrix[i][j] = matrix[i][j]*num;
        }
    }
}

void divideMatrixByNum (double **matrix, int matrixHeight, int matrixWidth, double num) {

    for (int i = 0; i < matrixHeight; i++) {
        for (int j = 0; j < matrixWidth; j++) {
            matrix[i][j] = matrix[i][j]/num;
        }
    }
}

void transposeMatrix(double **matrix, int matrixHeight, int matrixWidth) {

    double **matrix_copy = new double*[matrixHeight];
    for (int i = 0; i < matrixHeight; i++) {
        matrix_copy[i] = new double[matrixWidth];
    }

    //Copying the matrix that will be transposed
    for (int i = 0; i < matrixHeight; i++) {
        for (int j = 0; j < matrixWidth; j++) {
           matrix_copy[i][j] = matrix[i][j];
        }
    }

    //Transposing matrix
    for (int i = 0; i < matrixWidth; i++) {
        for (int j = 0; j < matrixHeight; j++) {
           matrix[i][j] = matrix_copy[j][i];
        }
    }

    //deleting the copied matrix
    for (int i = 0; i < matrixHeight; i++) {
         delete []matrix_copy[i];
    }
    delete []matrix_copy;
}

void multiplMatrixByMatrix (double **matrix, int matrixHeight, int matrixWidth) {
    //Initializing and inputing the second matrix
    int matrix2Height = 0, matrix2Width = 0;
    cout << "Now input the second matrix" << endl;
    cout << "Input matrix width: ";
    cin >> matrix2Width;
    cout << "Input matrix height: ";
    cin >> matrix2Height;

    //validation
    cout << matrixWidth << " " << matrix2Height << endl;
    if (matrixWidth != matrix2Height){
        cout << "Invalid value" << endl;
    }
    else{
        //Initialize and input the second matrix
        double **matrix2 = new double*[matrix2Height];
        for (int i = 0; i < matrix2Height; i++) {
            matrix2[i] = new double[matrix2Width];
        }
        inputMatrix(matrix2, matrix2Height, matrix2Width);

        //Initializing the matrix, which will store the result
        double **resultMatrix = new double*[matrixHeight];
        for (int i = 0; i < matrixHeight; i++) {
            resultMatrix[i] = new double[matrix2Width];
        }

        //Setting it's values to zero
        for (int i = 0; i < matrix2Width; i++) {
            for (int j = 0; j < matrixHeight; j++) {
                resultMatrix[i][j] = 0;
            }
        }

        //Multiply both matrices and store the result in the result matrix
        for (int i = 0; i < matrixHeight; i++) {
            for (int j = 0; j < matrix2Width; j++) {
                for (int k = 0; k < matrix2Height; k ++) {
                    cout << "i = " << i << " j = " << j << " = " << "i = " << i << " j = " << j  << " + " << "i = " << i << " k= " << k << " * " << " k = " << k << " j = " << j << endl;
                    resultMatrix[i][j] += matrix[i][k] * matrix2[k][j];
                }
            }
        }

        outputMatrixByMatrix(matrix, matrix2, resultMatrix, matrixHeight, matrixWidth, matrix2Height, matrix2Width);

        //deleting matrices
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

//Find the determinant of a matrix 3 by 3
double find_det_3_by_3(double **mat) {
    double det = 0;

    det = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1]
        - mat[0][2] * mat[1][1] * mat[2][0] - mat[0][0] * mat[1][2] * mat[2][1] - mat[0][1] * mat[1][0] * mat[2][2];

    return det;
}

//Find the determinant of a matrix with dimensions up to 4 by 4
double findDet (double **matrix, int matrixHeight, int matrixWidth) {


    if (matrixHeight != 1) {

        double det = 0;

        if (matrixHeight == 2) {
            det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
            return det;
        }

        if (matrixHeight == 3) {
            det = find_det_3_by_3(matrix);
            return det;
        }

        //Calculating the determinant of a 4x4 matrix
        //Initializing a cofactor matrix
        double **cofMat = new double*[matrixHeight - 1];
        for (int i = 0; i < matrixHeight - 1; i++) {
            cofMat[i] = new double[matrixWidth - 1];
        }

        for (int c = 0; c < matrixWidth; c++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if(j >= c){
                        cofMat[i][j] = matrix[i + 1][j + 1];
                    }
                    else {
                        cofMat[i][j] = matrix[i + 1][j];
                    }
                }
            }
            det = det + matrix[0][c]*myPow(-1, c + 2) * find_det_3_by_3(cofMat);
        }

        for (int i = 0; i < matrixHeight - 1; i++) {
             delete []cofMat[i];
        }
        delete []cofMat;

        return det;
    }

    else {
        return matrix[0][0];
    }
}

//Find the cofactor matrix for a given element (defined by its indexes)
void findCofactor(double **matrix, double **cofMat, int matrixHeight, int matrixWidth, int row, int col) {

    for (int i = 0; i < matrixWidth - 1; i++) {
        for (int j = 0; j < matrixHeight - 1; j++) {
            if(i < row && j < col) {
                cofMat[i][j] = matrix[i][j];
            }
            else if (i >= row && j < col) {
                cofMat[i][j] = matrix[i + 1][j];
            }
            else if (i >= row && j >= col) {
                cofMat[i][j] = matrix[i + 1][j + 1];
            }
            else if (i < row && j >= col) {
                cofMat[i][j] = matrix[i][j + 1];
            }
        }
    }

}

void findInverseMatrix (double **matrix, int matrixHeight, int matrixWidth) {
    double det = findDet(matrix, matrixHeight, matrixWidth);

    //Initializing the matrix which will store the copy
    double **matrix_Copy = new double*[matrixHeight];
    for (int i = 0; i < matrixHeight; i++) {
        matrix_Copy[i] = new double[matrixWidth];
    }
    //Copying matrix
    for (int i = 0; i < matrixHeight; i++) {
        for (int j = 0; j < matrixWidth; j++) {
            matrix_Copy[i][j] = matrix[i][j];
        }
    }

    double **cofMat = new double*[matrixHeight - 1];
    for (int i = 0; i < matrixHeight - 1; i++) {
        cofMat[i] = new double[matrixWidth - 1];
    }

    //Find the adjuncts of every element
    for (int i = 0; i < matrixHeight; i++) { //row
        for (int j = 0; j < matrixWidth; j++) { //col
            findCofactor(matrix_Copy, cofMat, matrixHeight, matrixWidth, i, j);
            matrix[i][j] = myPow(-1, i + j) * findDet(cofMat, matrixHeight - 1, matrixWidth - 1);
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

    transposeMatrix(matrix, matrixHeight, matrixWidth);
    multiplMatrixAndNum(matrix, matrixHeight, matrixWidth, 1/det);
}

int main (){
    const size_t STRING_SIZE = 100;
    char str[STRING_SIZE];
    ifstream inputFile;
    string filename;
    cout << "Please input 'menu.txt' to open the file with instructions" << endl;

    cin >> filename;

    inputFile.open(filename);

    if (!inputFile) {
      cout << "Such file doesn't exist" << endl;
      return 0;
    }


    while (!inputFile.eof()) {
        inputFile.getline(str, STRING_SIZE);
        cout << str << endl;
    }

    inputFile.close();

    int operation = 0;
    cout << "Please input the number of the operation you wish to perform" << endl;
    cin >> operation;

    int m = 0, n = 0;

    //Operation multiply a matrix with a number
    if (operation == 1) {
        cout << "Input matrix width: "; //cols
        cin >> n;
        cout << "Input matrix height: "; //rows
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "invalid value";
        }
        else {
            double **matrix = new double*[m];
            for (int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);

            double **matrix_copy = new double*[m];
            for (int i = 0; i < m; i++) {
                matrix_copy[i] = new double[n];
            }
            for (int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    matrix_copy[i][j] = matrix[i][j];
                }
            }

            cout << "Please input the number" << endl;
            int num = 0;
            cin >> num;
            cout << "Here is the result" << endl;
            multiplMatrixAndNum(matrix, m, n, num);
            outputWithMultipl(matrix_copy, matrix, m, n, num);

            for (int i = 0; i < m; i++) {
                 delete []matrix[i];
            }
            delete []matrix;
            for (int i = 0; i < m; i++) {
                 delete []matrix_copy[i];
            }
            delete []matrix_copy;
        }

    }

    //Operation multiply a matrix by another matrix
    if (operation == 2) {
        cout << "Input matrix width: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for (int i = 0; i < m; i++) {
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

    //Operation find the determinant of a matrix with dimensions up to 4 x 4
    if (operation == 3) {
        cout << "Input matrix width: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;
        //validation
        if (n != m || n <= 0 || m <= 0 || n > 4 || m > 4 || n != m) {
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

    //Operation divide a matrix by a number
    if (operation == 4) {
        cout << "Input matrix width: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for (int i = 0; i < m; i++) {
                matrix[i] = new double[n];
            }
            inputMatrix(matrix, m, n);

            cout << "Please input the number" << endl;
            int num = 0;
            cin >> num;
            //validation for num
            if (num == 0){
                cout << "Can't divide by zero! Sorry :(" << endl;
            }

            else {
                double **matrix_copy = new double*[m];
                for (int i = 0; i < m; i++) {
                    matrix_copy[i] = new double[n];
                }
                for (int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        matrix_copy[i][j] = matrix[i][j];
                    }
                }

                divideMatrixByNum(matrix, m, n, num);
                outputWithDivide(matrix_copy, matrix, m, n, num);

                for (int i = 0; i < m; i++) {
                     delete []matrix_copy[i];
                }
                delete []matrix_copy;

            }

            for (int i = 0; i < m; i++) {
                 delete []matrix[i];
            }
            delete []matrix;

        }

    }

    //Operation find the inverse of a matrix with dimensions up to 4 x 4
    if (operation == 5) {
        cout << "Input matrix wight: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n != m || n <= 0 || m <= 0 || n > 4 || m < 4) {
            cout << "Invalid value";
        }
        else {
            double **matrix = new double*[m];
            for (int i = 0; i < m; i++) {
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

    //Operation transpose a matrix
    if (operation == 6) {
        cout << "Input matrix width: ";
        cin >> n;
        cout << "Input matrix height: ";
        cin >> m;

        //validation
        if (n <= 0 || m <= 0){
            cout << "invalid value";
        }
        else {
            double **matrix = new double*[m];
            for (int i = 0; i < m; i++) {
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

    if (!(operation >= 1 && operation <= 6)) {
        cout << "We don't have such operation, sorry!" << endl;
    }

return 0;
}
/*1 2 3
-1 -2 5
0 1 1*/
