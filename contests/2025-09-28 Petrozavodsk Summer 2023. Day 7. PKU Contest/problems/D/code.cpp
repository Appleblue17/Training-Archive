#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=1e18;
int n,a[N],b[N];

priority_queue <int> p,q;
vector <int> V;

int ans;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    // for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    
    for(int i=1;i<=n;i++) q.push(-i);
    for(int i=1;i<=n;i++) q.push(-(n+1));
    
    for(int i=1;i<=n;i++){
        if(q.size() && q.top()==-i){
            q.pop();
            p.push(i);
            // cout<<"pop q push p "<<i<<endl;
        }
        
        // cout<<i<<": "<<endl;
        V.clear();
        
        for(int t=1;t<=b[i];t++){
            int l=p.empty()?-INF:p.top(),r=q.empty()?INF:-q.top();
            if(l<=-INF && r>=INF){
                ans+=1ll*(b[i]-t+1)*(n+1-i);
                // cout<<"skip "<<b[i]-t+1<<" "<<n+1-i<<endl;
                break;
            }
            
            if(i-l<=r-i){
                ans+=i-l;
                // cout<<" + "<<i-l<<"; pop p"<<"   "<<l<<" "<<r<<endl;
                p.pop();
            }
            else{
                ans+=r-i;
                q.pop();
                if(l > -INF){
                    p.pop();
                    V.push_back(l+(r-i)*2);
                }
                // cout<<" + "<<r-i<<"; pop p,q; push"<<" "<<l+(r-i)*2<<"   "<<l<<" "<<r<<endl;
            }
        }
        
        for(int x: V){
            p.push(x);
        }
    }
    cout<<ans;
}
