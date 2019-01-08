//
//  main.cpp
//  Matrix Comp
//
//  Created by Joshua on 8/2/18.
//  Copyright © 2018 Joshua Freeze. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Matrix.hpp"

int main() {
    try
    {
        unsigned int rows, cols, rows2, cols2;
//        int exponent;
        double determinant;
        std::cout << "Enter number of rows and columns separated by a space:";
        std:: cin >> rows >> cols;
        Matrix mtrx1(rows, cols);
        mtrx1.enter();
//        std::cout << "Enter exponent on the matrix: ";
//        std::cin >> exponent;
//        std::cout << "Enter number of rows and columns of second matrix:";
//        std:: cin >> rows2 >> cols2;
//        Matrix mtrx2(rows2, cols2);
//        mtrx2.enter();
//        Matrix sum(rows, cols);
//        sum = mtrx1 + mtrx2;
//        Matrix mtrxd(rows, cols);
//        mtrxd.enter();
        std::cout << "Determinant of\n";
//        std::cout << "Inverse of \n";
        mtrx1.display();
//        Matrix power(rows, cols);
//        power = mtrx1^exponent;
//        std::cout << " ^ " << exponent << std::endl;
//        std::cout << "=\n";
//        power.display();
//        Matrix power2(rows, cols);
//        power2 = mtrx1^(-exponent);
//        std::cout << " ^ " << -exponent << std::endl;
//        std::cout << "=\n";
//        power2.display();
//        std::cout << "Product =\n";
//        Matrix product(rows, cols);
//        product = power * power2;
//        product.display();
//        Matrix inv = mtrx1.inverse();
//        inv.display();
//        std::cout << "Their product is the identity matrix:\n";
//        Matrix product = mtrx1 * inv;
//        product.display();
//        mtrx2.display();
        determinant = det(mtrx1);
        std::cout << "= " << determinant << std::endl;
//        Matrix difference = mtrx1 - mtrx2;
//        difference.display();
//        sum.display();
//        Matrix product(rows, cols2);
//        product = mtrx1 * mtrx2;
//        mtrx1 = mtrx1 * 2.5;
//        mtrx1.display();
//        std::cout << "mtrx1(0, 2) = " << mtrx1(2, 1) << std::endl;
//        mtrx2.display();
//        product.display();
    }
    catch (std::string exceptionString)
    {
        std::cout << exceptionString << std::endl;
    }
}

//________
//int main() {
//    int choice;
//    int rows,
//    cols,
//    rows2,
//    cols2;
//    int mult,
//    power;
//    bool validsize = false;
//    try
//    {
//        do {
//            do {
//                std::cout << "  1. Addition\n";
//                std::cout << "  2. Subtraction\n";
//                std::cout << "  3. Scalar Multiplication\n";
//                std::cout << "  4. Matrix Multiplication\n";
//                std::cout << "  5. Exponent\n";
//                std::cout << "  6. Determinant\n";
//                std::cout << "  7. Inverse\n";
//                std::cout << "  0. No more computations\n";
//                std::cout << "Enter number of desired matrix computation: ";
//                std::cin >> choice;
//                if (choice < 0 or choice > 7) {
//                    std::cout << "Invalid choice\n\n"; }
//            } while(choice < 0 or choice > 7);
//
//            while (not(validsize)) {
//                if (choice != 4) {
//                    std::cout << "\nEnter the number of rows and columns. Separated by a space eg. 2 3) ";
//                    std::cin >> rows >> cols;
//                }
//                else {
//                    std::cout << "\nEnter the number of rows and columns for matrix 1. Separated by a space eg. 2 3) ";
//                    std::cin >> rows >> cols;
//                    std::cout << "\nEnter the number of rows and columns for matrix 2. Separated by a space eg. 2 3) ";
//                    std::cin >> rows2 >> cols2;
//                }
//                if (rows <= 1 && cols <= 1)
//                    std::cout << "Row and column size must be a positive integer\n";
//                else {
//                    switch (choice) {
//                        case 1:
//                        case 2:
//                        case 3:
//                            validsize = true;
//                            break;
//                        case 4:
//                            if (cols == rows2 && rows2 >= 1 && cols2 >= 1)
//                                validsize = true;
//                            else std::cout << "In matrix multiplication, the number of columns in the first matrix must equal the number of rows in the second\n";
//                            break;
//                        case 5:
//                        case 6:
//                        case 7:
//                            if (cols == rows)
//                                validsize = true;
//                            else std::cout << "Only square matrices have a determinant, an inverse or can be raised to a power.\n";
//                            break;
//                    }
//                }
//            }
//
//            switch (choice) {
//                case 1:     std::cout << "Entries for first matrix:\n";
//                    matrix1 = enter(rows, cols);
//                    std::cout << "Entries for second matrix:\n";
//                    matrix2 = enter(rows, cols);
//                    answer = add(matrix1, matrix2);
//                    break;
//                case 2:     answer = add(matrix1, smult(-1, matrix2));
//                    break;
//                case 3:     cout << "Enter number to multiply the matrix by: ";
//                    cin >> mult;
//                    answer = smult(mult, matrix1);
//                    break;
//                case 4:     matmult(matrix1, matrix2);
//                    break;
//                case 5:     cout << "Enter power to raise the matrix by: ";
//                    cin >> power;
//                    exp(power, matrix1);
//                    break;
//                case 6:     det(matrix1);
//                    break;
//                case 7:     inv(matrix1);
//                    break;
//                case 0: cout << "Thank you for playing with matrices.\n";
//            }
//        } while (choice != 0);
//    }
//    catch(string exceptstr)
//    {
//    std:cout << exceptstr;
//    }
//    return 0;
//}
//____________

