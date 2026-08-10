#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int N=2e5+5;
int n, m;
vector<vector<int> > h;
vector<vector<int> > dis;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
vector<pair<int, int> > bin[N];
bool check(int x){
    int mnx=inf, mxx=-inf, mny=inf, mxy=-inf;
    for(int i=max(n, m); i>x; --i){
        for(auto t:bin[i]){
            int cx=t.first-t.second, cy=t.first+t.second;
            mnx=min(mnx, cx); mxx=max(mxx, cx);
            mny=min(mny, cy); mxy=max(mxy, cy);
        }
    }
    if(mnx==inf) return true;
    int cx=(mnx+mxx)/2, cy=(mny+mxy)/2;
    int dis=inf;
    if((cx&1)==(cy&1)){
        dis=max(max(cx-mnx, mxx-cx), max(cy-mny, mxy-cy));
    }
    else{
        for(int i=0; i<4; ++i){
            int bx=cx+dx[i], by=cy+dy[i];
            dis=min(dis, max(max(bx-mnx, mxx-bx), max(by-mny, mxy-by)));
        }
    }
    return dis<=x;
}
int main(){
    scanf("%d%d", &n, &m);
    h.resize(n+1); dis.resize(n+1);
    queue<pair<int, int> > que;
    for(int i=1; i<=n; ++i){
        h[i].resize(m+1); dis[i].resize(m+1);
        for(int j=1; j<=m; ++j) {
            scanf("%d", &h[i][j]), dis[i][j]=max(n, m);
            if(h[i][j]){
                dis[i][j]=0; que.push(make_pair(i, j));
            }
        }
    }
    while(!que.empty()){
        int x=que.front().first, y=que.front().second;
        que.pop();
        for(int i=0; i<4; ++i){
            int cx=x+dx[i], cy=y+dy[i];
            if(cx>=1&&cx<=n&&cy>=1&&cy<=m){
                if(dis[cx][cy]==max(n, m)){
                    dis[cx][cy]=dis[x][y]+1;
                    que.push(make_pair(cx, cy));
                }
            }
        }
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) bin[dis[i][j]].push_back(make_pair(i, j));
    int L=0, R=max(n, m)-1, mid, ret=max(n, m);
    while(L<=R){
        mid=(L+R)>>1;
        if(check(mid)){
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    printf("%d\n", ret);
}
