#include <stdio.h>
#include <stdlib.h>


void Multiply2 (int *NrCif, int Nr[2000], int P2[2000]){
  int i,Transport=0;
  int n=*NrCif;
  for (i=0; i< n; i++)
     {P2[i]         =Nr[i]*2 +Transport;    ///se aduna la poz i cifra Nr[i]*2 si cu Transport;
      Transport     =P2[i]/10;	            ///se determina transportul
      P2[i]         =P2[i] % 10;	        ///se retine in P2[i] doar modulo 10
     }
      if(Transport>0){
         P2[n]  =Transport;
         n++;
      }
   *NrCif=n;
}

void AfisareNumar(int NrCif, int P2[2000])
{   int i=NrCif;
    while(P2[i]==0) i--;                    ///cifrele 0 nesemnificative nu le afisez

    int j=i+1;
    while(i>=0){
        printf("%d",P2[i]);
        i--;
    }

    printf("\n");
    printf("numarul are %d cifre\n",j);
}


int main()
{   int NrC=1;
    int *AdNr;
    int Nr[2000], P2[2000];
    int i,j,k;
    Nr[0]=1;
    printf("da exponent:");
    scanf ("%d:",&k);
    for(i=1;i<=k;i++)                       ///Nr se inmulteste iterativ cu 2
      { AdNr=&NrC;
        Multiply2(AdNr,Nr,P2);
                                            ///Copiere P2 in Nr
        NrC=*AdNr;
        for(j=0;j<NrC;j++)
           Nr[j]=P2[j];
      }

    AfisareNumar(NrC,P2);
    printf("\nProgram terminat\n");
    return 0;
}
