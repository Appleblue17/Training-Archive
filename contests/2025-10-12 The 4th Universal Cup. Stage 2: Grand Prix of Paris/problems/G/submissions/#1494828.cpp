#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T, n, d;
char s[N];
int L[N], R[N], len[N];
bool flag=0;
bool readstr(int st){
    char c=getchar();
    if(c==EOF||flag) return false;
    while(c!='\n'){
        if(c==EOF) {
            flag=1;
            return true;
        }
        if(c!='\n' && c!='\r'){
            s[st]=c;
            ++st; 
        }
        c=getchar();
    }
    return true;
}

bool valid[N];


bool cmp(string &S,int t){
    if(S.length()!=R[t]-L[t]+1) return 0;
    for(int i=0;i<S.length();i++){
        if(S[i]!=s[i+L[t]]) return 0;
    }
    return 1;
}

string rec[N],S,P,Q;
bool chk(int t){
    S.clear(); P.clear(),Q.clear();
    int id=0;
    bool fl=0;
    for(int i=L[t];i<=R[t];i++){
        if(s[i]==','){
            fl=1;
            break;
        }
        if(s[i]==' ') return 0;
        S+=s[i];
    }
    if(!fl) return 0;
    P=S+", "+S+" "+S+"ity "+S;
    Q="i said "+S+", "+S+" "+S+"ity "+S;
    return cmp(P,t) && cmp(Q,t+1);
}

signed main(){
    // freopen("Gin.txt","r",stdin);
    while(readstr(R[n]+1)){
        ++n;
        L[n]=R[n-1]+1;
        len[n]=strlen(s+R[n-1]+1);
        R[n]=L[n]+len[n]-1;
    }
    // for(int i=1; i<=n; ++i){
    //     for(int j=L[i]; j<=R[i]; ++j){
    //         putchar(s[j]);
    //     }
    //     putchar('\n');
    // }
    
    for(int i=1;i<n;i++){
        valid[i]=chk(i);
        if(valid[i]) rec[i]=S;
        // cout<<valid[i]<<" "<<rec[i]<<endl;
    }
    
    int ans=-1;
    for(int f=0;f<=1;f++){
        for(int l=f,r;l<=n;l=r+2){
            r=l;
            if(!valid[l]) continue;
            while(r+2<=n && valid[r+2] && rec[r+2]==rec[l]) r+=2;
            
            ans=max(ans,R[r+1]-L[l]+1+(r+1-l+1));
        }
    }
    cout<<ans;
}
