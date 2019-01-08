//
//  Matrix.cpp
//  Matrix Comp
//
//  Created by Joshua on 8/2/18.
//  Copyright © 2018 Joshua Freeze. All rights reserved.
//

#include <math.h>
#include "Matrix.hpp"

unsigned int Matrix::Rows()
{
    return rows;
}

unsigned int Matrix::Cols()
{
    return cols;
}

//__________________________
// Constructor
//__________________________

Matrix::Matrix(unsigned int r, unsigned int c)
{
    if (r >= 1 && c >= 1)
    {
        rows = r;
        cols = c;
        matrix = new double[rows * cols];
    }
    else
    {
        throw std::string("ERROR: number or rows and columns must be one or more.");
    }
}

//__________________________
// Input matrix entries
//__________________________
void Matrix::enter()
{
//    delete [] matrix;
//    matrix = new double[25]{1, 2, 3, 4, 5, -2, 3, -4, 5, 1, -3, -3, 4, -5, 2, 1, 2, -3, -3, 5, 2, 0, -2, 0, 4}; // det = -3986
    for (unsigned int row = 0; row < rows; ++row)
    {
        std::cout << "Enter " << cols << " numbers for row " << row + 1 << " separated by spaces: ";
        for (unsigned int col = 0; col < cols; ++col)
        {
            std::cin >> (*this)(row, col);
        }
    }
}

//__________________________
// Display matrix entries
//__________________________
void Matrix::display()
{
    
    double maxelem = *std::max_element((this->matrix),(this->matrix) + rows * cols);
    double minelem = *std::min_element((this->matrix),(this->matrix) + rows * cols);
    int fieldsize = (fmax(floor(log10(fabs(minelem))), floor(log10(fabs(maxelem)))));
    if (fieldsize < 1)
        fieldsize = 1;
    if (minelem < 0 && log10(fabs(minelem) >= log10(fabs(maxelem))))
        fieldsize++;
    fieldsize += 5;
    std::cout << "–—" << std::string( cols * fieldsize - 2, ' ' ) << "––\n";
    for (unsigned int row = 0; row < rows; ++row) {
        std::cout << std::left << "|";
        for (unsigned int col = 0; col < cols ; ++col) {
            if (fabs((*this)(row, col)) < 0.005)
                (*this)(row, col) = 0.0;
            if (col == 0)
                std::cout << std::right << std::setw(fieldsize - 1) << std::fixed
                          << std::setprecision(2) <<  (*this)(row, col);
            else
                std::cout << std::right << std::setw(fieldsize) << std::fixed
                          << std::setprecision(2) <<  (*this)(row, col);
        }
        std::cout << "|\n";
    }
    std::cout << "–—" << std::string( cols * fieldsize - 2, ' ' ) << "––" << std::endl;
}

//__________________________
// Copy Constructor
//__________________________
Matrix::Matrix(Matrix& mtrx)
{
    rows = mtrx.rows;
    cols = mtrx.cols;
    matrix = new double[rows * cols];
    for (unsigned int i = 0; i < rows * cols; i++)
    { (*this)[i] = mtrx[i]; }
}

//__________________________
// Overload assignment
//__________________________
Matrix& Matrix::operator=(Matrix& mtrx)
{
    if (this != &mtrx)
    {
        if (cols * rows > 0)
        {
            delete [] matrix;
        }
        cols = mtrx.cols;
        rows = mtrx.rows;
        matrix = new double[cols * rows];
        for (unsigned int i = 0; i < cols * rows; i++)
        { (*this)[i] = mtrx[i]; }
    }
    return *this;
}

//__________________________
// Overload addition
//__________________________
Matrix& Matrix::operator+(Matrix& mtrx)
{
    if (this->rows != mtrx.rows || this->cols != mtrx.cols)
    {
        throw std::string("ERROR: can't add arrays of different sizes");
    }
    else
    {
        static Matrix sum(this->rows, this->cols);
        for (unsigned int i = 0; i < cols * rows; i++)
        {
            sum.matrix[i] = (*this)[i] + mtrx[i];
        }
        return sum;
    }
}

//__________________________
// Overload subtraction
//__________________________
Matrix& Matrix::operator-(Matrix& mtrx)
{
    if (this->rows != mtrx.rows || this->cols != mtrx.cols)
    {
        throw std::string("ERROR: can't subtract arrays of different sizes");
    }
    return *this + (-1 * mtrx);
}

//__________________________
// Overload parentheses - subscripts
//__________________________
double& Matrix::operator()(unsigned row, unsigned col)
{
    return (this->matrix)[row * cols + col];
}

