#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
int n, m, k;
int a[N][N];
struct node{
    ll dt; int sz;
};
int main(){
    scanf("%d%d%d", &n, &m,  &k);
    for(int i=1; i<=k; ++i){
        for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    }
    vector<node> res;
    ll opt=0;
    for(int i=1; i<=n; ++i){
        vector<node> cur;
        vector<int> tem;
        for(int j=1; j<=k; ++j) tem.push_back(a[j][i]);
        sort(tem.begin(), tem.end());
        tem.push_back(m);
        tem.erase(unique(tem.begin(), tem.end()), tem.end());
        ll sum=0;
        for(int j=1; j<=k; ++j) sum+=a[j][i];
        opt+=sum;
        int lst=0; ll lstans=sum;
        for(auto t:tem){
            if(t==0) continue;
            int w=lst+1;
            ll curans=0;
            for(int j=1; j<=k; ++j) curans+=abs(a[j][i]-w);
            cur.push_back((node){curans-lstans, 1});
            lstans=curans;
            if(w!=t){
                curans=0;
                for(int j=1; j<=k; ++j) curans+=abs(a[j][i]-t);
                cur.push_back((node){(curans-lstans)/(t-w), t-w});
                lstans=curans;
            }
            lst=t;
        }
        int it1=0, it2=0;
        vector<node> nres;
        while(it1<(int)res.size()||it2<(int)cur.size()){
            if(it1==(int)res.size()){
                nres.push_back(cur[it2]);
                ++it2;
            }
            else if(it2==(int)cur.size()){
                nres.push_back(res[it1]);
                ++it1;
            }
            else if(res[it1].dt<cur[it2].dt){
                nres.push_back(res[it1]);
                ++it1;
            }
            else{
                nres.push_back(cur[it2]);
                ++it2;
            }
        }
        res.swap(nres);
    }
    int w=m;
    for(auto t:res){
        if(t.sz<w){
            opt+=t.dt*t.sz;
            w-=t.sz;
        }
        else{
            opt+=t.dt*w;
            break;
        }
    }
    printf("%lld\n", opt/2);
}
