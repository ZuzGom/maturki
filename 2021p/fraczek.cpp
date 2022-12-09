#include <bits/stdc++.h>

using namespace std;
unordered_map <string , vector<int>> haszumapu;


int main(){
        haszumapu["krasik123"].push_back(3);
        haszumapu["zuzi463"].push_back(36);
        
        for(auto n:haszumapu){

            cout<<n.first<<endl;
            cout<<n.second[0]<<endl;

        } 
    return 0;
}