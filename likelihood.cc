#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

std::vector<int> daten(0);
double L=1;
double mu1 = 3.11538;
int zahl = 0;
double prob(std::vector<int> daten1, double mu){
  for ( int k = 0; k < daten1.size(); k++) {
    L*=(pow(mu,daten1[k])*exp(-mu)/(tgamma(daten1[k]+1)));
    }
    return L;
}

int main() {
    using namespace std;

    ifstream fin("datensumme.txt");
    ofstream fout("likelihood.txt");
  
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
        daten.push_back(zahl);
    }
    
    std :: cout << "Likelihood for mu = 3.11: L=" <<prob(daten, mu1) << std :: endl ; //Result for 2a) 

    double mu2 = 0;
    while (mu2 < 6){
      L=1;
      double a = prob(daten, mu2);
      fout << mu2 << " " << a << std :: endl ;
      mu2 += 0.1;
    }


    fin.close();

}