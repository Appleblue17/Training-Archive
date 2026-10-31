#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=11e5+5,INF=1e18;

int T,n,m,ans;
int a[N];

int f[22][N];

int gmin(int l,int r){
    int tot=INF;
    for(int i=l;i<=r;i++) tot=min(tot,a[i]);
    return tot;
}

signed main(){
    // freopen("G0.in","r",stdin);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        // int tans; cin>>tans;
        
        // n++;
        m=(1<<n);
        for(int i=0;i<m;i++) a[i]=0;
        
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        if(!n){
            printf("%lld\n",a[0]);
            continue;
        }
        
        ans=0;
        for(int k=0;k<n;k++){
            // cout<<"--- start "<<k<<endl;
            for(int l=0;l<m;l+=(1<<k)) f[k][l]=0;
            for(int l=0;l<m;l+=(1<<(k+1))){
                int mid=l+(1<<k),r=mid+(1<<k);
                int mn1=gmin(l,mid-1),mn2=gmin(mid,r-1);
                
                if(k>0){
                    f[k][l]=f[k-1][mid]+f[k-1][mid+(1<<(k-1))];
                    f[k][mid]=f[k-1][l]+f[k-1][l+(1<<(k-1))];
                }
                
                int d=abs(mn1-mn2);
                
                if(mn1>mn2){
                    int val=max(0ll,d-f[k][l]);
                    ans+=val; f[k][l]+=val;
                }
                else{
                    int val=max(0ll,d-f[k][mid]);
                    ans+=val; f[k][mid]+=val;
                }
            }
            
            // for(int l=0;l<m;l+=(1<<k)) cout<<f[k][l]<<" ";
            // cout<<endl;
            
            // cout<<"cur ans: "<<ans<<endl;
        }
        
        int mn=gmin(0,m-1);
        int sum=min(f[n-1][0],f[n-1][m/2]);
        // cout<<mn<<" "<<sum<<endl;
        ans+=max(0ll,mn-sum);
        
        printf("%lld\n",ans);
        // if(ans>tans) cout<<"WRONG "<<ans<<" "<<tans<<endl;
    }
}