#include <iostream>
#include <string.h>

using namespace std;

bool Descentrat(char Cuv1[], char Cuv2[]){
    int L1=strlen(Cuv1);
    int L2=strlen(Cuv2);
    char Cuv3[20];
    if(L1==1 && L2==2)
      {if(Cuv1[0]==Cuv2[0] && Cuv1[0]==Cuv2[1]) return true;
       else return false;
      }
    if (L1==2 && L2==1)
      {if(Cuv1[0]==Cuv2[0] && Cuv1[1]==Cuv2[0]) return true;
       else return false;
      }

    if(L1==L2+1 && L1%2==0){
          strcpy(Cuv3,Cuv1);
          strcpy(Cuv3+L1/2,Cuv1+L1/2+1);
          if(strcmp(Cuv3,Cuv2)==0) return true;
        }
    if(L2==L1+1 && L2%2==0){
          strcpy(Cuv3,Cuv2);
          strcpy(Cuv3+L2/2,Cuv2+L2/2+1);
          if(strcmp(Cuv3,Cuv1)==0) return true;
        }
    return false;
}

int main()
{   char Cuv[15][20];       ///Cuv[i]=e linia a
    char Prop[101]="crezi ca poti sa creeeezi ceva original ";
    int i=0,j=0;
    while(j<=strlen(Prop)){
        if(Prop[j]==' ') {
            Cuv[i][j]='\0';
            strcpy(Prop,Prop+j+1);
            j=0;
            i++;
        }
        else
            {Cuv[i][j]=Prop[j];
             j++;
            }
    }
    int n=i;
    for(i=0;i<n;i++)
        cout<<Cuv[i]<<endl;
    i=0;
    while (i<n-1){
        j=i+1;
        while(j<n){
           if(Descentrat(Cuv[i],Cuv[j])) {cout<<"Da";
                                           j=n;i=n; ///am terminat
                                         }
           else j++;
        }
        i++;
        if(i==n-1) cout<<"Nu";
    }
    cout << "\nHello world!" << endl;
    return 0;
}
