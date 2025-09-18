#include<bits/stdc++.h>
using namespace std;
const int N=210000,M=11000,INF=1e9;

typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second
int n,xc,yc,xa,ya;

pii a[N];

int main(){
    scanf("%d%d%d%d%d",&n,&xc,&yc,&xa,&ya);
    int x,y,X,Y;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x,&y,&X,&Y);
        a[i*2-1]=mp(y,1);
        a[i*2]=mp(Y,-1);
    }
    if(yc <= ya){
        printf("0.0");
        return 0;
    }
    a[n*2+1]=mp(yc,0);
    a[n*2+2]=mp(ya,0);
    sort(a+1,a+2*n+3);
    bool f=0;
    int ans=0,cnt=0;
    for(int i=1;i<n*2+2;i++){
        if((a[i].fi == yc || a[i].fi == ya) && a[i].se == 0){
            if(f)f=0;
            else f=1;
        }
        cnt += a[i].se;
        if(cnt == 0 && f)ans += a[i+1].fi - a[i].fi;
    }
    printf("%.1lf",(double)ans);
}
