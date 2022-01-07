#include <iostream>

using namespace std;


void Sterg(int &n, int Sir[], int p){  ///stergerea elem. De pe poz. P, prin mutare la stanga
    for(int i=p;i<n;i++)
        Sir[i]=Sir[i+1];
    n--;
}

void AfisMat(int Nr, int Mat[10][10]){
   for(int i=1; i<=Nr;i++){
      int m=Mat[i][0];
      for(int j=1;j<=m;j++)
        cout<<Mat[i][j]<<",";
      cout<<"\b "<<endl;
   }
}


void SubSir(int& n, int Sir[], int &Nr, int M[10][10]){
   int i=1,k=0;				///i indice pentru Sir, k numara elementele de pe linia Nr
   Nr=1;					///Nr este contor pentru numarul de linii (subsiruri)
   while(i<=n){
     int j=i+1;
     while(j<=n && Sir[i]>Sir[j]) j++;  ///se sare peste elementele care nu sunt Sir[i]<Sir[j]
     M[Nr][++k]=Sir[i];                 ///indiferent conditia de iesire Sir[i] trebuie pus in
     Sterg(n,Sir,i);			        ///matricea M pe linia Nr si Sir[i] se sterge din Sir
     if(j>n)                            ///am ajuns la sfarsitul lui Sir
        {
          M[Nr][0]=k;			///trebuie puse numarul de elemente ale subsirului (k)
          Nr++;				    ///se trece la alt subsir
          k=0;				    ///nr de elemen. ale noului subsir se initializeaza cu 0
          i=1;				    ///se incepe in Sir de la i=1
        }
     else
         i=j-1;				    ///se continua in acelasi subsir cu poz. i=j-1
   }
   Nr--;                    	///la sfarsit trebuie decrementat numarul de subsiruri
}

int main()
{   int Sir[]={0,13, 4, 21, 16, 18, 5, 3};
    int n=7;
    int Nr;
    int M[10][10];
    SubSir(n,Sir,Nr,M);
    cout<<"n="<<n<<endl;
    cout<<"Nr de subsiruri="<<Nr<<endl;

    cout<<"subsirurile sunt:\n";
    AfisMat(Nr, M);
    cout<< "Program terminat" << endl;
    return 0;
}
