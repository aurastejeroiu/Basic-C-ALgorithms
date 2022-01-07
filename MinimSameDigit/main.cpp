#include <iostream>

using namespace std;

void VFrec(int n, int V[]){
  while(n>0){
    V[n%10]++;
    n/=10;
  }
}

int Minim(int n){
   int Min=0;
   int V[10]={0};
   VFrec(n,V);
                    //determina prima cifra nenmula
   int i=1;
   while(i<10 && V[i]==0) i++;
   if(i==10) return Min;
   Min=i;
   V[i]--;
   for(int cif=0;cif<10;cif++)// se face un ciclu de la cif=0,1,2,...,9
     while(V[cif]>0){
        Min=Min*10+cif;
        V[cif]--;
     }
   return Min;
}


int main()
{   int n;
    cout<<"da n=";
    cin >>n;
    cout<<"numarul minim cu aeleasi cifre:"<<Minim(n);
    cout << "\nHello world!" << endl;
    return 0;
}
