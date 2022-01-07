#include <iostream>

using namespace std;

void SecvComuna(int Xo, int& Xfin, int& Yo,int X[], int LenX,int Y[], int LenY){
    int i,j;
    i=Xo;
    j=Yo;
    while(i<=LenX && j<=LenY && X[i]==Y[j]) { //se determina o secventa comuna
             i++;
             j++;
          }
    Xfin=i;
}


void Comuna(int &Xo, int &Yo, int &Xfin){
    int X[]={0,1,5,8,7,23,4,5,6};
    int Y[]={0,10,2,3,5,8,7,2,3,4,5,8,7,23,100};
    int LenX=8;
    int LenY=14;
    int Yfin;          ///sf secv. comune cea mai lunga
    int Xs,Ys;         ///inceputul secv. comuna in lucru
    int Xf,Yf;         ///sf. secv. comuna in lucru
    int i,j,jjj;
    i=1;
    while(i<=LenX){
      j=1;
      while(j<=LenY && X[i]!=Y[j]) ///se sare peste elementele din Y diferite
        j++;
      if(j<=LenY){                  ///am gasit inceput comun
          Xs=i;
          Ys=j;
          while(j<LenY){            ///se determina cea mai lunga secv ce incepe la Xo in tot vectorul Y
            SecvComuna(Xs,Xfin,Ys,X,LenX,Y,LenY);
            j++;
            Ys=j;
          }
          cout<<Xs<<" "<<Ys<<endl;
          if (i-Xs>Xfin-Xo){
                   Xo=Xs;
                   Xfin=i;
                   Yo=Ys;
               }
          i++;          //se trece la o noua pozitie in X
     }
      else i++;
    }
}
int main(){
    int Xo,Yo;     //inceputul secv. comuna cea mai lunga
    int Xfin;
    Xo=Yo=0;
    Xfin=-1;
    Comuna(Xo,Yo,Xfin);
    //if(Xfin-Xo>0)
          cout<<Xo<<","<<Xfin-1<<endl<<Yo<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
