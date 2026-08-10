#include<bits/stdc++.h>
using namespace std;
const int N=630000;
int n,a[N][3],vis[N],cnt[N];
vector<int> ans;
vector<int> stn[N];
void addans(int i,int j){
    //printf("ans (%d,%d) added\n",i,j);
    ans.push_back(i);
    ans.push_back(j);
    cnt[i]++;cnt[j]++;
}
void dfs(int s,int fa){
    //printf("dfs set=%d,fa=%d\n",s,fa);fflush(stdout);
    for(int i=0;i<stn[s].size();i++){
        int u = stn[s][i];
        for(int o=0;o<3;o++){
            if(!vis[a[u][o]]){
                vis[a[u][o]]=1;
                dfs(a[u][o],u);
            }
        }
    }
    int tc=0;
    vector<int> tch;
    for(int u:stn[s]){
        if(cnt[u]%2==0){
            tc++;
            tch.push_back(u);
        }
    }
    if(fa != -1 && tc%2==1){
        if(cnt[fa]%2==1){
            tch.push_back(fa);
        }
        else{
            //tch.erase(fa);
            tch.clear();
            for(int u:stn[s]){
                if(cnt[u]%2 == 0 && u != fa){
                    tch.push_back(u);
                }
            }
        }
    }
    //now tch.size() is guaranteed to be even, or else fa=-1
    for(int i=0;i+1<tch.size();i+=2){
        int u = tch[i],v = tch[i+1];
        addans(u,v);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        a[i][1]+=n;a[i][2]+=2*n;
        for(int o=0;o<3;o++){
            stn[a[i][o]].push_back(i);
        }
    }
    for(int i=1;i<=n*3;i++){
        //cout << vis[i] << endl;
        if(!vis[i]){
            vis[i]=1;
            dfs(i,-1);
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]<=1)addans(i,i);
    }
    printf("%d\n",(int)ans.size()/2);
    for(int i=0;i<ans.size();i+=2){
        printf("%d %d\n",ans[i],ans[i+1]);
    }
}
