#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    double investimento = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ReadData(inputFileName,investimento,n,w,r))
    {
        cerr<<"qualcosa è andato storto con l'importazione dei dati"<<endl;
        return -1;
    }
    else
        cout<<"importazione avvenuta con successo"<<endl<<endl;

    double RoRcomplessivo = PortfolioRateOfReturn(n,w,r);
    string outputFileName = "result.txt";

    if (!ExportResult(outputFileName, n, w, r, investimento, RoRcomplessivo))
    {
        cerr<<"qualcosa è andato storto con l'esportazione dei dati"<<endl;
        return -2;
    }
    else
        cout<<endl<<"esportazione avvenuta con successo"<<endl;


    delete[] w;
    delete[] r;

    return 0;
}

