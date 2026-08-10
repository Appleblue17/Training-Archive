#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110000;
int n, m,a[N],b[N],ans[20][N],pr[N],cnt[20];
vector<int> cur;
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cur.push_back(a[i]);
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    
    for(int k=14;k>=0;k--){
        cnt[k]=0;
        vector<int> nxt1,nxt2;
        for(int i=n-1;i>=0;i--){
            if((cur[i]-1)&(1<<k)){
                ans[k][++cnt[k]]=cur[i];
                //printf("k=%d,modify%d\n",k,cur[i]);
                nxt2.push_back(cur[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(!((cur[i]-1)&(1<<k))){
                nxt1.push_back(cur[i]);
            }
        }
        cur.clear();
        for(int v:nxt2)cur.push_back(v);
        for(int v:nxt1)cur.push_back(v);

    }

    for(int i=0;i<n;i++){
        pr[cur[i]]=b[i+1];
        //printf("pr[%d]=%d\n",cur[i],b[i+1]);
    }
    int cntcnt=15;
    for(int k=14;k>=0;k--){
        if(cnt[k]==0)cntcnt--;
    }
    cout << cntcnt << endl;
    for(int k=14;k>=0;k--){
        if(cnt[k]==0)continue;
        printf("%d ",cnt[k]);
        for(int i=1;i<=cnt[k];i++){
            printf("%d ",pr[ans[k][i]]);
        }
        putchar('\n');
    }
}

int main(){
    solve();
}