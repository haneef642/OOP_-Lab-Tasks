#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** elements;

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        elements = new int*[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[cols]{0};
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix& other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.elements[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix A(2, 2);
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    Matrix B(2, 2);
    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    cout << "Matrix A " << endl;
    A.display();
    cout << endl;

    cout << "Matrix B " << endl;
    B.display();
    cout << endl;

    cout << "Matrix A + B " << endl;
    Matrix C = A.add(B);
    C.display();
    cout << endl;

    cout << "Matrix A * B " << endl;
    Matrix D = A.multiply(B);
    D.display();
    cout << endl;

    return 0;
}

