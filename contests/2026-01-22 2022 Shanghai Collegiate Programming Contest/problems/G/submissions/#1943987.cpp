#include<bits/stdc++.h>
using namespace std;
int T, B, R, D, S;
int main(){
    cin>>T;
    while(T--){
        cin>>B>>R>>D>>S;
        if(R==0){
            if(D==0) cout<<"ok"<<endl;
            else cout<<"gua!"<<endl;
            continue;
        }
        int x=S*R/60;
        x++;
        if(D<=B*x) cout<<"ok"<<endl;
        else cout<<"gua!"<<endl;
    }
}
