#include <bits/stdc++.h>

using namespace std;
class miasto{
    public:
    int ile=1;
    string kod;
    miasto(string akod){
        kod=akod;
    }
};
bool check(vector <miasto> m,string n){
    for (auto x:m) if (x.kod==n) return true;
    return false;
}
int main(){
    fstream input("Dane_2103/galerie.txt");
    ofstream output("wynik4_1.txt");
    string c;
    vector <miasto> miasta;
    for (int t =0 ;t<50;t++) {
        string kod, nazwa;
        int x,y;
        input>> kod>>nazwa;
        for(int i=0;i<70;i++){
            input>>x>>y;
        }
        if (check(miasta,kod)){
            for(auto& x:miasta){
                if (x.kod==kod) x.ile++;
            }
        }
        else miasta.push_back(miasto(kod));
        //cout<<kod<<nazwa<<endl;

    }
    for(auto x:miasta){
        output<<x.kod<<" "<<x.ile<<endl;
    }
    
    return 0;
}