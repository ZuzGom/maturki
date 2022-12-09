#include <bits/stdc++.h>
using namespace std;

bool czy_sym(vector<int> v){
    for(int i=0;i<v.size()/2;i++){
        if(v[i]!=v[v.size()-1-i]) return false;
    }
    return true;
}


int main(){
    vector<vector <int>> pix;
    fstream input("maturki/2017/Dane_PR2/dane.txt");
    ofstream out("maturki/2017/wyniki6.txt");
    int max=0,min=256,sym=0,sum=0;
    for (int x = 0;x<200;x++){
        vector <int> pom;
        for(int y = 0;y<320;y++){
            int p;
            input>>p;
            if(p<min) min=p;
            if(p>max) max=p;
            pom.push_back(p);
        }
        if(czy_sym(pom)) sym++;
        pix.push_back(pom);
    }

    for (int x = 0;x<200;x++){
        for(int y = 0;y<320;y++){
            int l=0;
            if(x>0) if(pix[x-1][y]-pix[x][y]>128||pix[x-1][y]-pix[x][y]<-128) l++;
            if(y>0) if(pix[x][y-1]-pix[x][y]>128||pix[x][y-1]-pix[x][y]<-128) l++;
            if(x<119) if(pix[x+1][y]-pix[x][y]>128||pix[x+1][y]-pix[x][y]<-128) l++;
            if(y<319) if(pix[x][y+1]-pix[x][y]>128||pix[x][y+1]-pix[x][y]<-128) l++;

            if(l>0) sum++;

        }
    }
    out<<max<<endl;
    out<<min<<endl;
    out<<200-sym<<endl;
    out<<sum<<endl;
    return 0;
    }