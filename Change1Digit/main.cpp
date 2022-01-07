#include <iostream>

using namespace std;

long S(long N,int L,int i,int CifJ){ //schimba pozitia i cu cifra de pe poz j (CifJ)
    long Change=0;
    long Put10=1;
    int Poz=L-i+1;
    int cont=1,Cif;
    while (N){
        Cif=N%10;
        if(cont==Poz)
            Change=Change+CifJ*Put10;
        else
            Change=Change+Cif*Put10;
        Put10*=10;
        N/=10;
        cont++;
        //cout<<Change<<endl;
    }
   return Change;
}

int main()
{   long N=123;
    long L=3;
    cout<<S(N,L,4,6);
    cout << "\nHello world!" << endl;
    return 0;
}
