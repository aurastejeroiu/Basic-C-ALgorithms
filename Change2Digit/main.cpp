#include <iostream>

using namespace std;
// se da un numar si pozita a 2 cifre i si j
// sa se obtina numarul prin interschimbarea cifrelor de pe pozitiile i si j
// pozitiile se numara din stanga (i<j)
// exemplu 157278 i=2(cifra 5) si j=5 (cifra 7)
// se obtine 177258

int DimNumber(long N){
   int cont =0;
   while(N){
      N=N/10;
      cont++;
   }
   return cont;
}

long SchPozIcuCifJ(long N,int L,int i,int CifJ){ //schimba pozitia i cu cifra de pe poz j (CifJ)
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
    }
   return Change;
}

long Schimba(long N, int i, int j, int L){  //i<j
    int CifI,CifJ,cont,Poz,Cif;
    long BackN,Change,Put10;
    BackN=N;
    Poz=L-j+1;        //determinarea cifrei de pe poz j
    while(Poz && N){
        CifJ=N%10;
        N=N/10;
        Poz--;
    }
    N=BackN;
    Poz=L-i+1;              //determinarea cifrei de pe poz i
    while(Poz && N){
        CifI=N%10;
        N=N/10;
        Poz--;
    }
    N=BackN;                            //aici se pune pe pozitia j cifra de pe pozitia i(CifI)
    Change=SchPozIcuCifJ(N,L,j,CifI);
    N=Change;
    Change=SchPozIcuCifJ(N,L,i,CifJ);   //aici se pune pe pozitia i cifra de pe pozitia j (CifJ)
    return Change;
}

int main()
{   int i,j,Lung;
    long n, Changed;
    cout<<"da numarul:";
    cin >>n;
    cout<<"da poz. primei cifre:";
    cin >>i;
    cout<<"da poz. cifrei cu care se schimba:";
    cin >>j;
    Lung=DimNumber(n);
    Changed=Schimba(n,i,j,Lung);
    cout <<n<<endl;
    cout <<Changed<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
