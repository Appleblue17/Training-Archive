#include <bits/stdc++.h>
using namespace std;
const int N=4400;

int n;

namespace Judger{
    char s[N][N];
    int curx, cury;
    char _dict[4]={'^', 'v', '<', '>'};
    int _dx[4]={-1, 1, 0, 0}, _dy[4]={0, 0, -1, 1};
    int cnt;
    
    
    void init(){
        for(int i=1; i<=n; ++i){
            scanf("%s", s[i]+1);
        }
        curx=(n+1)/2; cury=(n+1)/2;
    }
    
    int qry(int x){
        cnt++;
        cout<<_dict[x]<<endl;
        curx+=_dx[x]; cury+=_dy[x];
        char ret;
        ret=s[curx][cury];
        cout<<"  => "<<ret<<endl;
        if(ret=='^') return 0;
        if(ret=='v') return 1;
        if(ret=='<') return 2;
        if(ret=='>') return 3;
        if(ret=='.') return 4;
        if(ret=='G'){
            cout<<"Goal"<<endl;
            cout<<"step = "<<cnt<<endl;
            exit(0);
        }
        return -1;
    }
}
namespace OnlineJudger{
    char _dict[4]={'^', 'v', '<', '>'};
    void init(){}
    int qry(int x){
        cout<<_dict[x]<<endl;
        char ret;
        cin>>ret;
        
        // cout<<ret<<endl;
        if(ret=='^') return 0;
        if(ret=='v') return 1;
        if(ret=='<') return 2;
        if(ret=='>') return 3;
        if(ret=='.') return 4;
        if(ret=='G'){
            exit(0);
        }
        return -1;
    }
}
// using namespace Judger;
using namespace OnlineJudger;

int posx,posy,dir=0;

int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int mp[N][N];
void mov(int t){
    dir=qry(t);
    posx+=dx[t];
    posy+=dy[t];
    mp[posx][posy]=dir;
    // cout<<"  pos: "<<posx<<" "<<posy<<endl;
}
void move_to(int x,int y){
    while(posx>x) mov(0);
    while(posx<x) mov(1);
    while(posy>y) mov(2);
    while(posy<y) mov(3);
}
bool cal(int l,int r,int L,int R){
    // is in it
    int tot=0;
    for(int i=l;i<=r;i++) tot+=(mp[i][L-1]==3)-(mp[i][L]==2);
    for(int i=l;i<=r;i++) tot+=(mp[i][R+1]==2)-(mp[i][R]==3);
    for(int i=L;i<=R;i++) tot+=(mp[l-1][i]==1)-(mp[l][i]==0);
    for(int i=L;i<=R;i++) tot+=(mp[r+1][i]==0)-(mp[r][i]==1);
    return (tot!=0) ^ (l<=(n+1)/2 && (n+1)/2<=r && L<=(n+1)/2 && (n+1)/2<=R);
}

signed main(){
    // freopen("G.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin>>n; n=n*2+1;
    init();
    memset(mp,-1,sizeof(mp));
    
    int l=1,r=n,L=1,R=n;
    posx=(l+r)/2,posy=(L+R)/2;
    
    while(1){
        // cout<<" New round: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
        int savx=posx,savy=posy;
        if(L==R){
            while(posx>l) mov(0);
            while(posx<r) mov(1);
            return 0;
        }
        
        while(posx>l) mov(0);
        
        mov(3);
        while(posx<r) mov(1);
        
        mov(2);
        while(posx>savx) mov(0);
        
        // if(l==1 && r==3 && L==1 && R==3){
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=n;j++){
        //             if(mp[i][j]==-1) cout<<".";
        //             else cout<<mp[i][j];
        //         }
        //         cout<<endl;
        //     }
            
        //     cout<<"  ?? "<<l<<" "<<r<<" "<<posy+1<<" "<<R<<endl;
        //     int ret=cal(l,r,posy+1,R); cout<<ret<<endl;
        //     return 0;
            
        // }
        
        if(!cal(l,r,posy+1,R)){
            R=posy;
            // cout<<" Know A: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
            while(posy>L) mov(2);
            mov(1);
            while(posy<R) mov(3);
            
            if(!cal(posx,r,L,R)) r=posx-1;
            else l=posx;
            move_to((l+r)/2,(L+R)/2);
            
            // cout<<" Know B: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
        }
        else{
            mov(3);
            L=posy;
            // cout<<" Know A: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
            while(posy<R) mov(3);
            mov(1);
            while(posy>L) mov(2);
            
            if(!cal(posx,r,L,R)) r=posx-1;
            else l=posx;
            move_to((l+r)/2,(L+R)/2);
            
            // cout<<" Know B: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
        }
        
    }
    // assert(0);
}
