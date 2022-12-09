#include <bits/stdc++.h>
using namespace std;
bool czy_pierwsza(int l){
    if (l<2) return false;
    for (int i=2;i<sqrt(l)+1;i++){
        if(l%i==0) return false;
    }
    return true;
}
int main(){
    fstream input("maturki/2020/Dane_PR2/pary.txt");
    ofstream out("maturki/2020/wyniki4.txt");
    int m=99;
    string min="";
    for(int t=0;t<100;t++){
        int l,j;
        string s;
        input>>l;
        input>>s;
        if(l%2==0){
        for(int i=2;i<l;i++){
            if(czy_pierwsza(i)&&czy_pierwsza(l-i)){
                j=i;
                break;
            }
        }
        //cout<<l<<" "<<j<<" "<<l-j<<endl;


        }
        char last=' ';
        string max="",curr="";
        for(auto ch:s){
            if(ch==last){
                curr+=ch;
            }else{
                if(curr.size()>max.size()){
                    max=curr;
                }
                curr=ch;
            }
            last=ch;
        }
        //cout<<max<<" "<<max.size()<<endl;

        if(s.size()==l){
            if(l<m){
                min=s;
                m=l;
            }
            if(l==m&&s<min) min=s;
        }


    }
    cout<<m<<" "<<min<<endl;
    return 0;
}
