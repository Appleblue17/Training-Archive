#include<bits/stdc++.h>
using namespace std;
const int N=510,B=20;
int n,fa[N],cnt[N];
queue<int> q;
bool vis[N];

int ans[N];
int jvis[N];

int ret=0;
void operate(int typ,int x){
    if(typ == 1){
        printf("+ %d\n",x);fflush(stdout);
        
        // q.push(x);
        // jvis[ans[x]]++;
        // ret=0;
        // for(int i=1;i<=n;i++){
        //     if(jvis[i]>0)ret++;
        // }
        
        scanf("%d",&ret);
        //printf("get ret=%d\n",ret);
    }
    else{
        printf("-\n");fflush(stdout);
        
        // int tx = q.front();
        // q.pop();
        // jvis[ans[tx]]--;
        // ret=0;
        // for(int i=1;i<=n;i++){
        //     if(jvis[i]>0)ret++;
        // }
        
        scanf("%d",&ret);
        //printf("get ret=%d\n",ret);fflush(stdout);
        
    }
}

int findfa(int x){
    if(x == fa[x])return x;
    return fa[x] = findfa(fa[x]);
}

void connect(int x,int y){
    int fx = findfa(x);
    int fy = findfa(y);
    if(fx != fy){
        fa[fx]=fy;
    }
}

vector<int> getIS(const vector<int> S){
    vector<int> retIS;
    for(int v:S){
        int x = ret;
        operate(1,v);
        if(ret == x+1){
            retIS.push_back(v);
        }
    }
    for(int v:S){
        operate(2,0);
    }
    return retIS;
}

void merge(const vector<int>& s1,const vector<int>& s2){
    // printf("in merge,s1:");
    // for(int v:s1){
    //     printf("%d ",v);
    // }
    // printf(",s2:");
    // for(int v:s2){
    //     printf("%d ",v);
    // }putchar('\n');
    int n = s1.size(),m = s2.size();
    //if(n > m){
    //    merge(s2,s1);
    //    return;
    //}
    int k=0;
    while((1<<k) < n)k++;
    int grp[N];
    for(int v:s2)grp[v]=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<s1.size();j++){
            int v = s1[j];
            if(j & (1<<i))operate(1,v);
        }
        for(int v:s2){
            int x = ret;
            operate(1,v);
            if(ret == x){
                grp[v] += (1<<i);
            }
        }
        for(int v:s2){
            operate(2,0);
        }
        for(int j=0;j<s1.size();j++){
            int v = s1[j];
            if(j & (1<<i))operate(2,0);
        }
    }
    for(int v:s2){
        //printf("connect grp[%d]=%d\n",v,grp[v]);fflush(stdout);
    }
    for(int v:s2){
        //printf("connect %d,%d\n",v,s1[grp[v]]);fflush(stdout);
        connect(v,s1[grp[v]]);
    }
}

void solve1(vector<int> s,vector<int>& iss){//3*n*m
    // printf("in solve1,s:");
    // for(int v:s){
    //     printf("%d ",v);
    // }
    // printf(",iss:");
    // for(int v:iss){
    //     printf("%d ",v);
    // }putchar('\n');
    
        memset(vis,0,sizeof(vis));
        for(int v:s)vis[v]=1;
        for(int v:iss)vis[v]=0;
        s.clear();
        for(int i=1;i<=n;i++){
            if(vis[i])s.push_back(i);
        }
    
    bool tt=0;
    if(iss.size() % 2 == 1){
        iss.push_back(iss[0]);
        tt=1;
    }
    int i=0,j=0,w=s[i],u=iss[j],v=iss[j+1];
    while(1){
        operate(1,u);
        operate(1,w);
        bool f=0;
        if(ret == 1){
            connect(u,w);
            f=1;
        }
        else{
            operate(2,0);
            operate(1,v);
            if(ret == 1){
                connect(v,w);
                f=1;
            }
        }
        operate(2,0);
        operate(2,0);
        if(!f){
            j += 2;
            if(j >= iss.size())j=0;
            u = iss[j];v = iss[j+1];
        }
        else{
            i++;
            if(i >= s.size())break;
            w = s[i];
        }
    }
    if(tt){
        iss.pop_back();
    }
}


int main(){
    // ans[1]=1;ans[2]=2;ans[3]=1;ans[4]=3;ans[5]=4;
    // ans[6]=2;ans[7]=3;ans[8]=1;ans[9]=1;ans[10]=2;
    //freopen("A.out","w",stdout);
    scanf("%d",&n);
    //n = 10;
    vector<int> s,ns;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        s.push_back(i);
    }
    //cout << '^' << endl;
    vector<int> yis = getIS(s);
    bool firstrun=1;
    // printf("yis contains:");
    // for(int v:yis){
    //     printf("%d ",v);
    // }putchar('\n');
    //cout << '*' << endl;
    while(s.size()){
        vector<int> iss;
        if(firstrun)
            iss = yis;
        else
            iss = getIS(s);
        
        // printf("in main loop,s:\n");
        // for(int v:s){
        //     printf("%d ",v);
        // }
        // printf(",iss:");
        // for(int v:iss){
        //     printf("%d ",v);
        // }putchar('\n');
            
        if(iss.size() <= B){
            if(!firstrun)merge(yis,iss);
            solve1(s,iss);
            break;
        }
        else{
            if(!firstrun)merge(yis,iss);
        }
        ns.clear();
        memset(vis,0,sizeof(vis));
        for(int v:s)vis[v]=1;
        for(int v:iss)vis[v]=0;
        s.clear();
        for(int i=1;i<=n;i++){
            if(vis[i])s.push_back(i);
        }
        firstrun=0;
    }
    
    for(int i=1;i<=n;i++){
        fa[i] = findfa(i);
        cnt[fa[i]]++;
    }
    
    int tt=0;
    
    for(int i=1;i<=n;i++){
        if(cnt[i]!=0)tt++;
    }
    
    printf("! %d\n",tt);
    for(int i=1;i<=n;i++){
        tt=0;
        for(int j=1;j<=n;j++){
            if(fa[j] == i)tt++;
        }
        if(tt==0)continue;
        printf("%d ",tt);
        for(int j=1;j<=n;j++){
            if(fa[j] == i)printf("%d ",j);
        }
        putchar('\n');
    }
    fflush(stdout);
    
    
}
