#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2e5+5,INF=1e9;
int T,n,k;
char S[N];
int a[N];

int s0[N],p0[N],mp0[N],id0;
int s1[N],p1[N],mp1[N],id1;

signed main(){
    // freopen("1.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("\n%s",S+1);
        for(int i=1;i<=n;i++) a[i]=S[i]-'0';
        
        id0=0,id1=0;
        for(int i=1;i<=n;i++) mp0[i]=mp1[i]=p0[i]=p1[i]=0;
        for(int i=1;i<=n;i++){
            mp0[i]=mp0[i-1];
            mp1[i]=mp1[i-1];
            s0[i]=s0[i-1];
            s1[i]=s1[i-1];
            if(!a[i]){
                p0[++id0]=i;
                mp0[i]=id0;
                s0[i]++;
            }
            else{
                p1[++id1]=i;
                mp1[i]=id1;
                s1[i]++;
            }
        }
        
        int ans=INF;
        for(int t=1;t<=n;t++){
            if(!a[t] || s1[t]<k) continue;
            int lst=p0[mp0[t]],l=min(t-lst,k);
            // cout<<t<<" "<<lst<<" "<<l<<": "<<endl;
            
            int tot=1,nw=lst;
            while(nw>0 && l<k){
                // cout<<"st "<<nw<<" "<<l<<endl;
                
                int pos=p1[mp1[nw]];
                int d=(nw-pos-1)/l; tot+=d; nw-=d*l;
                
                // cout<<"+"<<d<<"  -> "<<nw<<endl;
                
                int nxt=p0[max(0,s0[nw]-l)];
                int num=s1[nw]-s1[nxt];
                if(num>k-l){
                    nxt=max(0,nw-k);
                    // cout<<" ! "<<num<<" "<<nw<<" "<<nxt<<endl;
                    num=k-l;
                }
                
                tot++;
                l+=num;
                nw=nxt;
                
                // cout<<"+"<<"  -> "<<nw<<endl;
            }
            // cout<<"ed "<<nw<<" "<<l<<" "<<(nw+l-1)/l<<endl;
            tot+=(nw+l-1)/l;
            ans=min(ans,tot);
            // cout<<tot<<endl;
        }
        
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    
}