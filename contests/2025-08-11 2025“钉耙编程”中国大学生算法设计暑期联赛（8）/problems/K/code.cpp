#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=1e5+5,mod=1e9+7,bas=1e9+1;
int T,n,k,id;

int pw[N];
char S[N],SS[N];

int p[N],rk[N];

string STR[N];

unordered_map <int,int> mp;
int ghas(){
    int len=strlen(S),tot=0;
    for(int i=0;i<len;i++) tot=(tot+1ll*(S[i]-'a')*pw[i]%mod)%mod;
    if(!mp[tot]) mp[tot]=++id;
    return mp[tot];
}

int team[N],bel[N],col[N];
bool isteam[N];
vector <int> COL[4];


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

void del(abc u);
void add(abc u);
int query(int x);

void update(int gameid){
    if(!Q[gameid].size()) return ;
    abc u=Q[gameid].front();
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


int win[N],score[N];

void del(abc u){
    // cout<<"del "<<u.X<<" "<<u.Y<<" "<<u.x<<" "<<u.y<<endl;
    int X=u.X,Y=u.Y,x=u.x,y=u.y;
    if(x<y) win[Y]--;
    else win[X]--;
    score[x]-=X-Y;
    score[y]-=Y-X;
    
}
void add(abc u){
    // cout<<"add "<<u.X<<" "<<u.Y<<" "<<u.x<<" "<<u.y<<endl;
    int X=u.X,Y=u.Y,x=u.x,y=u.y;
    if(x<y) win[Y]++;
    else win[X]++;
    score[x]+=X-Y;
    score[y]+=Y-X;
}

int query(int x){
    int tot=0;
    int c=col[x];
    // cout<<"col "<<c<<endl;
    
    for(int y: COL[c]){
        // cout<<"compare "<<x<<" "<<y<<endl;
        // cout<<win[y]<<" "<<score[y]<<" "<<rk[y]<<endl;
        if(win[y]>win[x] || (win[y]==win[x] && score[y]>score[x]) || (win[y]==win[x] && score[y]==score[x] && rk[y]>rk[x])){
            tot++;
        }
    }
    return tot+1;
}


int main(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=1ll*pw[i-1]*bas%mod;
    
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
        for(int t=1;t<=3;t++) COL[t].clear();
        
        mid=0;
        memset(msg,0,sizeof(msg));
        
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
            scanf("%d",&c);
            col[team[t]]=c;
            // cout<<c<<endl;
            COL[c].push_back(team[t]);
        }
        
        for(int i=1;i<=3*n;i++) p[i]=i;
        sort(p+1,p+3*n+1,[&](int x,int y){
            return STR[x]<STR[y];
        });
        for(int i=1;i<=3*n;i++) rk[team[p[i]]]=i;
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
                
                if(col[X]==col[Y]){
                    abc u={X,Y,x,y,mid};
                    Q[gameid].push(u);
                    add(u);
                    valid[mid]=1;
                }
            }
            else if(opt==2){
                int x; scanf("%d",&x);
                int gameid=msg[x];
                valid[x]=0;
                
                update(gameid);
            }
            else if(opt==3){
                int x; scanf("%d",&x);
                
                int ret=query(team[x]);
                printf("%d\n",ret);
            }
        }
        
    }
}