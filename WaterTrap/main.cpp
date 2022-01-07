#include <iostream>
#include <iomanip>
using namespace std;

void Citire(int &n, int X[]){
  int i;
  cout<<"da dim sirului:"; cin>>n;
  for(i=1;i<=n;i++){
     cout<<"X["<<i<<"]=";
     cin >>X[i];
  }
}

void AfisVF(int nr, int VF[]){
  if(nr>0) {
   cout<<"varfurile sunt:";
   for (int i=1;i<=nr;i++) cout<<setw(3)<<VF[i];
  }
  else
      cout<<"nu exista varfuri";
}

void Varfuri (int n, int X[], int& k, int VF[]){///k= lungimea  vect. de varfuri
   k=0;
   if (X[1]>X[2])  VF[++k]=1;   ///pentru primele 2 elemente

   for(int i=2;i<n;i++)
     if ((X[i]>X[i-1]) and (X[i]>X[i+1]))
         VF[++k]=i;

   if (X[n-1]<X[n])             ///pentru ultimele 2 elemente
        VF[++k]=n;
}


void Sterge(int &k,int VF[],int poz)
{  for(int i=poz;i<k;i++)       ///se muta tot vectorul la stanga de la pozitia poz
        VF[i]=VF[i+1];
    k--;                        ///lungimea lui VF se micsoreaza cu 1
}
void EliminVF(int &k, int VF[], int X[])
{
      int i=2;
      while(i<=k-1)
        {if((X[VF[i]]<=X[VF[i-1]]) and (X[VF[i]]<=X[VF[i+1]]))
            Sterge(k,VF,i);
         else
            if(X[VF[i]]==X[VF[i-1]])
                Sterge(k,VF,i-1);
            else i++;
        }
      cout<<endl;

}


int CalculVol(int k,int  VF[],int X[])
{   int Vol,i,j,mini;
    Vol=0;
    i=1;
    while(i<=k-1){
        if(X[VF[i]]<X[VF[i+1]]) mini=X[VF[i]];      //determinarea minimului intre doua varfuri mari
        else                    mini=X[VF[i+1]];

        for (j=VF[i]+1;j<=VF[i+1]-1;j++)
             Vol+=(mini-X[j]);
        i++;
     }
    return Vol;
}
int main(){
   int X[100],VF[100];
   int n,k;                 ///n lung. lui X iar k lung lui VF
   Citire   (n,X);
   Varfuri  (n,X,k,VF);
   AfisVF   (k,VF);
   EliminVF (k,VF,X);       ///elimin varfuri intermediare mici
   cout<<   endl<< "dupa eliminare varfuri mici ";
   AfisVF   (k,VF);
   cout<<   endl<<"volumul de apa="<<CalculVol(k,VF,X);
   cout<<   endl<<"Program terminat";
   return 0;
}
