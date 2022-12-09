#include <bits/stdc++.h>

using namespace std;

int main(){
    fstream input("Dane_2103/galerie.txt");
    ofstream output("wynik4_2b.txt");
    int min=999999;
    int max=0;
    string mins,maxs;
    for (int t =0 ;t<50;t++) {
        string kod, nazwa;
        int x,y;
        long suma=0;
        int licznik=0;
        input>> kod>>nazwa;
        for(int i=0;i<70;i++){
            input>>x>>y;
            suma+=y*x;
            if(x!=0&&y!=0) licznik++;
        }
        if (suma>max){
            max=suma;
            maxs=nazwa;
        }
        if (suma<min){
            min=suma;
            mins=nazwa;
        }
        

    }
    input<<maxs<<" "<<max<<endl;
    input<<mins<<" "<<min<<endl;
    return 0;
}