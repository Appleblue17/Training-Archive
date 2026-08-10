#pragma GCC optimize(2)
#include<bits/stdc++.h>

//#define double long double

using namespace std;

const double eps=1e-9;

inline int dcmp(double x){
    if(abs(x)<eps)return 0;
    else if(x>0)return 1;
    else return -1;
}

struct p2{
    double x,y;
    bool tel;
    p2(double x=0,double y=0,bool tel=0):x(x),y(y),tel(tel){}
    friend p2 operator +(p2 a,p2 b){return p2(a.x+b.x,a.y+b.y);}
    friend p2 operator -(p2 a,p2 b){return p2(a.x-b.x,a.y-b.y);}
    friend p2 operator /(p2 a,double d){return p2(a.x/d,a.y/d);}
    friend bool operator ==(p2 a,p2 b){return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;}
    friend bool operator <(p2 a,p2 b){if(a.x==b.x)return a.y<b.y;else return a.x<b.x;}
};




struct rect{
    double x,y,X,Y;
    rect(double x,double y,double X,double Y):x(x),y(y),X(X),Y(Y){}
};

vector<rect> rt;
vector<p2> p,t;

int n,m,R;

void addc(p2 t,rect a,int i,int j){
    vector<p2> ret;
    p2 m = t,v;
    m.y = a.y;
    if(R*R-(t.y-m.y)*(t.y-m.y)>=0){
        v.y=0;v.x = sqrt(R*R-(t.y-m.y)*(t.y-m.y));
        ret.push_back(m+v);ret.push_back(m-v);
    }
    
    
    m.y = a.Y;
    if(R*R-(t.y-m.y)*(t.y-m.y)>=0){
        v.y=0;v.x = sqrt(R*R-(t.y-m.y)*(t.y-m.y));
        ret.push_back(m+v);ret.push_back(m-v);
    }
    
    
    m=t;m.x =a.x;
    if(R*R-(t.x-m.x)*(t.x-m.x)>=0){
        v.x=0;v.y = sqrt(R*R-(t.x-m.x)*(t.x-m.x));
        ret.push_back(m+v);ret.push_back(m-v);
    }
    
    
    m.x = a.X;
    if(R*R-(t.x-m.x)*(t.x-m.x)>=0){
        v.x=0;v.y = sqrt(R*R-(t.x-m.x)*(t.x-m.x));
        ret.push_back(m+v);ret.push_back(m-v);
    }
    
    
    for(p2 v:ret){
        //printf("i=%d,j=%d,t(%.5lf,%.5lf),find v(%.5lf,%.5lf)\n",i,j,t.x,t.y,v.x,v.y);
        if(v.x >= a.x && v.x <= a.X && v.y >= a.y && v.y <= a.Y){
            p.push_back(v);
        }
        
    }
}

double Cross(p2 a,p2 b){
    return a.x*b.y-a.y*b.x;
}

double Dis(p2 a,p2 b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool segmentPI(p2 a1,p2 a2,p2 b1,p2 b2){
    //printf("spi %.5lf,%.5lf,%.5lf,%.5lf,%.5lf,%.5lf,%.5lf,%.5lf\n",a1.x,a1.y,a2.x,a2.y,b1.x,b1.y,b2.x,b2.y);
    double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1);
    double c3 = Cross(b2-b1,a1-b1), c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

bool ckvalid(p2 st,p2 ed){
    for(rect v:rt){
        if((st == p2(v.x,v.y)) && (ed == p2(v.X,v.Y)))return 0;
        if((st == p2(v.x,v.Y)) && (ed == p2(v.X,v.y)))return 0;
        if(segmentPI(st,ed,p2(v.x,v.y),p2(v.x,v.Y)))return 0;
        if(segmentPI(st,ed,p2(v.x,v.Y),p2(v.X,v.Y)))return 0;
        if(segmentPI(st,ed,p2(v.X,v.Y),p2(v.X,v.y)))return 0;
        if(segmentPI(st,ed,p2(v.X,v.y),p2(v.x,v.y)))return 0;

        if(segmentPI(st,ed,p2(v.x,v.y),p2(v.X,v.Y)))return 0;
        if(segmentPI(st,ed,p2(v.x,v.Y),p2(v.X,v.y)))return 0;

        if(st.x > v.x+eps && st.x < v.X-eps && st.y > v.y+eps && st.y < v.Y-eps)return 0;
        if(ed.x > v.x+eps && ed.x < v.X-eps && ed.y > v.y+eps && ed.y < v.Y-eps)return 0;
    }
    return 1;
}

const int N=2e5+5;
struct nod{
    int to,nxt;
    double w;
}e[N*2];
int head[N],cnt;
void add(int u,int v,double w){
    //printf("add %d %d %.5lf\n",u,v,w);
    e[++cnt]={v,head[u],w};
    head[u]=cnt;
}
double dis[N];
bool vis[N];
queue <int> q;

signed main(){
    //cout << segmentPI(p2(0,0),p2(0,2),p2(0,1),p2(0,2)) << endl;
    scanf("%d%d%d",&n,&m,&R);
    for(int i=1;i<=n;i++){
        int x,y,X,Y;
        scanf("%d%d%d%d",&x,&y,&X,&Y);
        rt.push_back(rect(x,y,X,Y));
        p.push_back(p2(x,y));
        p.push_back(p2(x,Y));
        p.push_back(p2(X,Y));
        p.push_back(p2(X,y));
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        t.push_back(p2(x,y,1));
        p.push_back(p2(x,y,1));
    }
    p2 st,ed;
    int x,y;scanf("%d%d",&x,&y);st=p2(x,y);
    scanf("%d%d",&x,&y);ed=p2(x,y);
    p.push_back(st);p.push_back(ed);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            addc(t[j],rt[i],i,j);
        }
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    
    int N = p.size();
    for(int i=0;i<N;i++){
        //printf("p[%d]=%.5lf,%.5lf\n",i,p[i].x,p[i].y);
        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(p[i].tel){
                if(Dis(p[i],p[j])<=R+eps){
                    add(i,j,0);
                }
                else{
                    p2 v = p[j]-p[i];
                    v = v/(Dis(v,p2(0,0))/(double)R);
                    p2 u = p[i]+v;
                    //cout << Dis(v,p2(0,0)) << endl;
                    //printf("tel arc ckvalid %.5lf,%.5lf %.5lf,%.5lf\n",u.x,u.y,p[j].x,p[j].y);
                    if(ckvalid(u,p[j])){
                        add(i,j,Dis(u,p[j]));
                    }
                }
            }
            else{
                //printf("direct ckvalid %.5lf,%.5lf,%.5lf,%.5lf\n",p[i].x,p[i].y,p[j].x,p[j].y);
                if(ckvalid(p[i],p[j])){
                    //printf("valid\n");
                    add(i,j,Dis(p[i],p[j]));
                }
            }
            
        }
    }
    
    int stid=0,edid=0;
    
    for(int i=0;i<N;i++){
        if(p[i] == st){
            stid=i;
        }
        if(p[i] == ed){
            edid=i;
        }
        dis[i]=1e9;
    }
    dis[stid]=0;
    q.push(stid); vis[stid]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(dis[u]+e[i].w<dis[v]){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
                
        }
    }
    
    for(int i=0;i<N;i++){
        //printf("dis[%d]=%.5lf\n",i,dis[i]);
    }
    
    printf("%.9lf\n",dis[edid]);
    
}
