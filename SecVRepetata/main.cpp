#include <iostream>
using namespace std;
//cea mai lunga secventa comuna a doi vectori
void DetSecCML(int m, int X[],  int& I0, int& lung, int& J0){
                                ///(I0,I0+lung-1) Secventa finala in X
   for(int i=1;i<=m;i++){	    /// i indice pentru X, (i,i+k) este secventa curenta
      for (int j=i+1;j<=m;j++) {	/// j indice pentru X
        int k=0;		        /// k pentru deplasament
                                /// verificam daca exista secventa egale ce incep in i si j
        while ((i+k<=m) && (j+k<=m) && (X[i+k]==X[j+k]))
            k++;

        if (k>=lung) 		///  la iesire nu mai trebuie testat pe ce conditie am iesit
                        	///  (cel putin o inegalitate  este falsa)
           { I0  =i;		///  se retine secventa mai lunga dintre (I0,I0+lung-1)
             lung=k;        ///  si (i,i+k-1)
             J0  =j;      	///  in J0 se retine j
           }
        }
      }
}

int main()
{  int m=10, X[]={0,5,5,1,2,5,5,10,5,5};
   int I0=0,lung=0;
   int J0=0;
   ///Cit(n,X);
   ///Cit(m,Y);
   DetSecCML(m-1,X,I0,lung,J0);
   if (lung>0){
      if(I0!=J0)
      {cout<<endl<<"in x incepe la I0="<<I0<<endl;
       cout<<endl<<"in x incepe la J0="<<J0<<endl;
       cout<<"si are lungimea:"<<lung<<endl;
       for(int i=I0;i<=I0+lung-1;i++)
           cout<<X[i]<<" ";
      }
      else cout<<"nu exista secv. care se repeta sau e sir constant";

   }
     else cout<<"Elemente distincte"<<endl;
   cout << "\nProgram terminat" << endl;
   return 0;
}
