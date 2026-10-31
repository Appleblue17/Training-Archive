#include<bits/stdc++.h>
using namespace std;
const int N = 210000;
int T,r;

int main(){
    cin>>T;
    while(T--){
        cin>>r;
        printf("%d %d\n",-r,0);
        printf("%d %d\n",0,-r);
        printf("%d %d\n",r,0);
        printf("%d %d\n",0,r);
        printf("%d %d\n",1,r+1);
        printf("%d %d\n",r+1,1);
    }
}