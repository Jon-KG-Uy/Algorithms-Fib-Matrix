/*
 * Implementation file for Matrix and Vector classes
 * 
 * @author Jonathan Uy
 * @date 7 Oct. 2018
 * @file Matrix.cc
 */ 

#include "Matrix.h"

Matrix::Matrix(int a, int b, int c, int d)
{
   data[0][0] = a;
   data[0][1] = b;
   data[1][0] = c;
   data[1][1] = d;
}

//resmat uses += to emulate dot product value of matrix multiplication
//cycle through k, then j, then i to ensure all the items in mat1 and mat2 are 
//successfully multiplied
//result matrix is of size four
Matrix operator*(const Matrix& mat1, const Matrix& mat2)
{
	Matrix resmat;

	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				resmat.data[i][j] += mat1.data[i][k] * mat2.data[k][j];

return resmat;
}

// stub version, must refine
// recursive multiplication?
Matrix power(const Matrix& mat, unsigned int n)
{
	Matrix resmat;

//if n == 1, matrix stays the same
//if n is even, ((x)^y/2)^2
//if n is odd, ((x)^y/2)^2

	if(n == 1)
		return mat;
	else if(n % 2)
		return mat * power(mat, n-1);

	resmat = power(mat, n/2);
	resmat = resmat * resmat;

return resmat;
}

Vector::Vector(int x, int y)
{
    data[0] = x;
    data[1] = y;
};

// return type == vector struct...
// F(n) is vector.data[0] according to text
Vector operator*(const Matrix& mat, const Vector& b)
{
	Vector resvec;
	
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			resvec.data[i] += mat.data[i][j] * b.data[j];
	
return resvec;
}
