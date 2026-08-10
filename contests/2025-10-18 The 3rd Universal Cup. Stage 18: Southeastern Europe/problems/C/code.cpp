#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n;
vector<int> p[N],s[N];
int b[N],ans[N];
int B;
vector<int> cct(vector<int> a,vector<int> b){
    for(int v:b)a.push_back(v);
    return a;
}
vector<int> sli(vector<int> a,int st,int ed){
    vector<int> ret;
    for(int i=st;i<=ed;i++)ret.push_back(a[i]);
    return ret;
}
int C=0;
void term(int a){
    printf("! %d\n",a);fflush(stdout);exit(0);
}
int query(vector<int> q){
    if(C == 3500){
        printf("! 0\n");fflush(stdout);
        exit(0);
    }
    C++;
    memset(b,0,sizeof(b));
    for(int i:q){
        for(int v:p[i]){
            b[v]=1;
        }
        
    }
    printf("? ");
    for(int i=1;i<=n;i++){
        printf("%d",b[i]);
    }
    putchar('\n');
    fflush(stdout);
    int ret=0;
    scanf("%d",&ret);
    //printf("get result %d\n",ret);
    return ret;
}
int ansa,bsans;
void bs(int a,vector<int> b){
    int nb = b.size();
    //int ansa = query(a),ansb = query(b);
    int l=0,r=nb-1,m=(l+r)/2;
    while(l<r){
        m = (l+r)/2;
        vector<int> vl = sli(b,l,m);
        vector<int> val = vl;
        val.push_back(a);
        int ansl = query(vl), ansz = query(val);
        if(ansl + ansa > ansz)r=m;
        else l=m+1;
    }
    bsans = b[l];
}
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i].push_back(i);
    }
    
    for(int t=1;t<n;t++){
        vector<int> tt,b;
        for(int i=2;i<=n-t+1;i++){
            b.push_back(i);
        }
        tt.push_back(1);
        ansa = query(tt);
        if(ansa == 0){
            term(0);
        }
        
        bs(1,b);
        //printf("bsans = %d\n",bsans);
        swap(p[bsans],p[n-t+1]);
        p[1] = cct(p[1],p[n-t+1]);
        p[n-t+1].clear();
        /*putchar('\n');
        for(int i=1;i<=n-t;i++){
            for(int v:p[i])printf("%d ",v);
            putchar('\n');
        }*/
    }
    term(1);
}
