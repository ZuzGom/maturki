#include <bits/stdc++.h>
using namespace std;

int bto10 (string bin) {
    int wyn=0;
for(int i=1;i<=bin.size();i++){
wyn += (bin[bin.size()-i] - 48) * pow(2,i-1);
}
return wyn;
}
ofstream output("maturki/2011/zadanie6.txt");
void dec_to_bin(long liczba)
{
	if(liczba>0)
	{
		dec_to_bin(liczba/2);
		output<<liczba%2; 
	}
}


int main(){
    fstream input("maturki/2011/Dane_PR/liczby.txt");
    
    int max=0,s1=0,s2=0;
    long s3=0; 
    string maxi = "";

    for(int t=0;t<1000;t++){
        string liczba;
        input>>liczba;
        int bin = bto10(liczba);
        if(liczba[liczba.size()-1]=='0') s1++;
        if(bin>max){
            max=bin;
            maxi=liczba;
        }
        if(liczba.size()==9){
            s2++;
            s3+=bin;
        }
    }
    output<<"a.\n"<<s1<<endl;
    output<<"b.\n"<<max<<" "<<maxi<<" "<<endl;
    output<<"c."<<endl;
    dec_to_bin(s3);
    return 0;
    }