#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Matrix {
public:
    Matrix(int row, int col);
    Matrix(const Matrix<T>& m);
    ~Matrix();
    void set(int row, int col, T value);
    void setFrom(T* array);
    T& get(int row, int col);
    const T& get(int row, int col) const;
    template<typename R>
    Matrix<R> retype();
    Matrix transpose() const;
    Matrix multiply(const Matrix& m) const;
    Matrix multiply(T scalar) const;
    Matrix sum(const Matrix& m) const;
    Matrix sum(T scalar) const;
    bool isEqual(const Matrix& m) const;
    void print() const;
private:
    T** matrix;
    int c_Row;
    int c_Col;
};

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    c_Row = row;
    c_Col = col;
    matrix = new T * [row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new T[col];
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = 0;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {
    matrix = new T * [m.c_Row];
    for (int i = 0; i < m.c_Col; ++i) {
        matrix[i] = new T[m.c_Col];
        for (int j = 0; j < m.c_Col; ++j) {
            matrix[i][j] = m.get(i, j);
        }
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < c_Row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    if (row < c_Row && col < c_Col) {
        matrix[row][col] = value;
    }
    else {
        throw std::invalid_argument{ "index" };
    }
}

template<typename T>
void Matrix<T>::setFrom(T* array) {
    int arrSize = sizeof(array) / sizeof(array[0]);
    int ptr = 0;
  
        for (int i = 0; i < c_Row; ++i) {
            for (int j = 0; j < c_Col; ++j) {
                matrix[i][j] = array[ptr];
                ptr++;
            }
        }
}

template<typename T>
T& Matrix<T>::get(int row, int col) {
    if (row < c_Row && col < c_Col) {
        return matrix[row][col];
    }
    else {
        throw std::invalid_argument{ "Index" };
    }
}

template<typename T>
const T& Matrix<T>::get(int row, int col) const {
    if (row < c_Row && col < c_Col) {
        return matrix[row][col];
    }
    else {
        throw std::invalid_argument{ "Index" };
    }
}


template<typename T>
template<typename R>
Matrix<R> Matrix<T>::retype() {
    Matrix<R>* matrix = new Matrix<R>(c_Row, c_Col);
    for (int i = 0; i < c_Row; ++i) {
        for (int j = 0; j < c_Col; ++j) {
            matrix->set(i, j, static_cast<R>(get(i, j)));
        }
    }
    return *matrix;
}


template<typename T>
bool Matrix<T>::isEqual(const Matrix<T>& m) const {
    if (c_Row == m.c_Row && c_Col == m.c_Col) {
        for (int i = 0; i < c_Row; ++i) {
            for (int j = 0; j < c_Col; ++j) {
                if (matrix[i][j] != m.get(i, j)) {
                    return false;
                }
            }
        }
    }
    else {
        return false;
    }
    return true;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T>*transposed = new Matrix<T>(c_Col, c_Row);
    for (int i = 0; i < c_Row; ++i) {
        for (int j = 0; j < c_Col; ++j) {
            transposed->set(j, i, matrix[i][j]);
        }
    }
    return *transposed;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T> &m) const {
    if (c_Col != m.c_Row) {
        throw std::invalid_argument("Invalid argument");
    }

    Matrix<T> new_matrix{ c_Row , c_Col  };

    for (int i = 0; i < c_Row; i++) {
        for (int j = 0; j < m.c_Col; j++) {
            T data = 0;
            for (int k = 0; k < m.c_Row; k++) {
                data += matrix[i][k] * m.matrix[k][j];
            }
            new_matrix.matrix[i][j] = data;
        }
    }
    return new_matrix;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(T scalar) const {
    Matrix<T> mult = new Matrix<T>(c_Row, c_Col);
    for (int i = 0; i < c_Row; ++i) {
        for (int j = 0; j < c_Col; ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return mult;
}

template<typename T>
Matrix<T> Matrix<T>::sum(const Matrix& m) const {
    if (c_Row == m.c_Row && c_Col == m.c_Col) {
        Matrix<T> sum = new Matrix<T>(c_Row, c_Col);
        for (int i = 0; i < c_Row; ++i) {
            for (int j = 0; j < c_Col; ++j) {
                sum[i][j] += matrix[i][j] + m.get(i, j);
            }
        }
    }
    else {
        throw std::invalid_argument{ "Matrix size" };
    }
    return sum;
}
template<typename T>
Matrix<T> Matrix<T>::sum(T scalar) const {
    Matrix<T> sum = new Matrix<T>(c_Row, c_Col);
    for (int i = 0; i < c_Row; ++i) {
        for (int j = 0; j < c_Col; ++j) {
            sum[i][j] += matrix[i][j] + scalar;
        }
    }
    return sum;
}
template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < c_Row; ++i) {
        for (int j = 0; j < c_Col; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
#endif //MATRIX_H