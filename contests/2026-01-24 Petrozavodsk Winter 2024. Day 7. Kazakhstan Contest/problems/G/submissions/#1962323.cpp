#include <bits/stdc++.h>
using namespace std;
#define int long long

#define db __float128
const db eps = 1e-12;

db abs(db x){
    if(x<0)return -x;
    else return x;
}

int dcmp(db x){
    if(abs(x)<eps)return 0;
    else if(x<0)return -1;
    else return 1;
}

struct p2{
    db x,y;
    int id,px,qx,py,qy;
    p2(db x,db y):x(x),y(y){}
    p2(int px,int qx,int py,int qy,int id=0):px(px),py(py),qx(qx),qy(qy),id(id){
        x = px/(db)qx;
        y = py/(db)qy;
    }
    
    friend p2 operator - (p2 a,p2 b){return p2(a.x-b.x,a.y-b.y);}
    friend bool operator == (p2 a,p2 b){return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;}
};



vector<p2> a,l,p;
const int B=201;
vector<int> g[(B+10)*(B+10)];
const int BB = (B+10)*(B+10)-1;
bool vis[BB+10];

vector<int> adj[B+10];

void add(int u,int mid,int v){
    //printf("add %lld %lld %lld\n",u,mid,v);fflush(stdout);
    g[u*B+mid].push_back(mid*B+v);
}

db Cross(p2 a,p2 b){
    return a.x*b.y - a.y*b.x;
}

p2 O=p2(0,0);
int ori(p2 a){
    a = a-O;
    if(a.x < 0 && a.y < 0)return 0;
    else if(a.x >= 0 && a.y < 0)return 1;
    else if(a.x >= 0 && a.y >= 0)return 2;
    else return 3;
}

bool tgcmp(int i,int j){
    p2 A = a[i];
    p2 B = a[j];
    if(ori(A) != ori(B))return ori(A)<ori(B);
    return Cross(A-O,B-O) > 0;
}

bool cmp(p2 a,p2 b){
    if(a.px == b.px && a.qx == b.qx){
        return a.py*b.qy < a.qy*b.py;//a.y < b.y
    }
    else{
        return a.px*b.qx < a.qx*b.px;//a.x < b.x
    }
}




bool col(p2 a,p2 b,p2 c){
    //printf("%.5lf,%.5lf %.5lf,%.5lf\n",(a-b).x,(a-b).y,(a-c).x,(a-c).y);
    //cout << Cross(a-b,a-c) << endl;
    if(abs(Cross(a-b,a-c))<=eps)return 1;
    else return 0;
}

signed main(){
    int N,n=0;
    cin >> N;
    for(n=1;n<=20;n++){
        if(N == n*(n-1)/2)break;
    }
    //if(N != n*(n-1)/2){
    //    
    //}
    a.push_back(p2(0,0));
    for(int i=1;i<=N;i++){
        int px,qx,py,qy;
        cin >> px >> qx >> py >> qy;
        a.push_back(p2(px,qx,py,qy,i));
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            
            l.clear();
            for(int k=1;k<=N;k++){
                if(k==i || k==j){
                    //sm++;
                    //printf("i=%lld,j=%lld,add k=%lld\n",i,j,k);
                    l.push_back(a[k]);
                    continue;
                } 
                
                if(col(a[i],a[j],a[k])){
                    //printf("i=%lld,j=%lld,k=%lld,(%.5lf,%.5lf),(%.5lf,%.5lf),(%.5lf,%.5lf)\n",i,j,k,a[i].x,a[i].y,a[j].x,a[j].y,a[k].x,a[k].y);
                    //sm++;
                    //printf("i=%lld,j=%lld,add k=%lld\n",i,j,k);
                    l.push_back(a[k]);
                }
                
            }
            if(l.size() == n-1){
                sort(l.begin(),l.end(),cmp);
                //printf("new line:\n");
                for(int i=1;i<l.size();i++){
                    int u = l[i-1].id;
                    int v = l[i].id;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    //printf("adj add %lld,%lld\n",u,v);
                }
            }
        }
    }
    //cout << "*@" << endl;
    for(int i=1;i<=N;i++){
        O = a[i];
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
        sort(adj[i].begin(),adj[i].end(),tgcmp);
        
        adj[i].push_back(adj[i][0]);
        //for(int v:adj[i]){
        //    cout << v << endl;
        //}
        for(int j=1;j<adj[i].size();j++){
            int u = adj[i][j-1];
            int v = adj[i][j];
            //printf("i=%lld\n",i);
            add(u,i,v);
        }

    }
    //cout << "*#" << endl;

    for(int i=0;i<BB;i++){
        vector<p2> ans;
        int u = i,cnt=0;
        if(vis[u])continue;
        vis[u]=1;
        do{
            if(g[u].size()==0){
                u=0;
                break;
                
            }
            ans.push_back(a[u/B]);
            cnt++;
            u = g[u][0];
            vis[u]=1;
        }while(u != i && u != 0);
        if(u == 0)continue;
        if(cnt == n){
            cout << n << endl;
            for(p2 v:ans){
                printf("%d %d %d %d\n",v.px,v.qx,v.py,v.qy);
            }
            return 0;
        }
    }
    
}
