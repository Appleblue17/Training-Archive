#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=126,mod=1e9+7,inv2=(mod+1)/2;
 
int n,W,H,ans;
int invv[N];
int w[N],h[N];
 
void init(int lim){
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
}
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int v1[N],id1;
int v2[N],id2;
 
struct abc{
    int pos1,pos2,vw,vh,iW,iH;
};
 
vector <abc> P[N],Q[N];
 
int f[N][N],g[N][N];
void gmod(int &x){
    x+=(x>>31 & mod);
}
 
void mul(int f[N][N],int A,int B,int C,int D){
    // A+Bx+Cy+Dxy
     
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            f[i][j]=1ll*A*f[i][j]%mod;
            if(B && i) gmod(f[i][j]+=1ll*B*f[i-1][j]%mod-mod);
            if(C && j) gmod(f[i][j]+=1ll*C*f[i][j-1]%mod-mod);
            if(D && i && j) gmod(f[i][j]+=1ll*D*f[i-1][j-1]%mod-mod);
        }
    }
}
 
void div(int f[N][N],int A,int B,int C,int D){
    // A+Bx+Cy+Dxy
    int iA=ksm(A,mod-2);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            f[i][j]=1ll*iA*f[i][j]%mod;
            if(B) gmod(f[i+1][j]-=1ll*B*f[i][j]%mod);
            if(C) gmod(f[i][j+1]-=1ll*C*f[i][j]%mod);
            if(D) gmod(f[i+1][j+1]-=1ll*D*f[i][j]%mod);
        }
    }
}
 
void pr(int f[N][N]){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
 
signed main() {
    init(N-5);
     
    cin>>n>>W>>H;
    for(int i=1;i<=n;i++) cin>>w[i]>>h[i];
     
    for(int i=1;i<=n;i++){
        v1[++id1]=min(w[i],W-w[i]);
        v2[++id2]=min(h[i],H-h[i]);
    }
    sort(v1,v1+id1+1);
    id1=unique(v1,v1+id1+1)-v1-1;
    sort(v2,v2+id2+1);
    id2=unique(v2,v2+id2+1)-v2-1;
     
    v1[id1+1]=1ll*W*inv2%mod;
    v2[id2+1]=1ll*H*inv2%mod;
     
    // for(int i=1;i<=id1+1;i++) cout<<v1[i]<<" "; cout<<endl;
    // for(int i=1;i<=id2+1;i++) cout<<v2[i]<<" "; cout<<endl;
     
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        int iW=ksm(W-w[i],mod-2);
        int iH=ksm(H-h[i],mod-2);
         
        int pos1=lower_bound(v1,v1+id1+1,min(w[i],W-w[i]))-v1;
        int vw=min(w[i],W-w[i])%mod;
         
        int pos2=lower_bound(v2,v2+id2+1,min(h[i],H-h[i]))-v2;
        int vh=min(h[i],H-h[i])%mod;
         
        abc tmp={pos1,pos2,vw,vh,iW,iH};
        P[pos1].push_back(tmp);
        Q[pos2].push_back(tmp);
         
        // cout<<"> "<<pos1<<" "<<pos2<<" "<<w[i]<<" "<<h[i]<<"   "<<vw<<" "<<vh<<" "<<iW<<" "<<iH<<endl;
        mul(f,1,0,0,(mod-1ll*iW*iH%mod)%mod);
    }
     
    for(int t=0;t<=id1;t++){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                g[i][j]=f[i][j];
         
        for(int s=0;s<=id2;s++){
            int Lw=v1[t],Rw=v1[t+1];
            int Lh=v2[s],Rh=v2[s+1];
             
            int Lws,Rws,Lhs,Rhs;
            Lws=1,Rws=1;
            for(int i=0;i<=n;i++){
                Lws=1ll*Lws*Lw%mod,Rws=1ll*Rws*Rw%mod;
                Lhs=1,Rhs=1;
                int A=1ll*(Rws+mod-Lws)%mod*invv[i+1]%mod;
                int tot=0;
                for(int j=0;j<=n;j++){
                    Lhs=1ll*Lhs*Lh%mod,Rhs=1ll*Rhs*Rh%mod;
                    int B=1ll*(Rhs+mod-Lhs)*invv[j+1]%mod;
                    gmod(tot+=1ll*B*g[i][j]%mod-mod);
                }
                gmod(ans+=1ll*A*tot%mod-mod);
            }
             
            for(abc R: Q[s+1]){
                if(t<R.pos1){
                    div(g,1,0,0,(mod-1ll*R.iW*R.iH%mod)%mod);
                    mul(g,1,(mod-1ll*R.iW*R.iH%mod*R.vh%mod)%mod,0,0);
                }
                else{
                    div(g,1,0,(mod-1ll*R.iW*R.iH%mod*R.vw%mod)%mod,0);
                    mul(g,(1+mod-1ll*R.iW*R.iH%mod*R.vw%mod*R.vh%mod)%mod,0,0,0);
                }
            }
        }
         
        for(abc R: P[t+1]){
            div(f,1,0,0,(mod-1ll*R.iW*R.iH%mod));
            mul(f,1,0,(mod-1ll*R.iW*R.iH%mod*R.vw%mod),0);
        }
    }
     
    cout<<(1ll*H*W%mod+mod-1ll*ans*4%mod)%mod;
}
