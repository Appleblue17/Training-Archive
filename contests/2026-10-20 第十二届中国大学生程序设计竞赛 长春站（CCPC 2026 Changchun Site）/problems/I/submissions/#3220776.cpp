#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;

int T,r,n;
char s[N];
vector<int> ans;
vector<int> e[N];
int deg[N];
bool flg[N];
int val[N];
int fr[N], dis[N];
bool check(int x, int y){
    if(x==1&&y==6) return false;
    if(x==2&&y==1) return false;
    if(x==3&&y==6) return false;
    if(x==3&&y==5) return false;
    if(x==3&&y==4) return false;
    if(x==4&&y==1) return false;
    if(x==4&&y==2) return false;
    if(x==4&&y==3) return false;
    if(x==5&&y==6) return false;
    if(x==6&&y==1) return false;
    return true;
}
void back(int x){
    if(x==0) return ;
    back(fr[x]);
    if((x==n||x==n+n)&&(n&1)){
        ans.push_back(s[n]-'0');
    }
    else{
        for(int i=4; i>=1; i/=2){
            ans.push_back((val[x]&i)!=0);
        }
    }
}
void solve1(){
    scanf("%d",&n);
    scanf("%s",s+1);
    ans.clear();
    for(int i=1; i<=n+n; ++i) e[i].clear(), deg[i]=0, fr[i]=0, dis[i]=0;
    for(int i=2; i<=n; i+=2){
        if(s[i-1]=='0'&&s[i]=='0'){
            flg[i]=1;
            flg[i+n]=0;
            val[i]=2;
        }
        if(s[i-1]=='1'&&s[i]=='1'){
            flg[i]=1;
            flg[i+n]=0;
            val[i]=5;
        }
        if(s[i-1]=='0'&&s[i]=='1'){
            flg[i]=1;
            flg[i+n]=1;
            val[i]=1;
            val[i+n]=6;
        }
        if(s[i-1]=='1'&&s[i]=='0'){
            flg[i]=1;
            flg[i+n]=1;
            val[i]=3;
            val[i+n]=4;
        }
        if(i!=2){
            for(int j=i; j<=i+n; j+=n){
                for(int k=i-2; k<=i-2+n; k+=n){
                    if(flg[j]&&flg[k]&&check(val[k], val[j])){
                        ++deg[j]; e[k].push_back(j);
                    }
                }
            }
        }
    }
    if(n&1){
        flg[n]=1; flg[n+n]=0;
        if(n>1){
            for(int j=n-1; j<=n-1+n; j+=n){
                if(flg[j]){
                    if(s[n]=='1'&&val[j]==3) continue;
                    if(s[n]=='0'&&val[j]==4) continue;
                    ++deg[n]; e[j].push_back(n);
                }
            }
        }
    }
    queue<int> que;
    for(int i=1; i<=n+n; ++i) if(flg[i]&&!deg[i]) que.push(i);
    while(!que.empty()){
        int x=que.front(); que.pop();
        for(auto y:e[x]){
            --deg[y];
            if(dis[y]<dis[x]+1) {
                dis[y]=dis[x]+1;
                fr[y]=x;
            }
            if(!deg[y]){
                que.push(y);
            }
        }
    }
    int ed=n;
    if(dis[n]!=(n/2)+(n&1)-1) ed=n+n;
    back(ed);
    printf("%d\n",ans.size());
    for(char v:ans)printf("%c",v+'0');
    printf("\n");
    fflush(stdout);
}

void solve2(){
    scanf("%d",&n);
    scanf("%s",s+1);
    s[n+1] = 0;
    int cnt=1;
    ans.clear();
    for(int i=3;i<=n;i+=3){
        int num=0;
        num=(s[i-2]-'0')*4+(s[i-1]-'0')*2+(s[i]-'0');
        if(num==2) ans.push_back(0), ans.push_back(0);
        if(num==5) ans.push_back(1), ans.push_back(1);
        if(num==1) ans.push_back(0), ans.push_back(1);
        if(num==6) ans.push_back(0), ans.push_back(1);
        if(num==3) ans.push_back(1), ans.push_back(0);
        if(num==4) ans.push_back(1), ans.push_back(0);
    }
    if(n%3==1) ans.push_back(s[n]-'0');
    printf("%d\n",ans.size());
    for(char v:ans)printf("%c",v+'0');
    printf("\n");
    fflush(stdout);
}

signed main(){
    cin>>T >> r;
    while(T--){
        if(r==1)solve1();
        else solve2();
    }
    
    
}