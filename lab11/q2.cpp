#include <iostream>
#include <stdexcept>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException";
    }
};

template<typename T>
class Matrix {
    T** data;
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds");
        return data[r][c];
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows)
            throw DimensionMismatchException();
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};
