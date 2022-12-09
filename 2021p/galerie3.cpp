#include <bits/stdc++.h>

using namespace std;
class miasto{
    public:
    int ile;
    string kod;
    miasto(string akod){
        kod=akod;
    }
};


int main(){
    fstream input("Dane_2103/galerie_przyklad.txt");
    ofstream output("wynik4_3.txt");
    
    string mins,maxs;
    for (int t =0 ;t<10;t++) {
        int tab[4760];
        for(auto& x:tab)x=0;
        string kod, nazwa;
        int x,y;
        long suma=0;
        int licznik=0;
        input>>kod>>nazwa;
        for(int i=0;i<70;i++){
            input>>x>>y;
            int iloczyn=y*x;
            tab[iloczyn]++;
            if(x!=0&&y!=0) licznik++;
        }
        int ilosc=0;
        for (int i=0;i<4760;i++)
        {
            if(tab[i]==1) ilosc++;
        }
        cout<<ilosc<<" "<<t<<endl;


    }
    return 0;
}