#include<bits/stdc++.h>
using namespace std;
int n, m, w, p;
int a[1005][1005];
int posx[1005*1005], posy[1005*1005];
bool vis[1005*1005];
bool in(int x, int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int main(){
    cin>>n>>m>>w>>p;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin>>a[i][j];
            if(a[i][j]!=0){
                posx[a[i][j]]=i; posy[a[i][j]]=j;
            }
        }
    }
    for(int i=1; i<=p; ++i){
        int x=posx[i], y=posy[i];
        int dis=p-i;
        for(int k=0; k<4; ++k){
            int cx=x+dx[k], cy=y+dy[k];
            if(!in(cx, cy)) continue;
            if(a[cx][cy]==0) continue;
            if(a[cx][cy]+dis<=w) vis[a[cx][cy]+dis]=1;
        }
    }
    int ans=0;
    for(int i=1; i<=w; ++i) if(vis[i]&&i!=p) ++ans;
    printf("%d/%d\n", ans, w-1);
}