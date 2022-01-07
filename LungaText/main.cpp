#include <iostream>
#include <cstring>
using namespace std;
//cea mai lunga secventa comuna a doi vectori


void DetSecCML(int m, char X[], int& I0, int& lung, int& J0){
                                ///(I0,I0+lung-1) Secventa finala in X
   for(int i=0;i<m;i++){	    /// i indice pentru X, (i,i+k) este secventa curenta
      for (int j=i+1;j<m;j++) {	/// j indice pentru X, pentru a 2-a secevnta
        int k=0;		        /// k pentru deplasament
                                /// verificam daca exista secventa egale ce incep in i si j
        while ((i+k<m) && (j+k<m) && (X[i+k]==X[j+k]))
            k++;

        if (k>lung) 		///  la iesire nu mai trebuie testat pe ce conditie am iesit
                        	///  (cel putin o inegalitate  este falsa)
           { I0  =i;		///  se retine secventa mai lunga dintre (I0,I0+lung-1)
             lung=k;        ///  si (i,i+k-1)
             J0  =j;      	///  in J0 se retine j
           }
        }
      }
}

int main()
{
   char X[]={"VasileconstataAnaAremereAnaareMere"};
   int m=strlen(X);
   int I0=0,lung=0;
   int J0=0;
   ///Cit(n,X);
   ///Cit(m,Y);
   DetSecCML(m,X,I0,lung,J0);
   if (lung>0){
      cout<<endl<<"prima incepe la I0="<<I0<<endl;
      cout<<endl<<"a doua incepe la J0="<<J0<<endl;
      cout<<"si are lungimea:"<<lung<<endl;
      cout<<"\"";
      for(int i=I0;i<=I0+lung-1;i++)
          cout<<X[i];
      cout<<"\"";
   }
   else cout<<"Nu exista secventa care se repeta"<<endl;

   cout << "\nProgram terminat" << endl;
   return 0;
}
