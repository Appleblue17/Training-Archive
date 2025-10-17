#include <bits/stdc++.h>
//using namespace std;
//#define int long long
#define double long double
const int N=1e5+5;

int n,m,w,h,u[N],d[N];
double x[N],y[N];

int cnt[N];

int fl(double x){
    return floor(x);
    //if(x >= 0)return floor(x);
    //else return (x);
}
std::vector<int> ans1,ans2;

const double eps = 1e-7;
void add(double x0,double y0,double x1,double y1){
    //printf("in add %lf %lf %lf %lf\n",x0,y0,x1,y1);
    int st,ed;
    if(x0 < x1){
        st=ceil(x0);ed=floor(x1);
    }
    else{
        st=ceil(x1);ed=floor(x0);
    }
    for(int j=st;j<=ed;j++){
        double y = y0+(j-x0)*(y1-y0)/(x1-x0);
        if(x0 > x1)ans1.push_back(fl(y)+500);
        else ans2.push_back(fl(y)+500);
        cnt[fl(y)+500]++;
        //printf("add cnt %d,y=%Lf\n",fl(y)+500,y);
    }
    if(y0<y1){
        st=ceil(y0);ed=floor(y1);
    }
    else{
        st=ceil(y1);ed=floor(y0);
    }
    for(int j=st;j<=ed;j++){
        double x = x0+(x1-x0)*(j-y0)/(y1-y0);
        cnt[fl(x)+500]++;
        if(y0 < y1)ans2.push_back(fl(x)+500);
        else ans1.push_back(fl(x)+500);
        //printf("add cnt %d,j=%d,x=%Lf\n",fl(x)+500,j,x);
    }
    
}

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%Lf%Lf",&x[i],&y[i]);
    }
    x[n+1]=x[1];y[n+1]=y[1];
    for(int i=1;i<=n;i++){
        add(x[i],y[i],x[i+1],y[i+1]);
    }
    printf("%lld\n",ans1.size());
    for(int v:ans1){
        printf("%d\n",v-500);
    }
}
/*std::bitset<3005000> f[3005];
const int pls=1502000;
int sz[N], tot;
std::vector<int> ans;
void back(int i, int j){
    if(i==0) return ;
    if(f[i-1][j]) back(i-1, j);
    else if(f[i-1][j-sz[i]]){
        ans.push_back(sz[i]);
        back(i-1, j-sz[i]);
    }
    else {
        std::cout<<"??????"<<std::endl;
    }
}*/
void solve3(){

}
/*void solve2(){
    int sum=0;
    for(int i=-500; i<=500; ++i){
        if(cnt[i+500]==0) continue;
        if(cnt[i+500]&1){
            for(int j=4; j<=cnt[i+500]; j+=2){
                ans.push_back(i);
            }
            for(int j=1; j<=3&&j<=cnt[i+500]; ++j){
                sum+=i; sz[++tot]=i;
            }
        }
        else{
            for(int j=4; j<=cnt[i+500]; j+=2){
                ans.push_back(i);
            }
            for(int j=1; j<=2&&j<=cnt[i+500]; ++j){
                sum+=i; sz[++tot]=i;
            }
        }
    }
    if(sum&1){
        printf("-1\n");
        return ;
    }
    f[0][pls]=1;
    for(int i=1; i<=tot; ++i){
        if(sz[i]>0){
            f[i]=f[i-1]|(f[i-1]<<sz[i]);
        }
        else{
            f[i]=f[i-1]|(f[i-1]>>(-sz[i]));
        }
    }
    if(!f[tot][sum/2+pls]){
        printf("-1\n");
        return ;
    }
    back(tot, sum/2+pls);
    printf("%d\n", (int)ans.size());
    for(auto t:ans){
        printf("%d\n", t);
    }
}*/
signed main(){
    solve();
    //solve2();
}
