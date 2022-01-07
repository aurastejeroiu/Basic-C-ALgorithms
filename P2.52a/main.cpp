#include <iostream>
using namespace std;

void DetSecCML(int n, int X[], int m, int Y[], int& I0, int& dr, int& J0){	///(I0,dr) Secventa finala
   for(int i=1;i<=n;i++){			/// i indice pentru X, (i,i+k) este secventa curenta
      for (int j=1;j<=m;j++) {			/// j indice pentru Y
        int jj=j;			    	/// j, jj indici pentru Y
        while (jj<=m && Y[jj]!=X[i]) jj++;	///sarim In Y peste valori de inceput care nu sunt egale
        if (jj<=m)
        {  int k=1;             		///am gasit 2 pozitii egale X[i] cu Y[jj]
           while (i+k<=n && jj+k<=m && X[i+k]==Y[jj+k]) ///daca conditiile se indeplinesc => se continua
               k++;                                     ///crestem k
           if (k-1>dr-I0)	///la iesire nu mai trebuie testat pe ce conditie am iesit
                                ///(cel putin o egalit este)
           { I0=i;		///se retine seventa mai lunga dintre (I0,Dr) si (i,i+k)
             dr=i+k-1;
             J0=jj;             ///in J0 se retine jj
           }
        }
      }
   }
}

int main()
{  int n=10, X[]={0,51,52,53,54,555,556,57,58,59,555};  ///(2,4)
   int m=14, Y[]={0,4,4,4,52,53,4,4,52,53,54,4,52,53,4};
   int I0=1,dr=0;
   int J0;
   ///Cit(n,X);
   ///Cit(m,Y);
   DetSecCML(n,X,m,Y,I0,dr,J0);
   if (dr-I0>=0){
      cout<<I0<<","<<dr<<" in X"<<endl;
      for(int i=I0;i<=dr;i++)
          cout<<X[i]<<" ";
     cout<<endl<<"in x incepe la:"<<I0<<endl;
     cout<<endl<<"in y incepe la:"<<J0<<endl;
   }
    else cout<<"Nu exista elemente comune"<<endl;
   cout << "\nProgram terminat" << endl;
   return 0;
}
