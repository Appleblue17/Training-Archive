#include <bits/stdc++.h>
using namespace std;
int n,a,b;
string S;

bool fl1,fl2;

int main(){
    cin>>n>>a>>b;
    if(a>n+1-a) a=n+1-a,fl1=1;
    if(b>n+1-b) b=n+1-b,fl2=1;
    
    for(int i=1;i<=n-1;i++) S+="LU";
    for(int i=1;i<a;i++) S+="D";
    for(int i=1;i<b;i++) S+="R";
    for(char c: S){
        if(c=='L' || c=='R'){
            if(fl2) putchar('L'+'R'-c);
            else putchar(c);
        }
        else{
            if(fl1) putchar('U'+'D'-c);
            else putchar(c);
        }
        
    }
    
    // cout<<endl<<S.length()<<" "<<3*(n-1)<<endl;
}
