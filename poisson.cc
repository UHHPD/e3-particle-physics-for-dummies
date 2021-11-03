#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


double poisson(double mu, int k) {
    return 0;
}
double daten[234];
int main() {
    std::vector<int> zaehler(11);


    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> daten[i];  
        zaehler[daten[i]]+=1;
    }
    for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
    std :: cout << k << ":" << zaehler [ k ] << std :: endl ;
    }
    fin.close();
}