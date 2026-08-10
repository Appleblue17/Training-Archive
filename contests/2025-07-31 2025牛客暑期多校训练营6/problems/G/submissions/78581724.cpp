#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550000,mod=998244353;
  
int n,q,a[N],sm1;
char s[N];
int mx[N*4],addmark[N*4];
#define ls rt<<1,le,mi
#define rs rt<<1|1,mi+1,ri
  
void update(int rt,int le,int ri){
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
  
void build(int rt,int le,int ri){
    if(le == ri){
        mx[rt]=a[le];
        addmark[rt]=0;
        return;
    }
    int mi=(le+ri)>>1;
    build(ls);
    build(rs);
    update(rt,le,ri);
}
void pushdown(int rt,int le,int ri){
    addmark[rt*2]+=addmark[rt];
    mx[rt*2]+=addmark[rt];
    addmark[rt*2+1]+=addmark[rt];
    mx[rt*2+1]+=addmark[rt];
    addmark[rt]=0;
}
int L,R,X;
void add(int rt,int le,int ri){
    //if(rt == 1)printf("add X=%lld L=%lld R=%lld\n",X,L,R);
    if(le >= L && ri <= R){
        addmark[rt]+=X;
        mx[rt]+=X;
        return;
    }
    pushdown(rt,le,ri);
    int mi=(le+ri)/2;
    if(mi >= L)add(ls);
    if(mi < R)add(rs);
    update(rt,le,ri);
}
  
 
  
int query(int rt,int le,int ri){
    if(le >= L && ri <= R){
        //printf("query L=%lld R=%lld,rt=%lld,le=%lld,ri=%lld,mx=%lld\n",L,R,rt,le,ri,mx[rt]);
        return mx[rt];
    }
    int mi=(le+ri)/2,ret=-1e9;
    pushdown(rt,le,ri);
    if(mi >= L)ret = max(ret,query(ls));
    if(mi < R)ret = max(ret,query(rs));
    //printf("query L=%lld R=%lld,rt=%lld,le=%lld,ri=%lld,ret=%lld\n",L,R,rt,le,ri,ret);
    return ret;
}
  
set<int> s1,s0;
  
signed main(){
    scanf("%lld%lld",&n,&q);
    scanf("%s",s+1);
    sm1=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='R')s[i]=1,a[i]=a[i-1]+1,sm1++,s1.insert(i);
        else s[i]=-1,a[i]=a[i-1]-1,s0.insert(i);
        //cout << a[i] << ' ';
    }
    //putchar('\n');
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int x;
        scanf("%lld",&x);
        L=x;R=n;
        if(s[x]==-1){
            s0.erase(x);
            s1.insert(x);
            X=2;
            add(1,1,n);
            s[x]=1;
            sm1++;
        }
        else{
            s1.erase(x);
            s0.insert(x);
            X=-2;
            add(1,1,n);
            s[x]=-1;
            sm1--;
        }
        if(s1.empty() || s0.empty()){
            printf("0\n");
            continue;
        }
        L = *s1.begin();
        set<int>::iterator it = s0.end();
        it--;
        R = *it;
        int ans = query(1,1,n)-1+(L-1);
        ans = max(ans,0ll);
        //printf("L=%lld,R=%lld,query=%lld,stepblocked=%lld\n",L,R,query(1,1,n),ans);
        it = s1.end();
        it--;
        ans = n-(L-1)-s1.size()+ans;
        printf("%lld\n",ans);
    }
}
