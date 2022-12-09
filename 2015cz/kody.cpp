#include <bits/stdc++.h>

using namespace std;


int main(){
    string kody[10]={"10101110111010", "11101010101110", "10111010101110" ,"11101110101010" , "10101110101110" , 
    "11101011101010" , "10111011101010" ,"10101011101110" , "11101010111010" , "10111010111010"};
    string start = "11011010",stop="11010110";
    fstream input("maturki/2015cz/dane/kody.txt");
    ofstream out1("maturki/2015cz/kody1.txt");
    ofstream out2("maturki/2015cz/kody2.txt");
    ofstream out3("maturki/2015cz/kody3.txt");
    for(int t=0;t<500;t++){
        int liczba;
        input>>liczba;
        //cout<<liczba<<endl;
        string str = to_string(liczba);
        int s1=0,s2=0;
        for(int i=5;i>=0;i--){
            s1+=str[i]-48;
            i--;
            s2+=str[i]-48;
        }
        int k = (10 - (s1*3 +s2)%10)%10;
        out1<<s1<<" "<<s2<<endl;
        out2<<k<<" "<<kody[k]<<endl;
        string wyn = "";
        wyn+=start;
        for (int i=0;i<6;i++) wyn+=kody[str[i]-48];
        
        wyn+=kody[k]+stop;
        out3<<wyn<<endl;


    }
    return 0;
}
