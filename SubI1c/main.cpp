#include <iostream>

using namespace std;

void Reclame3(int n, int k, int &Nr){
    int poz=k;
    int Primesc=0;
    int cont=0;
    do {
        poz+=k;         ///se numara copii din k in k
        if(poz>n){      ///daca numaratoare dep. ultimul copil , ea se reia cu primul copil
            poz=poz%n;  ///iar ciocolata se va da copilului de pe pozitia poz%n
        }
        Primesc++;
        cont++;
    } while(poz!=k);
    Nr= n-Primesc;
    cout <<"ciclari: "<<cont<<endl;
}


int main()
{   int n,k,Nr;
    cout <<"da n:";
    cin  >>n;
    cout <<"da k:";
    cin  >>k;
    Reclame3(n,k,Nr);
    cout <<"nu primesc: "<<Nr<<" copii"<<endl;
    cout << "Program terminated" << endl;
    return 0;
}
