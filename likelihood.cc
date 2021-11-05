#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

std::vector<double> daten(0);
double L=1;
int datasize = 234;
double mu1 = 3.11538;
int zahl = 0;
double prob(std::vector<double> daten1, double mu){
  L=1;
  for ( int k = 0; k < daten1.size(); k++) {
    L*=(pow(mu,daten1[k])*exp(-mu)/(tgamma(daten1[k]+1)));
    }
    return L;
}

int main() {
    using namespace std;

    ifstream fin("datensumme.txt");
    ofstream fout("likelihood.txt");
    ofstream fout1("nll.txt");
    ofstream fout2("deltanll.txt");
  
    for(int i = 0 ; i < datasize ; ++i) {
        fin >> zahl;
        daten.push_back(zahl);
    }
    
    std :: cout << "Likelihood for mu = 3.11: L=" <<prob(daten, mu1) << std :: endl ; //Result for 2a) 

    double mu2 = 0;
    
    cout <<"Interval of µ for which: −2 ln [L(µ)/L(ˆµ)] < 1.0: [";
    while (mu2 < 6){
      
      double P = -2*log(prob(daten, mu2));
      double P1 = 2*log((prob(daten, mu1)/prob(daten, mu2)));
      int check=0;
      if(P1<1){
        cout << mu2 << ", ";
      }
  

      fout << mu2 << " " << prob(daten, mu2) << std :: endl ;
      fout1 << mu2 << " " << P << std :: endl ;
      fout2 << mu2 << " " << P1 << std :: endl ;
      mu2 += 0.1;
    }
    cout << "], therefore the interval has a length of 0.1." << endl;

    //2d)
    double var = 0;
    for(int i=0; i<datasize; i++){
      var+=pow(daten[i]-mu1,2);
    }
    var=var/datasize;
    double stddev = sqrt(var);
    double delta = stddev/sqrt(datasize);
    std :: cout << "Uncertainty of µ the sample mean: "<< delta << std :: endl ;
    // The uncertainty is the same as the interval.

    //2e)
    int L1=1;
    for ( int k = 0; k < daten.size(); k++) {
      L1*=(pow(daten[k],daten[k])*exp(-daten[k])/(tgamma(daten[k]+1)));
    }
    cout << L1 << endl;
  
    cout << "Likelihood ratio Λ: " << -2*log(prob(daten,mu1)/L1) << endl;
    cout << "relative deviation of your likelihood ratio from the mean: " << (-2*log(prob(daten,mu1)/L1)-233)/sqrt(2*233) << endl;
    fin.close();

}
// 2b) The maximum of the likelihood plot "out2" resembles the most likely mean. That also fits the result from 2a).