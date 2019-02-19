/**
 * Header file for 2x2 matrix operations.
 *
 * @author Jonathan Uy
 * @date 7 Oct. 2018
 * @file Matrix.h
 */

#pragma once

/**
 * Some operations on 2x2 matrices, needed for the fast Fibonacci
 * algorithm.  
 */
struct Matrix
{
/**
 * Constructor.
 *
 * Default constructor gives the zero matrix.
 * Four-parameter constructor initializes the four matrix entries from
 * the four parameters.
 */
   Matrix(int a = 0, int b = 0, int c = 0, int d = 0);

/**
 * data for the Matrix
 */
   long data[2][2];
};

/**
 * Multiply two matrices 
 *
 * @param mat1 the left-hand operand
 * @param mat2 the right-hand operand
 * @return the product mat1*mat2
 */
Matrix operator*(const Matrix& mat1, const Matrix& mat2);

/**
 * A two-component vector, needed for the fast Fibonacci algorithm. 
 */
struct Vector
{
/**
 * Constructor.
 * 
 * Default constructor gives the zero vector.
 * Two-parameter constructor initializes the two vector entries from
 * the two parameters.
 */
   Vector (int x = 0, int y = 0);

   /**
    * data for the Vector
    */
   long data[2];
};

/**
 * Compute power of a matrix, using fast algorithm.
 *
 * @param mat the matrix
 * @param n the power
 * @return mat<sup><em>n</em></sup>
 */
Matrix power(const Matrix& mat, unsigned int n);

/**
 * Multiply a matrix by a vector.
 *
 * @param mat the matrix
 * @param b the vector
 * @return mat*b
 */
Vector operator*(const Matrix& mat, const Vector& b);
