#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,mod=1e9+123;
// mod-1=2*3*11*2089*7253
const int M[5]={2,3,11,2089,7253};
int R[5];

int T,n,m;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int ksmp(int a,int x,int p){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%p;
        a=a*a%p;
        x>>=1;
    }
    return tot;
}

int mul[5][N],inv[5][N];
void init(){
    for(int t=0;t<5;t++){
        int lim=M[t]-1;
        mul[t][0]=inv[t][0]=1;
        for(int i=1;i<=lim;i++) mul[t][i]=mul[t][i-1]*i%M[t];
        inv[t][lim]=ksmp(mul[t][lim],M[t]-2,M[t]);
        for(int i=lim-1;i>=1;i--) inv[t][i]=inv[t][i+1]*(i+1)%M[t];
    }
}

int p[N],e[N],id;
map <int,int> mp;
int getid(int x){
    if(!mp[x]) mp[x]=++id,p[id]=x,e[id]=0;
    return mp[x];
}

void decomp(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i) continue;
        int u=getid(i);
        while(x%i==0) x/=i,e[u]++;
    }
    if(x>1){
        int u=getid(x);
        e[u]++;
    }
}


int x[N],y[N];
int exgcd(int dep,int a,int b){
	if(!b){
		x[dep]=1,y[dep]=0;
		return a;
	}
	int g=exgcd(dep+1,b,a%b);
	x[dep]=y[dep+1];
	y[dep]=x[dep+1]-a/b*y[dep+1];
	return g;
}
int exCRT(int n,const int *a,int *b){
    // for(int i=0;i<n;i++) cout<<b[i]<<" "; cout<<endl;
	__int128 A=a[0],B=b[0];
	for(int i=1;i<n;i++){
		__int128 g=exgcd(1,A,a[i]),d=b[i]-B;
		if(d%g) assert(0);
		__int128 t=d/g*x[1];
		
		B=t*A+B;
		A=A/g*a[i];
		B=(B%A+A)%A;
	}
    return B;
}

int binom_core(int m,int n,int t){
    int tot=1;
    while(n){
        int m_=m%M[t],n_=n%M[t];
        if(m_<n_) return 0;
        tot=tot*mul[t][m_]%M[t]*inv[t][n_]%M[t]*inv[t][m_-n_]%M[t];
        m/=M[t],n/=M[t];
    }
    return tot;
}

int binom(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    // cout<<m<<" "<<n<<": ";
    for(int t=0;t<5;t++){
        R[t]=binom_core(m,n,t);
        // cout<<R[t]<<" ";
    }
    // cout<<endl;
    
    int res=exCRT(5,M,R);
    return res;
}

int pw[N];
signed main(){
    init();
    
    cin>>T;
    while(T--){
        cin>>n>>m;
        id=0;
        mp.clear();
        int ans=1;
        
        if(n%2==0) decomp(n/2),decomp(n-1);
        else decomp(n),decomp((n-1)/2);
        
        // cout<<" --- start "<<n<<" "<<m<<endl;
        // for(int i=1;i<=id;i++) cout<<p[i]<<" "<<e[i]<<endl;
        
        for(int i=1;i<=id;i++){
            
            pw[0]=1;
            for(int j=1;j<=e[i];j++) pw[j]=pw[j-1]*p[i];
            
            if(p[i]==2){
                for(int t=1;t<=e[i];t++){
                    int d=pw[t]*2;
                    int cur=n-1;
                    
                    int x=1,y=0;
                    int tmp=(cur-x)/d+(cur-y)/d+2;
                    ans=ans*ksm(p[i],binom(tmp,m))%mod;
                    
                    
                    auto upd=[&](int l,int r,int val){
                        l=max(l,2ll);
                        r=min(r,pw[t]);
                        int num=max(0ll,r-l+1);
                        ans=ans*ksm(p[i],binom(val,m)*num%(mod-1))%mod;
                    };
                    
                    int lim=cur%d;
                    // x<=lim, y<=lim => x>=d+1-lim
                    upd(d+1-lim,lim,cur/d*2+2);
                    
                    // x<=lim, y>lim => x<d+1-lim
                    upd(2,min(lim,d-lim),cur/d*2+1);
                    
                    // x>lim, y<=lim => x>=d+1-lim
                    upd(max(lim+1,d+1-lim),pw[t],cur/d*2+1);
                    
                    // x>lim, y>lim => x<d+1-lim
                    upd(lim+1,d-lim,cur/d*2);
                    
                    // for(int x=2;x<=pw[t];x++){
                    //     int y=(d+1-x)%d;
                        
                    //     int num1=(n-1-x)/d+1,num2=(n-1-y)/d+1;
                    //     int A=num1+num2,B=m;
                    //     int res=binom(A,B);
                    //     // if(A>=B) cout<<" (2) "<<t<<" - "<<x<<" "<<y<<" | "<<A<<" "<<B<<" -> "<<res<<endl;
                    //     ans=ans*ksm(p[i],res)%mod;
                    // }
                }
                continue;
            }
            
            int bas=(p[i]+1)/2;
            // cout<<"i = "<<i<<" "<<p[i]<<endl;
            for(int t=1;t<=e[i];t++){
                // cout<<"t = "<<t<<endl;
                int cur=n-1;
                for(int j=0;j<=(t-1)/2;j++){
                    int d=pw[t-j*2];
                    
                    auto upd=[&](int l,int r,int val){
                        l=max(l,2ll)-1;
                        r=min(r,d/2);
                        if(l>=r) return ;
                        // cout<<l<<" "<<r<<" "<<bas<<" "<<p[i]<<endl;
                        // cout<<numl<<" "<<numr<<endl;
                        // int num=0;
                        // cout<<num<<endl;
                        // for(int x=l+1;x<=r;x++){
                        //     if(x%p[i]!=bas) num++;
                        // }
                        
                        int numl=l-(l+p[i]-bas)/p[i];
                        int numr=r-(r+p[i]-bas)/p[i];
                        int num=numr-numl;
                        // cout<<num<<" "<<numr-numl<<endl;
                        
                        ans=ans*ksm(p[i],binom(val,m)*num%(mod-1))%mod;
                    };
                    
                    int x=1,y=0;
                    int tmp=(cur-x)/d+(cur-y)/d+2;
                    ans=ans*ksm(p[i],binom(tmp,m))%mod;
                    
                    int lim=cur%d;
                    // x<=lim, y<=lim => x>=d+1-lim
                    upd(d+1-lim,lim,cur/d*2+2);
                    
                    // x<=lim, y>lim => x<d+1-lim
                    upd(2,min(lim,d-lim),cur/d*2+1);
                    
                    // x>lim, y<=lim => x>=d+1-lim
                    upd(max(lim+1,d+1-lim),d/2,cur/d*2+1);
                    
                    // x>lim, y>lim => x<d+1-lim
                    upd(lim+1,d-lim,cur/d*2);
                    
                    cur=(cur-bas)/p[i];
                }
                
                // j=(t+1)/2;
                int res=binom(cur+1,m);
                // if(cur>=m) cout<<" (ex) "<<t<<" "<<(t+1)/2<<" "<<cur<<" - "<<" | "<<cur<<" "<<m<<" -> "<<res<<endl;
                ans=ans*ksm(p[i],res)%mod;
            }
        }
        cout<<ans<<endl;
    }
    
}