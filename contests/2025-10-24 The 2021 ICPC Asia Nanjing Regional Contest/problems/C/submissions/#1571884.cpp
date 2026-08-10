#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5,W=1e6;
int n,k,ans;
int a[N];
vector <int> V[N];

int p[N],id;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        V[a[i]+W].push_back(i);
    }
    
    for(int i=0;i<N;i++){
        int j=i+k;
        if(j>=0 && j<N){
            int x=0,y=0,sum=0;
            id=0;
            while(x<V[i].size() && y<V[j].size()){
                if(V[i][x]<V[j][y]) p[++id]=1,x++;
                else p[++id]=-1,y++,sum++;
            }
            while(x<V[i].size()) p[++id]=1,x++;
            while(y<V[j].size()) p[++id]=-1,y++,sum++;
            
            // if(i-W==2){
            //     for(int t=1;t<=id;t++) cout<<p[t]<<" ";
            //     cout<<endl;
            // }
            ans=max(ans,sum);
            if(k==0) continue;
            int nw=0;
            for(int t=1;t<=id;t++){
                nw=max(0,nw+p[t]);
                ans=max(ans,nw+sum);
            }
        }
    }
    cout<<ans;
}