//using namespace std;
//
//typedef vector<vector<int>> matrix;
//
//matrix add(matrix, matrix);
//void sub(int, int);
//matrix smult(int, matrix);
//matrix matmult(matrix, matrix);
//matrix exp(int, matrix);
//int det(matrix);
//matrix inv(matrix); // WILL NEED TO CHANGE INTS TO FLOATS!!!!!
//void rsize(matrix&, int, int);
//matrix enter(int, int);
//void display(matrix, int, int);
//
//matrix matrix1,
//       matrix2,
//       answer;
//
//int main() {
//    int choice;
//    int rows,
//        cols,
//        rows2,
//        cols2;
//    int mult,
//        power;
//    bool validsize = false;
//    do {
//        do {
//            cout << "  1. Addition\n";
//            cout << "  2. Subtraction\n";
//            cout << "  3. Scalar Multiplication\n";
//            cout << "  4. Matrix Multiplication\n";
//            cout << "  5. Exponent\n";
//            cout << "  6. Determinant\n";
//            cout << "  7. Inverse\n";
//            cout << "  0. No more computations\n";
//            cout << "Enter number of desired matrix computation: ";
//            cin >> choice;
//            if (choice < 0 or choice > 7) {
//                cout << "Invalid choice\n\n"; }
//            } while(choice < 0 or choice > 7);
//
//        while (not(validsize)) {
//            if (choice != 4) {
//                cout << "\nEnter the number of rows and columns. Separated by a space eg. 2 3) ";
//                cin >> rows >> cols;
//            }
//            else {
//                cout << "\nEnter the number of rows and columns for matrix 1. Separated by a space eg. 2 3) ";
//                cin >> rows >> cols;
//                cout << "\nEnter the number of rows and columns for matrix 2. Separated by a space eg. 2 3) ";
//                cin >> rows2 >> cols2;
//            }
//            if (rows <= 1 && cols <= 1)
//                cout << "Row and column size must be a positive integer\n";
//            else {
//                switch (choice) {
//                    case 1:
//                    case 2:
//                    case 3:
//                        validsize = true;
//                        break;
//                    case 4:
//                        if (cols == rows2 && rows2 >= 1 && cols2 >= 1)
//                            validsize = true;
//                        else cout << "In matrix multiplication, the number of columns in the first matrix must equal the number of rows in the second\n";
//                        break;
//                    case 5:
//                    case 6:
//                    case 7:
//                        if (cols == rows)
//                            validsize = true;
//                        else cout << "Only square matrices have a determinant, an inverse or can be raised to a power.\n";
//                        break;
//                }
//            }
//        }
//
//        switch (choice) {
//            case 1:     cout << "Entries for first matrix:\n";
//                        matrix1 = enter(rows, cols);
//                        cout << "Entries for second matrix:\n";
//                        matrix2 = enter(rows, cols);
//                        answer = add(matrix1, matrix2);
//                        break;
//            case 2:     answer = add(matrix1, smult(-1, matrix2));
//                        break;
//            case 3:     cout << "Enter number to multiply the matrix by: ";
//                        cin >> mult;
//                        answer = smult(mult, matrix1);
//                        break;
//            case 4:     matmult(matrix1, matrix2);
//                        break;
//            case 5:     cout << "Enter power to raise the matrix by: ";
//                        cin >> power;
//                        exp(power, matrix1);
//                        break;
//            case 6:     det(matrix1);
//                        break;
//            case 7:     inv(matrix1);
//                        break;
//            case 0: cout << "Thank you for playing with matrices.\n";
//            }
//    } while (choice != 0);
//
//
//    return 0;
//}
//
//matrix enter(int rows, int cols) {
//    matrix mtrx;
//    rsize(mtrx, rows, cols);
//    for (int row{0}; row < rows; ++row) {
//        cout << "Enter " << cols << " numbers for row " << row + 1 << " separated by spaces: ";
//        for (int col{0}; col < cols; ++col) {
//            cin >> mtrx[row][col]; }
//    }
//    return mtrx;
//}
//
//void rsize(matrix& mtrx, int rows, int cols) {
//    mtrx.resize(rows);
//    for(int row{0}; row < rows; ++row)
//        mtrx[row].resize(cols);
//}
//
//void display(matrix mtrx, int cols, int rows) {
//
//    for (int row{0}; row < rows; ++row) {
//        cout << right << "\n|";
//        for (int col{0}; col < cols ; ++col) {
//            cout << setw(3) << mtrx[row][col];
//        }
//        cout << "|";
//    }
//}
//
//matrix add(int rows, int cols) {
//    string temp;
//    cout << "\nAdd matrices:\n";
//    matrix matrix1;
//    matrix matrix2;
//    matrix matrixsum;
//
//    rsize(matrixsum, rows, cols);
//
//
//    for (int row{0}; row < rows; ++row) {
//        for (int col{0}; col < cols; ++col) {
//            matrixsum[row][col] = matrix1[row][col] + matrix2[row][col];
//        }
//    }
////    display(matrix1, cols, rows);
////    cout << "\n+";
////    display(matrix2, cols, rows);
////    cout << "\n________";
////    display(matrixsum, cols, rows);
////    cout << "\n\nPress c and enter to continue ";
////    while (1)
////    {
////        if ('c' == cin.get())
////            break;
////    }
////    cout << "\n\n";
//    return matrixsum;
//}
//
//void smult(int rows, int cols, int mult) {}
//
//
//void sub(int rows, int cols) {}
//void matmult(int rows, int cols) {}
//void exp(int rows, int cols, int power) {}
//void det(int rows, int cols) {}
//void inv(int rows, int cols) {}




// {
//    cout << "\nEnter the number of rows and columns. Separated by a space eg. 2 3) ";
//    cin >> rows >> cols;
//    if (rows < 1 || cols < 1) {
//        cout << "Row and column size must be a positive integer\n"; }
//        else {
//            switch (choice) {
//                case 1:
//                case 2:
//                case 3:
//                    validsize = true;
//                    break;
//                case 4:
//                    if (cols == rows2) {
//                        validsize = true
//                    }
//            }
//        } while (not(validsize));
//
//                switch (choice) {
//                    case 1:
//                    case 2:
//
//                        cout << "\nEntries for second matrix: \n";
//                        for (int row{0}; row < rows; ++row) {
//                            cout << "Enter " << cols << " numbers for row " << row + 1 << " separated by spaces: ";
//                            for (int col{0}; col < cols; ++col) {
//                                cin >> matrix2[row][col]; }

//}
//rsize(matrix1, rows, cols);
//rsize(matrix2, rows, cols);
//}

