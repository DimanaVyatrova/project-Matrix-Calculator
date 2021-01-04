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

int main (){
    int n = 0, m = 0;
    cout << "Input matrix wight: ";
    cin >> n;

    cout << "Input matrix height: ";
    cin >> m;

    double matrix[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrix, m, n);
    outputMatrix(matrix, n, m);

return 0;
}
