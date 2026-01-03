#include<bits/stdc++.h>
using namespace std;
const int N=44;
int T,n,k;
int a[N];
double p[N];

int cal(double p,double x){
    int l=0,r=k,tot=r+1;
    while(l<=r){
        int mid=(l+r)>>1;
        double C=(1+p*(mid+1))/(1+p*mid);
        if(C<x) tot=mid,r=mid-1;
        else l=mid+1;
    }
    return tot;
}

int check(double x){
    int tot=0;
    for(int i=1;i<=n;i++){
        tot+=cal(p[i],x);
        if(tot>k) return 0;
    }
    return (tot<=k);
}

int ans[N];
pair <double,int> q[N];

int main(){
    // freopen("G2.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            p[i]=1.0*a[i]/100;
        }
        
        double l=1,r=2,tot=3;
        for(int t=1;t<=80;t++){
            double mid=(l+r)/2;
            
            // cout<<"check "<<mid<<": "<<check(mid)<<endl;
            
            if(check(mid)) tot=mid,r=mid;
            else l=mid;
        }
        // cout<<tot<<endl;
        
        int sum=0;
        for(int i=1;i<=n;i++){
            int r=cal(p[i],tot);
            sum+=r;
            q[i]=make_pair((1+p[i]*(r+1))/(1+p[i]*r),i);
            
            ans[i]=r;
        }
        sort(q+1,q+n+1);
        assert(k-sum<=n);
        for(int i=1;i<=min(k-sum,n);i++) ans[q[n-i+1].second]++;
        
        // for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
        
        long double anss=1;
        for(int i=1;i<=n;i++) anss*=(1+p[i]*ans[i]);
        printf("%.8Lf\n",anss);
    }
}
