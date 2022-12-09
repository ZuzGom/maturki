#include <bits/stdc++.h>
using namespace std;

bool pierwsza(int l){
    if (l<2) return false;
    for (int i=2;i<sqrt(l)+1;i++){
        if(l%i==0) return false;
    }
    return true;
}


bool check(vector<int> v, int x){
    for (auto a:v) if (x==a) return true;
    return false;
}

bool hepi(int licz){
vector <int> ciag;
        int j=licz;
        string l=to_string(j);
        ciag.push_back(j);
        while(j!=1){
            //cout<<l<<" ";
            
            int sum=0;
            for(auto x:l) sum+=(x-48)*(x-48);
            j=sum;
            if (check(ciag,j)) {
                ciag.clear();
                return false;
            }
            ciag.push_back(j);
            
            l=to_string(sum);
            //cout<<j<<" ";
            
        }
return true;
        
}


int main(){

    fstream dane;
    ofstream wyn;
    dane.open("dane//liczby.txt");
    wyn.open("wynik4.txt");

    wyn<<"4.1"<<endl;
    vector <int> wyni;
    for (int i=1;i<=1000;i++){
        vector <int> ciag;
        int j=i;
        string l=to_string(j);
        ciag.push_back(j);
        while(j!=1){
            //cout<<l<<" ";
            
            int sum=0;
            for(auto x:l) sum+=(x-48)*(x-48);
            j=sum;
            if (check(ciag,j)) {
                ciag.clear();
                break;
            }
            ciag.push_back(j);
            
            l=to_string(sum);
            //cout<<j<<" ";
            
        }
        
        
        if (ciag.size()>wyni.size()){
            wyni=ciag;
            for(auto x:ciag) cout<<x<<" ";
            cout<<endl;

        }
        if (ciag.size()==7){
            cout<<ciag[0]<<endl;

        }

    }
    wyn<<wyni.size()<<endl;
    for (auto x:wyni) wyn<<x<<" ";
        wyn<<endl;
    //cout<<wynik.size()<<endl;


    
    string liczba;
    queue<string> ciag;
    queue<string> wynik;
    int s=0, licznik1=0, licznik2=0;
    while (!dane.eof()){
        dane>>liczba;
        
        if (hepi(stoi(liczba))==true) {
            licznik1 ++;
            if (pierwsza(stoi(liczba))==true) {
                cout<<liczba<<endl;
                licznik2++;
            }
            ciag.push(liczba);
            //cout<<ciag.size()<<endl;
            

        }
        else {
            if (s<ciag.size()){
                s = ciag.size();
                wynik=ciag;
            }
            while (!ciag.empty()) ciag.pop();
        }

    }

    wyn<<"4.2"<<endl;
    wyn<<licznik1<<endl;
    wyn<<"4.3"<<endl;
    wyn<<wynik.size()<<" "<<wynik.front()<<" "<<wynik.back()<<endl;
    wyn<<"4.4"<<endl;
    wyn<<licznik2<<endl;
    wyn.close();
    return 0;
}
