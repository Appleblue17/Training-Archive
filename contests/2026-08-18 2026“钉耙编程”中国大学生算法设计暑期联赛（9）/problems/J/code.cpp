#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int T,n,m;
char S[N];
int s[N];

int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

int S2(int x){
    return x*(x+1)/2;
}

pair <int,int> get_range(int x,int y,int d){
    int mn,mx;
    mx=S2((x+y+d)/2)-S2(y);
    if(d<x+y) mn=S2(x)-S2((x+y-d)/2);
    else mn=S2(x)+(d-x-y)/2;
    return {mn,mx};
}


signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("\n%s",S+1);
        
        bool fl=1;
        for(int i=1;i<=n;i++) if(S[i]=='?') fl=0;
        if(fl){
            for(int i=1;i<=n;i++) putchar(S[i]);
            putchar('\n');
            continue;
        }
        
        int st=0; while(st+1<=n && S[st+1]!='?') st++;
        int ed=n+1; while(ed-1>=1 && S[ed-1]!='?') ed--;
        
        s[0]=s[n]=0;
        for(int i=1;i<=st;i++){
            s[i]=s[i-1]+((S[i]=='(')?1:-1);
            if(S[i]==')') m-=s[i-1];
        }
        for(int i=n;i>=ed;i--){
            s[i-1]=s[i]-((S[i]=='(')?1:-1);
            if(S[i]==')') m-=s[i-1];
        }
        
        // cout<<" left m = "<<m<<endl;
        
        for(int i=st+1;i<ed;i++){
            int d=(ed-1)-(i-1);
            int x=s[i-1],y=s[ed-1];
            
            pair<int,int> nw=get_range(x+1,y,d-1);
            
            // cout<<i<<": "<<x<<" "<<y<<" "<<d<<" -> "<<nw.first<<" "<<nw.second<<endl;
            if(nw.first<=m && m<=nw.second){
                S[i]='(';
                s[i]=s[i-1]+1;
            }
            else{
                S[i]=')';
                s[i]=s[i-1]-1;
                m-=s[i-1];
            }
        }
        
        for(int i=1;i<=n;i++) putchar(S[i]);
        putchar('\n');
    }
    
}