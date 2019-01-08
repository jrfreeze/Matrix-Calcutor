//
//  Matrix.hpp
//  Matrix Comp
//
//  Created by Joshua on 8/2/18.
//  Copyright © 2018 Joshua Freeze. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>

class Matrix

// Look at https://stackoverflow.com/questions/2076624/c-matrix-class

{
private:
    unsigned int rows,
                 cols;
/* Move matrix back to private */
public:
    double* matrix;
    unsigned int Rows();
    unsigned int Cols();
    Matrix(unsigned int r, unsigned int c);    // Constructor
    Matrix(Matrix& mtrx);  // Copy Constructor
    ~Matrix()  // Destructor deallocates the matrix
    {
        delete [] matrix;
        matrix = nullptr;
    }
    void enter();   // Input matrix entries
    void display(); // Display the matrix
    Matrix& operator=(Matrix& mtrx); // Overload assignment
    Matrix& operator+(Matrix& mtrx);  // Overload addition
    Matrix& operator-(Matrix& mtrx);  // Overload subtraction
    Matrix& operator^(int exponent);  // Overload power
    double& operator()(unsigned int row, unsigned int col);
    double& operator[](unsigned int elem);
    friend Matrix& operator*(const double mult, const Matrix& mtrx);  // Overload multiplication - scalar left
    friend Matrix& operator*(const Matrix& mtrx, const double mult);  // Overload multiplication - scalar right
    friend Matrix& operator*(Matrix& left, Matrix& right);  // Overload multiplication - matrix
    friend void Minor(Matrix& mtrx, Matrix& minor, unsigned int row, unsigned int col);    // Create the minor of a matrix
    friend double det(Matrix& mtrx);   // Determinant
    Matrix& adjoint();             // Adjoint
    Matrix& inverse();              // Inverse
};

#endif /* Matrix_hpp */
