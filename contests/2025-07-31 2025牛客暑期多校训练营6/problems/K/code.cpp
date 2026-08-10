#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;
 
vector <int> D[N];
void init(int lim){
    for(int i=2;i<=lim;i++){
        if(D[i].size()) continue;
        for(int x=i;x<=lim;x*=i){
            for(int j=x;j<=lim;j+=x) D[j].push_back(x);
            if(1ll*x*i>lim) break;
        }
    }
}
int cal(int x,int y){
    return __gcd(abs(x),abs(y));
}
 
 
int T,n;
int a[N],b[N];
int f[19][N];
int qry(int l,int r){
    if(l>r) return 0;
    int x=log2(r-l+1);
    return cal(f[x][l],f[x][r-(1<<x)+1]);
}
 
 
int p[N],id;
vector <int> V[N];
 
signed main() {
    init(N-5);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int mx=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
        for(int i=n;i>=1;i--) b[i]=a[i]-a[i-1];
         
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=(b[i]!=0);
        if(cnt==1){
            printf("0\n");
            continue;
        }
        if(cnt==2){
            printf("%d\n",mx);
            continue;
        }
         
        // for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
         
        for(int i=1;i<=n;i++) f[0][i]=b[i];
        for(int t=1;t<=18;t++){
            for(int i=1;i<=n-(1<<t)+1;i++){
                f[t][i]=cal(f[t-1][i],f[t-1][i+(1<<(t-1))]);
            }
        }
         
        int ans=qry(1,n);
        for(int i=1;i<=n;i++){
            ans=max(ans,cal(qry(1,i-1),qry(i+1,n)));
        }
         
        id=0;
        int alc=0;
        for(int i=1;i<=n;i++){
            int val=abs(b[i]);
            if(!val) continue;
            alc++;
            for(int x: D[val]){
                if(!V[x].size()) p[++id]=x;
                V[x].push_back(i);
            }
        }
         
        for(int t=1;t<=id;t++){
            int x=p[t];
            if(V[x].size()==alc-2){
                vector <int> TMP;
                for(int i=1;i<=n;i++){
                    if(abs(b[i])%x!=0) TMP.push_back(i);
                }
                 
                int A=TMP[0],B=TMP[1];
                if(A>B) swap(A,B);
                int tot=abs(b[A]+b[B]);
                tot=cal(tot,qry(1,A-1));
                tot=cal(tot,qry(A+1,B-1));
                tot=cal(tot,qry(B+1,n));
                ans=max(ans,tot);
            }
             
            V[x].clear();
        }
         
        printf("%d\n",ans);
    }
     
}
