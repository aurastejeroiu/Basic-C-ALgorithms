#include <iostream>
#include <climits>
#include <fstream>

using namespace std;


int Max(int X[],int n){
   if(X[1]>=X[2])   return X[1];
   else             return X[n];

}

bool Progresie(int X[], int n){
     int i=2;
     while(i<n && X[i]*2==X[i-1]+X[i+1])
         i++;
     if(i==n) return true;
              return false;

}


int main()
{   int X[101];
    int M=INT_MIN;
    ifstream  f("Linii.txt");
    int n,i=1;
    f>>n;
    while(!f.eof()){
        while(i<=n){
            f>>X[i++];
        }
        int ML=Max(X,n);
        if(Progresie(X,n) && ML> M) M=ML;
        i=1;
    }

    cout << "Maxim="<<M << endl;
    return 0;
}
