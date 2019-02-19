/**@mainpage
 *
 * CISC 5825: Computer Algorithms<br/>
 * Project 1: Comparing Fibonacci Algorithms<br/>
 *
 * <p>Computes Fibonacci numbers by the following algorithms:</p>
 * <ol>
 *  <li>Naive recursion.</li>
 *  <li>Explicit matrix-based formula (page 9 of text), based on
 * fast matrix power algoroithm (page 19)</li>
 * </ol>
 * <p>It also gives the timing of these algorithms.</p>
 *
 * @author Jonathan Uy
 * @date 10/7/2018
 * @file proj1.cc
 *
 **********************************************************************/

#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

#include "Matrix.h"

using Fib_alg = long int(*)(unsigned int);

// function prototypes

/**
 * Print a usage msg.
 * 
 * @param progname the name of the program whose usage msg we print.
 */ 
void usage(string progname);

/**
 * Test a Fibonacci algorithm.
 *
 * More precisely, it uses a specific algorithm to compute a specific
 * Fibonacci number, as well as time how long it took to do so.
 *
 * @param name identifies which algorithm we're testing
 * @param fib a Fibonacci algorithm
 * @param n maximum Fibonacci index 
 */
void test_alg(string name, Fib_alg fib, unsigned int n);

/**
 * Naive implementation of recursive Fibonacci algorithm.
 *
 * @param n index of Fibonacci number \f$F_n\f$
 *
 * @return \f$F_n\f$
 * @pre \f$n\ge0\f$
 */
long int fib_rec_naive(unsigned int n);

/**
 * Fibonacci algorithm, using explict formula with matrix power.
 *
 * Use fast algorithm (see page 19 of text, ignore the modular part).
 *
 * @param n index of Fibonacci number \f$F_n\f$
 * @return \f$F_n\f$
 * @pre \f$n\ge0\$
 */
long int fib_matrix(unsigned int n);

/**
 * The usual main function.
 *
 * Takes a non-negative integer \f$n\f$ from the command line.
 * It then uses the aforementioned algorithms to compute (and print) the
 * Fibonacci numbers \f$F_n\f$
 * In addition, it displays the amount of time each algorithm took to
 * compute \f$F_n\f$.
 */
int main(int argc, char* argv[])
{
   /// program name, for error msgs
   string progname {argv[0]};

   try {
      // check command line arguments
      if (argc != 2) {
         usage(progname);
         return 1;
      }

      /// order of highest Fibonacci number
      unsigned int n = stoul(argv[1]);

      // test them out
      test_alg("naive", fib_rec_naive, n);
      cout << endl;
      test_alg("matrix power", fib_matrix, n);
      return 0;

   } // try

   catch (...) {
      usage(progname);
      return 2;
   }
}

// function definitions

void usage(string progname)
{
   cerr << "usage:\n   " << progname << " n\n"
        << "where  n  is a non-negative integer\n";
}

void test_alg(string name, Fib_alg fib, unsigned int n)
{
   cout << "Using " << name << " algorithm:\n";
   auto start = system_clock::now();
   long int result = fib(n);
   cout << "Fib[" << n << "] = " << result << endl;
   auto end = system_clock::now();
   duration<double> elapsed_seconds = end - start;
   cout << "Elapsed time: " << setprecision(3)
        << elapsed_seconds.count() << " seconds\n";
}

// Recursive Fibonacci Algorithm
long int fib_rec_naive(unsigned int n)
{
	long int result = 0;

	if(n == 0 || n == 1) {
		result = n;
	}
	else{
		result = fib_rec_naive(n-1) + fib_rec_naive(n-2);
	}
    
return result;
}

// stub version, must refine/ Matrix multiplication
long int fib_matrix(unsigned int n)
{
	Matrix mat(1, 1, 1, 0);
	Vector vec(1, 0);
	Vector resvec(0, 0);
	long int result = 0;

//if n == 0 or n == 1, fib number is n
//else resulting F(n) == vector.data[0] of (M^n)*vector

	if(n == 0 || n == 1)
		result = n;
	else{
		resvec = power(mat,n-1) * vec;
		result = resvec.data[0];
	}
		
return result;
}
