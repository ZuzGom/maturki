#include <stdio.h>

typedef char napis3[4];
typedef char napis9[10];

#define n 2000

int odp[n];
napis9 num[n];
FILE *we;

void punktA()
{ int i,ile=0;

  for(i=0;i<n;i++) ile+=odp[i];
  printf("Punkt (a):\n");
  printf("Tak: %d\n", ile);
  printf("Nie: %d\n", n - ile);
}

int sumaCyfr(napis9 numer)
{ int i, s=0;

  for(i=0; i<9; i++)
    s = s + (numer[i]-'0');
  return s;
}

int malejacy(napis9 numer)
// wyznacza dlugosc najdluzszego ciagu
// zlozonego malejacego z pocz¹tkowych cyfr
// ciagu numer
{ int i, dl=1, dln=9;

  for(i=1;i<dln;i++){
    if (numer[i]<numer[i-1]) dl++;
    else return dl;
  }
 return dl;
}


void punktB()
{ int i,j,cyf,grupa[9],ile=0;

  for(i=5;i<=8;i++)
    grupa[i]=0;
  for(j=0;j<n;j++){
    cyf=num[j][0]-'0';
    if (cyf>=5 && cyf<=8) grupa[cyf]++;
  }
  printf("Punkt (b):\n");
  for(i=5;i<=8;i++)
    printf("Liczba numerow w grupie %d: %d\n", i, grupa[i]);

}

void punktC()
{ int i,maxpos,maxsuma,aktsuma;

  maxpos = 0;
  maxsuma=sumaCyfr(num[0]);
  for(i=1;i<n;i++) {
    aktsuma = sumaCyfr(num[i]);
    if (aktsuma>maxsuma){
        maxsuma = aktsuma;
        maxpos = i;
    }
  }
  printf("Punkt (c):\n");
  printf("Numer telefonu: %s\n",num[maxpos]);
  printf("Suma cyfr: %d\n",maxsuma);
}

void punktD()
{
  int i,aktD,maxD, maxpos[n],ile=1;

  maxpos[0]=0;
  ile=1;
  maxD = malejacy(num[0]);
  for(i=1;i<n;i++) {
    aktD = malejacy(num[i]);
    if (aktD>maxD)
        maxD = aktD;
  }
  printf("Punkt (d):\n");
  printf("Numery telefonow:\n");
  for(i=0;i<n;i++)
    if (malejacy(num[i])==maxD)
    printf("%s\n",num[i]);
  printf("Dlugosc: %d\n",maxD);
}


int rowne(napis9 n1, napis9 n2)
// sprawdza rownosc dwoch ciagow znakow
// o dlugosci 9 - numerow telefonow
{ int i=1;
  for(i=0;i<9;i++)
    if (n1[i]!=n2[i]) return 0;
  return 1;
}
void punktE()
{
  int i,j,aktE,licznik,maxE=0, maxpos=0;
  int liczony[n];

  for(i=0;i<n;i++) liczony[i]=0;
  for(i=0;i<n;i++) {
     if (!liczony[i]){
        licznik=0;
        for(j=i;j<n;j++)
            if (rowne(num[i],num[j])) {
               liczony[i]++;
               licznik++;
            }
        if (licznik>maxE){
            maxE=licznik;
            maxpos=i;
        }
     }
  }
  printf("Punkt (e):\n");
  printf("Liczba sms-ow: %d\n",maxE);

}


int main()
{  int i;
   char odpBiez[3];

   if ((we=fopen("telefony.txt", "r"))==NULL) {
     printf("Nie moge otworzyc pliku telefony.txt!\n");
     return 1;
     }

   for (i=0;i<n;i++){ // wczytywanie danych
       fscanf(we, "%s %s", num[i], odpBiez);
       if (odpBiez[0]=='T') odp[i]=1;
       else odp[i]=0;
   }

   punktA();
   punktB();
   punktC();
   punktD();
   punktE();

   fclose(we);
   system("PAUSE");
   return 0;
}
