#include <iostream>

using namespace std;

void Reclame2(int n, int k, int &Nr){
    int Primesc=n/k;        ///la prima parcurgere, atatia copii primesc
                            ///numaratoare continua cu poz. n-n%k+1
                            ///primul copil ce primest va fi pe poz k-n%k
    int nn=n;               ///copie a lui n (pentru liniarizarea cercului)
    int cont=0;
    while(nn%k>0){
        nn=n+nn%k;          ///ultimii copii nu primesc ciocalata, ii includem in noua numaratoare
        Primesc+=nn/k;      /// nn/k copii primesc ciocalata
        cont++;
    }
    Nr= n-Primesc;
    cout <<"ciclari: "<<cont<<endl;
}


int main()
{   int n,k,Nr;
    cout <<"da n:";
    cin  >>n;
    cout <<"da k:";
    cin  >>k;
    Reclame2(n,k,Nr);
    cout <<"nu primesc: "<<Nr<<" copii"<<endl;
    cout << "Program terminated" << endl;
    return 0;
}
