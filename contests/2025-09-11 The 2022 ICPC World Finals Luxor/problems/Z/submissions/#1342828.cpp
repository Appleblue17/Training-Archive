#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=44,M=330,K=6,mod=1e7+9;

struct complx {
    int A=0,B=0; // A+B \omega
    void pr(){
        cout<<A<<","<<B<<" ";
    }
};
const complx I={1,0},omega={0,1},omega2={-1,-1};
const complx hexa[6]={I,{1,1},omega,{-1,0},omega2,{0,-1}};

complx operator +(complx x,complx y){
    return (complx){x.A+y.A,x.B+y.B};
}
complx operator -(complx x,complx y){
    return (complx){x.A-y.A,x.B-y.B};
}
complx operator *(complx x,complx y){
    return (complx){x.A*y.A-x.B*y.B,x.B*y.A+x.A*y.B-x.B*y.B};
}
complx operator *(complx x,int y){
    return (complx){x.A*y,x.B*y};
}

void fwtxor(complx *f,int n,int opt){
    for(int k=1;k<n;k*=3){
        for(int i=0;i<n;i+=k*3){
            for(int j=i;j<i+k;j++){
                complx x=f[j],y=f[j+k],z=f[j+k*2];
                // f[j].pr(),y.pr(),z.pr(); cout<<endl;
                
                f[j]=x+y+z;
                f[j+k]=x+y*omega+z*omega2;
                f[j+k*2]=x+y*omega2+z*omega;
                
            }
        }
    }
    if(opt==-1){
        for(int i=0;i<n;i++) f[i].A/=n,f[i].B/=n;
    }
}


int n,k,t;
int pw[K];
char S[K];

inline int neg(int mac){
    int tot=0;
    for(int i=0;i<k;i++){
        int x=mac/pw[i]%3;
        if(x) tot+=(3-x)*pw[i];
    }
    return tot;
}
inline int oplus(int A,int B){
    int tot=0;
    for(int i=0;i<k;i++){
        int x=A/pw[i]%3,y=B/pw[i]%3;
        tot+=(x+y)%3*pw[i];
    }
    return tot;
}

complx P[M],Q[M],R[M];
complx G1[M],G2[M];
int f[M],g0[M];

int p[M],r[M];
complx A[M],B[M],C[M];
bool valid[M];

int q[N],id;
bool dp[N][M],rec[N][M];

