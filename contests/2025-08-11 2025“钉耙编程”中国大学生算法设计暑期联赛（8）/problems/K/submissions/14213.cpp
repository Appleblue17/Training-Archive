#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std;
#define MP make_pair
const int N=1e5+5,mod=1e9+7,bas=1e4+7;
int T,n,k,id;

int pw[N];
char S[55],SS[55];

int p[N],rk[N];

string STR[N];

unordered_map <int,int> mp;
int ghas(){
    int len=strlen(S),tot=0;
    for(int i=0;i<len;i++) tot=(tot+1ll*S[i]*pw[i]%mod)%mod;
    if(!mp[tot]) mp[tot]=++id;
    return mp[tot];
}

int team[N],bel[N],col[N];
bool isteam[N];

map <pair<int,int>, int> game;
int gid;

int getgameid(int x,int y){
    if(x>y) swap(x,y);
    if(!game[MP(x,y)]) game[MP(x,y)]=++gid;
    return game[MP(x,y)];
}

bool valid[N];

struct abc{
    int X,Y,x,y,num;
};
queue <abc> Q[N];

int msg[N],mid;


/* ----------------------------------- */

int win[N],score[N];
struct def{
    int win,score,rk;
};
bool operator <(def X,def Y){
    if(X.win!=Y.win) return X.win<Y.win;
    if(X.score!=Y.score) return X.score<Y.score;
    return X.rk>Y.rk;
}
tree<def,null_type,less<def>,rb_tree_tag,tree_order_statistics_node_update> bbt[3];

void del(abc u){
    // cout<<"del "<<u.X<<" "<<u.Y<<" "<<u.x<<" "<<u.y<<endl;
    int X=u.X,Y=u.Y,x=u.x,y=u.y;
    bbt[col[X]].erase((def){win[X],score[X],rk[X]});
    bbt[col[Y]].erase((def){win[Y],score[Y],rk[Y]});
    if(x<y) win[Y]--;
    else win[X]--;
    score[X]-=x-y;
    score[Y]-=y-x;
    bbt[col[X]].insert((def){win[X],score[X],rk[X]});
    bbt[col[Y]].insert((def){win[Y],score[Y],rk[Y]});
}
void add(abc u){
    // cout<<"add "<<u.X<<" "<<u.Y<<" "<<u.x<<" "<<u.y<<endl;
    int X=u.X,Y=u.Y,x=u.x,y=u.y;
    bbt[col[X]].erase((def){win[X],score[X],rk[X]});
    bbt[col[Y]].erase((def){win[Y],score[Y],rk[Y]});
    if(x<y) win[Y]++;
    else win[X]++;
    score[X]+=x-y;
    score[Y]+=y-x;
    bbt[col[X]].insert((def){win[X],score[X],rk[X]});
    bbt[col[Y]].insert((def){win[Y],score[Y],rk[Y]});
}

int query(int X){
    return n-bbt[col[X]].order_of_key((def){win[X],score[X],rk[X]});
}

int main(){
    // freopen("1.txt","w",stdout);
    pw[0]=1;
    for(int i=1;i<=50;i++) pw[i]=1ll*pw[i-1]*bas%mod;
    
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        mp.clear();
        game.clear();
        id=0;
        gid=0;
        memset(isteam,0,sizeof(isteam));
        memset(valid,0,sizeof(valid));
        for(int i=0;i<N;i++){
            while(Q[i].size()) Q[i].pop();
        }
        for(int t=0;t<3;t++) bbt[t].clear();
        
        mid=0;
        memset(msg,0,sizeof(msg));
        
        memset(win,0,sizeof(win));
        memset(score,0,sizeof(score));
        memset(rk,0,sizeof(rk));
        
        for(int t=1;t<=3*n;t++){
            scanf("\n%s",S);
            
            STR[t].clear();
            int len=strlen(S);
            for(int i=0;i<len;i++) STR[t]+=S[i];
            
            team[t]=ghas();
            isteam[team[t]]=1;
            // cout<<team[t]<<": ";
            
            for(int i=1;i<=5;i++){
                scanf(" %s",S);
                int pers=ghas();
                bel[pers]=team[t];
                // cout<<pers<<" ";
            }
            
            int c;
            scanf("%d",&c); c--;
            col[team[t]]=c;
            // cout<<c<<endl;
        }
        // cout<<id<<endl;
        
        for(int i=1;i<=3*n;i++) p[i]=i;
        sort(p+1,p+3*n+1,[&](int x,int y){
            return STR[x]<STR[y];
        });
        for(int i=1;i<=3*n;i++) rk[team[p[i]]]=i;
        for(int i=1;i<=3*n;i++){
            int x=team[i];
            // cout<<col[x]<<" "<<rk[x]<<endl;
            bbt[col[x]].insert((def){0,0,rk[x]});
        }
        // for(int i=1;i<=3*n;i++) cout<<rk[i]<<" "; cout<<endl;
        
        while(k--){
            int opt; scanf("%d",&opt);
            if(opt==1){
                int x,y;
                scanf(" a fan of %s The score of our game against Team %s is %d-%d.",S,SS,&x,&y);
                
                int len=strlen(S);
                S[len-1]=0;
                len=strlen(S);
                
                int X=ghas();
                swap(S,SS);
                int Y=ghas();
                
                if(!isteam[X]) X=bel[X];
                // cout<<X<<" "<<Y<<" "<<x<<" "<<y<<endl;
                
                if(X>Y) swap(X,Y),swap(x,y);
                int gameid=getgameid(X,Y);
                msg[++mid]=gameid;
                
                if(X!=Y && col[X]==col[Y]){
                    abc u={X,Y,x,y,mid};
                    if(!Q[gameid].size()) add(u);
                    Q[gameid].push(u);
                    valid[mid]=1;
                }
            }
            else if(opt==2){
                int x; scanf("%d",&x);
                int gameid=msg[x];
                valid[x]=0;
                
                if(Q[gameid].size() && Q[gameid].front().num==x){
                    abc u=Q[gameid].front(); Q[gameid].pop();
                    del(u);
                    
                    while(Q[gameid].size()){
                        abc u=Q[gameid].front();
                        if(valid[u.num]){
                            add(u);
                            break;
                        }
                        Q[gameid].pop();
                    }
                }
            }
            else if(opt==3){
                int x; scanf("%d",&x);
                
                int ret=query(team[x]);
                printf("%d\n",ret);
            }
        }
        
    }
}