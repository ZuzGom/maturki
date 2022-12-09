#include <bits/stdc++.h>

using namespace std;

    
int main(){
    fstream input("maturki/2008/dane/slowa.txt");
    ofstream out1("maturki/2008/hasla_b.txt");
    ofstream out2("maturki/2008/slowa_b.txt");
    string maxi, mini;
    int max=0, min=31;
    long suma=0;
    out2<<"1."<<endl;
    for(int t=0;t<1000;t++){
        string slowo;
        input>>slowo;
        
        int j=slowo.size()-1,i=0;

        while (j>=0){
            if (slowo[i]==slowo[j]) i++;
            else i=0;
            j--;
        }
        string start="";
        for(int j=slowo.size()-1;j>i;j--){
            start+=slowo[j];
        }
        string wyn="";
        wyn+=start+slowo;
        out1<<wyn<<endl;
        if (wyn.size()==12) out2<<wyn<<endl;
        if (wyn.size()>max){
            maxi = wyn;
            max = wyn.size();
        }
        if (wyn.size()<min){
            mini = wyn;
            min = wyn.size();
        }
        suma+=wyn.size();
    }
    out2<<"2."<<endl;
    out2<<max<<" "<<maxi<<endl;
    out2<<min<<" "<<mini<<endl;
    out2<<"3."<<endl;
    out2<<suma<<endl;

    return 0;
}