signed main(){
    scanf("%lld%lld%lld",&n,&k,&t);
    pw[0]=1;
    for(int i=1;i<=k;i++) pw[i]=pw[i-1]*3;
    
    for(int i=1;i<=t;i++){
        int x;
        scanf("\n%s%lld",S,&x);
        
        int mac=0;
        for(int j=0;j<k;j++){
            if(S[j]=='E') mac+=pw[j];
            else if(S[j]=='I') mac+=pw[j]*2;
        }
        P[mac].A+=x;
        p[mac]+=x;
    }
    fwtxor(P,pw[k],1);
    
    // cout<<"P"<<endl;
    for(int mac=0;mac<pw[k];mac++){
        int A=P[mac].A,B=P[mac].B,r=A?abs(A):abs(B);
        g0[mac]=r;
        Q[mac]={__lg(r),0};
        
        // cout<<mac<<": "; P[mac].pr();
        // cout<<endl;
    }
    
    fwtxor(Q,pw[k],1);
    // for(int mac=0;mac<pw[k];mac++){
    //     cout<<mac<<": "; Q[mac].pr();
    //     cout<<endl;
    // }
    
    f[0]=(Q[0].A/pw[k-1]-n)/2;
    int cnt=0;
    for(int mac=1;mac<=pw[k];mac++){
        if(neg(mac)<mac) continue;
        f[mac]=Q[mac].A/pw[k-1],cnt+=f[mac];
    }
    // for(int mac=0;mac<pw[k];mac++) cout<<f[mac]<<" "; cout<<endl;
    
    //////////////////// 从猜测的 f 计算所有组合情况 ////////////////////
    
    G1[0]=G2[0]={cnt*pw[k-1]};
    for(int mac=1;mac<pw[k];mac++){
        int x=f[mac],y=f[neg(mac)];
        G1[mac]=(complx){-y,x-y}*pw[k-1];
        G2[mac]=(complx){-x,y-x}*pw[k-1];
    }
    fwtxor(G1,pw[k],-1);
    fwtxor(G2,pw[k],-1);
    
    // cout<<"G"<<endl;
    // for(int mac=0;mac<pw[k];mac++){
    //     cout<<mac<<": ";
    //     G1[mac].pr(); G2[mac].pr();
    //     cout<<endl;
    // }
    
    
    for(int mac=0;mac<pw[k];mac++){
        int dir=(G1[mac].A%6+6-G2[mac].A%6+6)%6;
        R[mac]=hexa[dir]*g0[mac];
    }
    fwtxor(R,pw[k],-1);
    
    for(int mac=0;mac<pw[k];mac++) r[mac]=R[mac].A;
    
    //////////////////// 比对 p 和 r ////////////////////
    
    // cout<<"P & R"<<endl;
    // for(int mac=0;mac<pw[k];mac++) cout<<p[mac]<<" "; cout<<endl;
    // for(int mac=0;mac<pw[k];mac++) cout<<r[mac]<<" "; cout<<endl;
    
    int sum1=0,sum2=0;
    for(int mac=0;mac<pw[k];mac++){
        sum1=(sum1+(p[mac]%mod)*(p[mac]%mod)%mod)%mod;
        sum2=(sum2+(r[mac]%mod)*(r[mac]%mod)%mod)%mod;
    }
    for(int mac=0;mac<pw[k];mac++){
        A[mac].A=p[mac]%mod;
        B[neg(mac)].A=r[mac]%mod;
    }
    fwtxor(A,pw[k],1);
    fwtxor(B,pw[k],1);
    for(int mac=0;mac<pw[k];mac++) C[mac]=A[mac]*B[mac];
    fwtxor(C,pw[k],-1);
    
    // cout<<sum1<<" "<<sum2<<endl;
    // for(int mac=0;mac<pw[k];mac++) cout<<C[mac].A<<" "; cout<<endl;
    
    for(int mac=0;mac<pw[k];mac++){
        int rem=(sum1+sum2+mod-2*C[mac].A%mod)%mod;
        valid[mac]=(rem==0);
        // cout<<C[mac].A<<" "<<rem<<endl;
    }
    
    //////////////////// 寻找方案 ////////////////////
    
    for(int mac=0;mac<pw[k];mac++){
        for(int i=1;i<=f[mac];i++) q[++id]=mac;
    }
    
    dp[0][0]=1;
    for(int t=1;t<=id;t++){
        int x=q[t];
        for(int mac=0;mac<pw[k];mac++) dp[t][mac]=dp[t-1][mac];
        for(int mac=0;mac<pw[k];mac++){
            if(dp[t-1][mac]){
                int nmac=oplus(mac,x);
                dp[t][nmac]=rec[t][nmac]=1;
            }
        }
    }
    
    for(int mac=0;mac<pw[k];mac++){
        if(dp[id][mac] && valid[mac]){
            int nw=mac;
            for(int t=id;t>=1;t--){
                int x=q[t],ans=0;
                if(!rec[t][nw]) ans=x;
                else ans=neg(x);
                
                for(int i=0;i<k;i++){
                    int tmp=ans/pw[i]%3;
                    if(!tmp) putchar('0');
                    else if(tmp==1) putchar('+');
                    else putchar('-');
                }
                putchar('\n');
                
                if(rec[t][nw]) nw=oplus(nw,neg(x));
            }
            
            return 0;
        }
    }
    printf("Impossible");
}
