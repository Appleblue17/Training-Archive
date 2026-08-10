#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define int long long
const int N=1100,M=1100;
char s[N][M];
int r,c,n,dis[N][M];
typedef pair<int,int> pii;

#define mp make_pair
#define fi first
#define se second

const int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

void solve(){
    scanf("%lld%lld",&r,&c);
    for(int i=1;i<=r;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dis[i][j]=1e9;
        }
    }
    queue<pii> q;
    q.push(mp(r,c));
    dis[r][c]=0;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int d=0;d<4;d++){
            pii v = mp(u.fi+dir[d][0],u.se+dir[d][1]);
            if(v.fi > r || v.fi < 1 || v.se > c || v.fi < 1)continue;
            if(dis[v.fi][v.se]>5e8){
                dis[v.fi][v.se] = dis[u.fi][u.se]+1;
                if(s[v.fi][v.se] == 'C') q.push(v);
            }
        }
    }
    n=0;
    priority_queue<int> x1,x2;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(s[i][j]=='B'){
                n++;
                bool f=0;
                for(int d=0;d<4;d++){
                    pii v = mp(i+dir[d][0],j+dir[d][1]);
                    if(v.fi > r || v.fi < 1 || v.se > c || v.fi < 1)continue;
                    if(s[v.fi][v.se]=='B'){
                        f=1;
                        break;
                    }
                }
                if(f){
                    x1.push(-dis[i][j]);
                    //printf("x1 push %lld\n",dis[i][j]);
                }
                else{
                    x2.push(-dis[i][j]);
                    //printf("x2 push %lld\n",dis[i][j]);
                }
            }
        }
    }
    int lsm=0,x=0;
    int xd=0,xn=0;
    for(x=0;x<=r*c;x++){
        while(!x1.empty() && -x1.top()<=x+1){
            lsm += -x1.top();
            x1.pop();
        }
        //if(!x2.empty())cout << -x2.top() << ' ' << x2.size() << endl;
        while(!x2.empty() && -x2.top()<=x+2){
            lsm += -x2.top();
            x2.pop();
        }
        int x1s = x1.size(),x2s = x2.size();
        //printf("current x=%lld,true x = %lld/%lld\n",x,x1s+2*x2s+lsm,(n-x1s-x2s));
        if(x * (n-x1s-x2s) <= x1s+2*x2s+lsm && x1s+2*x2s+lsm <= (x+1)*(n-x1s-x2s)){
            xd = x1s+2*x2s+lsm;
            xn = (n-x1s-x2s);
            //printf("x calculated as %lld/%lld\n",xd,xn);
        }
    }
    int mindis = 1e9;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(s[i][j]=='B'){
                mindis = min(mindis,i+j-2);
            }
        }
    }
    if(n==0){
        printf("%lld/1\n",dis[1][1]);
        return;
    }
    if(dis[1][1]*xn < mindis*xn+xd){
        printf("%lld/1\n",dis[1][1]);
    }
    else{
        int A=mindis*xn+xd,B=xn,C=__gcd(A,B);
        A/=C;B/=C;
        printf("%lld/%lld\n",A,B);
    }
}
signed main(){
    int T;
    scanf("%lld",&T);
    while(T--)solve();
}