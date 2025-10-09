#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int ans[N];


int cal(int y,int m){
    if(m==2){
        if(y%400==0) return 29;
        if(y%100==0) return 28;
        if(y%4==0) return 29;
        return 28;
    }
    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        return 31;
    }
    else{
        return 30;
    }
}

int solve(int y,int m,int d){
    int tot=cal(y,m);
    ans[y]++;
    for(int i=1;i<=tot;i++){
        // if(y==2025 && m==9 && i==27){
        //     cout<<d<<endl;
        // }
        if(i<tot && d==6) ans[y]++;
        d=(d+1)%7;
    }
    return d;
}

int main(){
    int d=3;
    for(int y=1970;y<=2037;y++){
        for(int m=1;m<=12;m++) d=solve(y,m,d);
    }
    int x; cin>>x;
    cout<<ans[x];
}
