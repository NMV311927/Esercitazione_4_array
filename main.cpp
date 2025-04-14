#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
using namespace std;


int main()
{
    string inputFile = "data.txt";
    string outputFile = "result.txt";
    size_t n;
    double S;
    double *w = nullptr;
    double *r = nullptr;

    ImportData(inputFile, S, n, w, r);
    ExportResult(outputFile, S, n, w, r);

    delete [] w;
    delete [] r;

    return 0;
}

