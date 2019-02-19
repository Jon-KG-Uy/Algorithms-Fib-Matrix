######################################################################
#
# CISC 5825 Project 1: Comparing Fibonacci Algorithms
#
# Author: A. G. Werschulz
# Date:   20 Sep 2018
#
######################################################################

CXXFLAGS=-Wall -std=c++17 -g

proj1: proj1.o Matrix.o
	$(CXX) $(CXXFLAGS) -o proj1 proj1.o Matrix.o

Matrix.o: Matrix.cc Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cc

clean:
	@/bin/rm -f *~ \#*\# core* proj1 *.o


