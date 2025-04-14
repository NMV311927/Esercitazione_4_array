#pragma once
#include <iostream>
using namespace std;


// ImportData reads the input data from a file
// filePath: path name of the input file
// S: initial value of my portfolio
// n: number of assets
// w: assets as fraction of S
// r: rate of return of assets
// returns the result of the reading, true is success, false is error
bool ImportData(const string& inputFilePath,
    double& S,
    size_t& n,
    double*& w,
    double*& r);


// RateOfReturn calculates the total rate of return based on the asset distribution and respective returns
// n: number of assets
// w: assets as fraction of S
// r: rate of return of assets
// returns the total rate of return of my portfolio
double RateOfReturn(const size_t& n,
    const double* w,
    const double* r);


// FinalValue calculates the final value of my portfolio with RateOfReturn 
// S: initial value of my portfolio
// n: number of assets
// w: assets as fraction of S
// r: rate of return of assets
// returns the total final value of my portfolio
double FinalValue(const double S, 
    const size_t& n,
    const double* w,
    const double* r);


// ExportResult exports the result obtained into a file
// outputFilePath: path name of the output file
// S: initial value of my portfolio
// n: number of assets
// w: assets as fraction of S
// r: rate of return of assets
// returns the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
    const double& S, 
    const size_t& n,
    const double* w,
    const double* r);


// ArrayToString exports an array into a string
// n: size of the array
// v: array
// returns the resulting string
string ArrayToString(const size_t& n,
    const unsigned int* const& v);