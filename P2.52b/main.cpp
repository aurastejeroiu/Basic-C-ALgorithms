#include <iostream>
using namespace std;

void CeaMaiLunga(int i, int jj, int& pozi, int n,int X[], int m,int Y[]){
         pozi=i;             ///am gasit 2 pozitii egale X[i] cu Y[jj]
  int    pozj=jj;
  while (pozi<=n && pozj<=m && X[pozi]==Y[pozj]) ///daca conditiile se indeplinesc => se continua
    { pozi++;                ///crestem in X
      pozj++;                ///crestem in Y
    }
}

void DetSecCML(int n, int X[], int m, int Y[], int& st, int& dr, int& stY){
   for(int i=1;i<=n;i++){		/// i indice pentru X
      for (int j=1;j<=m;j++) {	/// (i,pozi) este secventa curenta
        int pozi;			    /// pozi indice pentru X  de parcurgere
        int jj=j;			    /// j, jj indici pentru Y

        while (jj<=m && Y[jj]!=X[i]) jj++;	///sarim peste valori de inceput care nu sunt egale
        if (jj<=m)
        {                       ///am gasit 2 pozitii egale X[i] cu Y[jj]
           CeaMaiLunga(i,jj,pozi,n,X,m,Y);
           if (pozi-i-1>dr-st)	///la iesire nu mai trebuie testat pe ce conditie am iesit (cel putin o egalit este)
           { st=i;			    ///se retine seventa mai lunga dintre (i,pozi) si (st,dr)
             dr=pozi-1;
             stY=jj;
           }
        }
      }
   }
}

int main()
{  int n=10, X[]={0,12,11,1,3,4,3,4,16,200,5};  ///(6,8)
   int m=14, Y[]={0,12,11,3,4,11,12,11,3,4,16,181,191,111,2111};
   int st=1,dr=0;
   int stY;
   ///Cit(n,X);
   ///Cit(m,Y);
   DetSecCML(n,X,m,Y,st,dr,stY);
   if (dr-st>=0){
      cout<<st<<","<<dr<<endl;
      for(int i=st;i<=dr;i++)
          cout<<X[i]<<" ";
     cout<<endl<<"in x incepe la:"<<st<<endl;
     cout<<endl<<"in y incepe la:"<<stY<<endl;
   }
    else cout<<"Nu exista elemente comune"<<endl;
   cout << "\nProgram terminat" << endl;
   return 0;
}
