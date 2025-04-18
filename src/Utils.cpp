#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
using namespace std;


bool ImportData(const string& inputFilePath,
    double& S,
    size_t& n, 
    double*& w,
    double*& r)
{
    ifstream file(inputFilePath);

    if(file.fail()){
        cerr << "Error opening data file" << endl;
        return false;
    }
    
    string line;
    string val;

    // first line -- S
    getline(file,line,';'); 
    getline(file,line);
    S = stod(line);

    // second line -- n
    getline(file,line,';'); 
    getline(file,line);
    n = static_cast<unsigned int>(stoi(line));

    // third line -- skip
    getline(file,line); 

    w = new double[n];
    r = new double[n];

    // reads data -- w, r
    for (unsigned int i = 0; i < n; i++) {
        getline(file, line);
        stringstream ss(line);
            getline(ss, val, ';');
            w[i] = stod(val);
            getline(ss, val, ';');
            r[i] = stod(val);
    }
   
    file.close();
    return true;
}


double RateOfReturn(const size_t& n,
    const double* w,
    const double* r)
{
    double RoR = 0.0;
    for(unsigned int i = 0; i < n; i++)
        RoR += r[i] * w[i];
    return RoR;
}


double FinalValue(const double S, 
    const size_t& n,
    const double* w,
    const double* r)
{
    double V = (1 + RateOfReturn(n,w,r)) * S;
    return V;
}


bool ExportResult(const string& outputFilePath,
    const double& S, 
    const size_t& n,
    const double* w,
    const double* r)
{
    ofstream file;
    file.open(outputFilePath);


    if (file.fail())
    {
        cerr<< "Error opening export file"<< endl;
        return false;
    }


    file << "S = " << fixed << setprecision(2) << S << ", n = " << setprecision(3) << n << endl;

    file << fixed << setprecision(2) << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << w[i];
    file << " ]" << endl;

    file << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << r[i];
    file << " ]" << endl;

    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << RateOfReturn(n,w,r) << endl;
    file << "V: " << fixed << setprecision(2) << FinalValue(S,n,w,r) << endl;


    file.close();
    return true;
}