//__________________________
// Overload square brackets - subscript
//__________________________
double& Matrix::operator[](unsigned int elem)
{
    return (this->matrix)[elem];
}

//__________________________
// Overload (twice) scalar multiplication
//__________________________
Matrix& operator*(const double mult, const Matrix& mtrx)  // scalar first
{
    static Matrix product(mtrx.rows, mtrx.cols);
    for (unsigned int i = 0; i < mtrx.rows * mtrx.cols; i++)
    {
        product.matrix[i] = mult * mtrx.matrix[i];
    }
    return product;
}

Matrix& operator*(const Matrix& mtrx, const double mult) // matrix first
{
    return mult * mtrx;
}

//__________________________
// Overload matrix multiplication
//__________________________
Matrix& operator*(Matrix& left, Matrix& right)
{
    if (left.cols != right.rows)
    {
        throw std::string("ERROR: left matrix cols must equal right matrix rows in multiplication");
    }
    else
    {
        static Matrix product(left.rows, right.cols);
        double entry;
        for (unsigned int row = 0; row < left.rows; row++)
        {
            for (unsigned int col = 0; col < right.cols; col++)
            {
                entry = 0;
                for (unsigned int i = 0; i < left.cols; i++)
                    entry += left(row, i) * right(i, col);
                product(row, col) = entry;
            }
        }
        return product;
    }
}

//__________________________
// Overload power
//__________________________
Matrix& Matrix::operator^(int exponent)
{
    if (this->rows != this->cols)
    {
        throw std::string("ERROR: only a square matrix may be raised to a power");
    }
    int exp = exponent;
    if (exp < 0)
    {
        if (det(*this)== 0)
        {
            throw std::string("ERROR: singular matrix may not be raised to a negative power");
        }
        *this = (*this).inverse();
        exp = -exp;
    }
    static Matrix power(this->rows, this->cols);
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int col = 0; col < cols; col++)
            if (row != col)
                power(row, col) = 0;
            else
                power(row, col) = 1;
    unsigned int i = 1;
    while (i <= exp)
    {
        power = power * *this;
        i++;
    }
    return power;
}

//__________________________
// Minor of a matrix
//__________________________
void Minor(Matrix& mtrx, Matrix& minor, unsigned int row, unsigned int col)
{
    unsigned int mrow = 0,  // row, col of minor
                 mcol = 0,
                 rowi,      // row, col of mtrx
                 coli;
    for (rowi=0; rowi < mtrx.rows; rowi++)
    {
        for (coli=0; coli < mtrx.cols; coli++)
        {
            if (rowi != row && coli != col)
            {
                minor(mrow, mcol) = mtrx(rowi, coli);
                mcol += 1;
            }
        }
        mcol = 0;
        if (rowi != row)
        {
            mrow += 1;
        }
    }
}

//__________________________
// Determinant
//__________________________
double det(Matrix& mtrx)
{
    if (mtrx.rows != mtrx.cols)
    {
        throw std::string("ERROR: only a square matrix has a determinant");
    }
    double determinant = 0;
    if (mtrx.rows == 1)
    {
        determinant = mtrx(0,0);
    }
    else if (mtrx.rows == 2)
    {
        determinant = mtrx(0,0) * mtrx(1,1) - mtrx(0,1) * mtrx(1,0);
    }
    else
    {
        unsigned int row = 0;
        for (unsigned int col = 0; col < mtrx.cols; col ++)
        {
            Matrix minor(mtrx.rows - 1, mtrx.cols - 1);
            Minor(mtrx, minor, row, col);
            determinant += pow(-1, row + col) * mtrx(row, col) * det(minor);
        }
    }
    return determinant;
}

//__________________________
// Adjoint
//__________________________
Matrix& Matrix::adjoint()
{
    if (rows != cols)
    {
        throw std::string("ERROR: only a square matrix has an adjoint");
    }
    static Matrix adjoint(rows, cols);
    Matrix minor(rows - 1, cols - 1);
    for (unsigned int row = 0; row < rows; row++)
    {
        for (unsigned int col = 0; col < cols; col++)
        {
            Minor(*this, minor, row, col);
            adjoint(col, row) = pow(-1, col + row) * det(minor);
        }
    }
    return adjoint;
}

//__________________________
// Inverse
//__________________________
Matrix& Matrix::inverse()
{
    if (rows != cols)
    {
        throw std::string("ERROR: only a square matrix has an inverse");
    }
    if (det(*this) == 0)
    {
        throw std::string("ERROR: a singular matrix has no inverse");
    }
    return (1 / det(*this) * this->adjoint());
}
