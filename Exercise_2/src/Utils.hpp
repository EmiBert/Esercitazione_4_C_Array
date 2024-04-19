#pragma once
#include "iostream"

using namespace std;


// ReadData legge i dati di input dal file contente S, n, w ed r
// inputFilePath: nome del file di input
// S: quantità di denaro all'inizio del periodo
// n: numero di asset (e dimensione dei vettori w ed r)
// w: pesi frazionari dell'investimento sui singoli asset
// r: rate of return dei singoli asset
// la funzione restituisce il risultato della lettura:
// vero se avviene con successo, falso se si presentano errori
bool ReadData(const string& inputFilePath,
              double& S,
              size_t& n,
              double*& w,
              double*& r);




// PortfolioRateOfReturn calcola il rate of return complessivo del portafoglio
// n: numero di asset (e dimensione dei vettori w ed r)
// w: pesi frazionari dell'investimento sui singoli asset
// r: rate of return dei singoli asset
// la funzione restituisce il rate of return complessivo del portafoglio
double PortfolioRateOfReturn(const size_t& n,
                             const double* const& w,
                             const double* const& r);




// ExportResult stampa su schermo e su file i risultati ottenuti
// n: numero di asset (e dimensione dei vettori w ed r)
// outputFilePath: nome del file di output
// w: pesi frazionari dell'investimento sui singoli asset
// r: rate of return dei singoli asset
// S: quantità di denaro all'inizio del periodo
// RoR: rate of return complessivo del portafoglio
// la funzione restituisce il risultato della stampa:
// vero se avviene con successo, falso se si presentano errori
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& S,
                  const double& RoR);







