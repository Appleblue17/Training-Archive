#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5,INF=1e9;
int n;
char s[N];
int pos[26];
int p[N];

int f[N];

int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    
    reverse(s+1,s+n+1);
    
    for(int i=1;i<=n;i++){
        int c=s[i]-'a';
        p[i]=pos[c];
        pos[c]=i;
    }
    
    // for(int i=1;i<=n;i++) cout<<p[i]<<" "; cout<<endl;
    
    int ans=0;
    for(int i=1;i<=n;i++){
        int mn=INF;
        for(int j=p[i];j<i;j++) mn=min(mn,f[j]);
        f[i]=mn+1;
        ans=max(ans,f[i]);
    }
    // for(int i=1;i<=n;i++) cout<<f[i]-1<<" "; cout<<endl;
    cout<<ans;
}
