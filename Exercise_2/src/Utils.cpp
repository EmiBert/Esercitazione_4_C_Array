#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;



bool ReadData(const string& inputFilePath,
              double& S,
              size_t& n,
              double*& w,
              double*& r)
{
    // apertura File
    ifstream file;
    file.open(inputFilePath);

    // controllo corretta apertura
    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // estrazione di S
    string elem;
    getline(file,elem,';');
    getline(file,elem,'\n');
    istringstream convertS;
    convertS.str(elem);
    convertS >> S;

    // estrazione di n
    getline(file,elem,';');
    getline(file,elem,'\n');
    istringstream convertN;
    convertN.str(elem);
    convertN >> n;


    getline(file,elem);

    // allocazione di memoria sui vettori w ed r
    w = new double[n];
    r = new double[n];

    // estrazione di w ed r
    for (int i =0; i<n; i++)
    {
        getline(file,elem,';');
        w[i] = stod(elem);

        getline(file,elem);
        r[i] = stod(elem);
    }


    // Close File
    file.close();
    return true;
}




double PortfolioRateOfReturn(const size_t& n,
                             const double* const& w,
                             const double* const& r)
{   // inizializzazione della variabile di ritorno
    double RoR = 0;

    // calcolo del rate of return complessivo
    for (int i=0; i<n; i++)
    {
        RoR += w[i]*r[i];
    }

    return RoR;
}




bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& S,
                  const double& RoR)
{
    // dichiarazione di print, variabile che conterrà il testo dell'output
    ostringstream print;

    // la precisione viene impostata a 2 per tenere conto dei "trailing zeros"
    print<<fixed<<setprecision(2);

    print<<"S = "<<S<<", n = "<<n<<endl;
    print<<"w = [ ";

    for (int i=0; i<n;i++)
    {
        print<<w[i]<<" ";
    }

    print<<"]"<<endl;
    print<<"r = [ ";

    for (int i=0; i<n;i++)
    {
        print<<r[i]<<" ";
    }

    print<<"]"<<endl;
    // la precisione deve essere portata a 4 per non avere approssimazione
    // (nella riga successiva verrà di nuovo impostata a 2)
    print<<"Rate of return of the portfolio: "<<fixed<<setprecision(4)<<RoR<<endl;
    print<<"V: "<<fixed<<setprecision(2)<<S*(1+RoR)<<endl;


    // apertura File
    ofstream file;
    file.open(outputFilePath);

    // controllo corretta apertura
    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // il testo ottenuto in print viene stampato su file
    file<<print.str();

    // chiusura File
    file.close();

    // il testo ottenuto in print viene stampato su schermo
    cout<<print.str();

    return true;
}


