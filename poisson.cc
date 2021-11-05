#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

double daten[234];

double poisson(double mu, int k){
  double p;
  p=(pow(mu,k)*exp(-mu)/(tgamma(k+1)));
}

int main() {
    std::vector<int> zaehler(11);


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout1("histpoi.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> daten[i];  
        zaehler[daten[i]]+=1;
    }
    for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
    std :: cout << k << ":" << zaehler [ k ] << std :: endl ;
    fout << k << " " << zaehler [ k ] << std :: endl ;
    }

  
  for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
    fout1 << k << " " << zaehler [ k ]<< " " << 234*poisson(3.11538,k) << std :: endl ;
  }

    fout.close();
    fin.close();
}