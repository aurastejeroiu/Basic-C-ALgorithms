#include <iostream>
using namespace std;

struct Coada{
   int m;
   int timp[100];
};

void CitireDate(Coada &C, int &n){
    C.m=0;                            ///lungimea cozii
    cout<<"da lungimea cozii:";
    cin>>C.m;
    for(int i=1;i<=C.m;i++){
        cout<<"da un elem.:";
        cin >>C.timp[i];
    }
    cout<<"Pe cate masini:";
    cin >> n;

}

void AfisRepart(int TMax, int n, int Repart[100][10]){
   cout<<endl;
   for(int i=1; i<=n;i++){
      int k=Repart[i][0];
      int Suma=0;
      cout<<"Masinia "<<i<<": ";
      for(int j=1;j<=k;j++){
        cout<<Repart[i][j]<<",";
        Suma+=Repart[i][j];
      }
      if(k>=3) cout<<"\b\t";
      else     cout<<"\b\t\t";
      cout<<"Timpul consumat: "<<Suma<<"  timp ramas:"<<TMax-Suma<<endl;
   }
}



void Strategia(Coada C, int& TMax, int n, int Repart[100][10]){
    cout<<"Timpul limita max:";
    cin >> TMax;
    int T[n];                   ///timpii ramasi pe ficeare masina, raportati la TMax
    for (int i=1;i<=n;i++){     ///initilaizare T si Repart
        T[i]=TMax;
        Repart[i][0]=0;
    }

    int j=1;
                                ///determinare timpii ramasi pe fiecare masina: T[i]-suma timpilor repartizati
    while(j<=C.m){
            int Dif[n],iMin;
            for (int i=1;i<=n;i++)      ///diferentele de timpi pentru fiecare masina referitor la elementul j din coada
                {Dif[i]=T[i]-C.timp[j];
                 if(Dif[i]>0) iMin=i;   ///iMin se initializeaza cu indicele unei diferente pozitive
                }
                             ///determinare minim din timpii ramasi pe fiecare masina
            for (int i=1;i<=n;i++)
                {   if(Dif[i]>0 && Dif[i]<Dif[iMin]) iMin=i;
                }
                                        ///repartizare element C.timp[j] pe masina iMax
            int k=++Repart[iMin][0];
            Repart[iMin][k]=C.timp[j];
            T[iMin]-=C.timp[j];
            cout<<endl<<"am repartizat:"<<j<<" timpi";
            AfisRepart(TMax,n,Repart);
            j++;                        ///trecerea la elementul urmator din coada

    }
}

void TimpObtinut(int Tmax, int n, int Repart[100][10]){
    int Min=0;                      ///determinare timp obtinut Max(din timpii pe fiecare masina)
    for(int i=1; i<=n;i++){
        int k=Repart[i][0];
        int Suma=0;
        for(int j=1;j<=k;j++)
           Suma+=Repart[i][j];
        if (Suma>Min) Min=Suma;
    }
    cout<<"Timpul Maxim: "<<Min<<endl;
}


int AfisMeniu(){
    int Opt;
    cout<<"\n1.Citeste date intrare";
    cout<<"\n2.Repartitie cu strategia minimala";
    cout<<"\n0.Terminare program";
    cout<<"\nOptiunea ta(0,1,2,3):";
    cin >>Opt;
    return Opt;
}

int main()
{   Coada C;
    int n, TMax;
    int Repart[100][10];
    int Opt=AfisMeniu();
    while(Opt){
        switch (Opt){
            case 1: CitireDate(C,n);
                    break;
            case 2: Strategia (C,TMax,n,Repart);
                    cout<<"\n\nFinal:";
                    AfisRepart(  TMax,n,Repart);
                    TimpObtinut(TMax,n,Repart);
                    break;
            default:cout<<"\nAi gresit optiunea!!!";
        }
       Opt=AfisMeniu();
    }
    cout <<"\nProgram terminat\n";
    return 0;
}

