#include<bits/stdc++.h>
#define int long long
using namespace std;
#define v2 p2
struct p2{
    int x,y,i;
    p2(int x=0, int y=0):x(x),y(y) {i=0;}
    friend v2 operator -(const p2& A,const p2& B){return v2(A.x-B.x,A.y-B.y);}
    friend v2 operator +(const p2& A,const p2& B){return v2(A.x+B.x,A.y+B.y);}
    friend bool operator < (const p2& A,const p2& B){return A.x < B.x || (A.x == B.x && A.y < B.y);}
    friend bool operator == (const p2& A,const p2& B){return A.x == B.x && A.y == B.y;}
};
int c(const v2& A,const v2& B){
    return A.x*B.y - A.y*B.x;
}

int ori(p2 A){
    if(A.x < 0 && A.y >= 0)return 0;
    else if(A.x < 0 && A.y < 0)return 1;
    else if(A.x >= 0 && A.y < 0)return 2;
    else return 3;
}
p2 O;
bool cmp(p2 A,p2 B){
    if(ori(A-O) != ori(B-O)){return ori(A-O) < ori(B-O);}
    else{
        return c(A-O,B-O) > 0;
    }
}

vector<p2> CH(vector<p2> p){//modify p
    sort(p.begin(),p.end());
    //p.erase(unique(p.begin()))
    int n = p.size();
    int m = 0;
    vector<p2> ch(n+1);
    for(int i=0;i<n;i++){
        while(m>1 && c(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0)m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i=n-2;i>=0;i--){
        while(m > k && c(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0)m--;
        ch[m++] = p[i];
    }
    if(n>1)m--;
    ch.resize(m);
    return ch;
}
bool isin(const p2& p,const vector<p2>& poly){
    int n = poly.size();
    for(int i=0;i<n;i++){
        if(c(poly[(i+1)%n] - poly[i],p-poly[i]) <= 0)return false;
    }
    return true;
}
bool intri(const p2& p,const p2& A,const p2& B,const p2& C){
    vector<p2> po;
    po.push_back(A);po.push_back(B);po.push_back(C);po = CH(po);
    if(isin(p,po))return 1;
    else return 0;
}
bool ison(p2 p,p2 a,p2 b){
    return c(b-a,p-a)==0;
}
vector<p2> p,C;
void solve(){
    p.clear();C.clear();
    int n,q;
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p2 tmp = p2(x,y);
        tmp.i = i;
        p.push_back(tmp);
    }
    C = CH(p);
    /*for(p2 v:C){
        printf("%lld %lld\n",v.x,v.y);
    }*/
    if(C.size() <= 3){
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            if(isin(p2(x,y),C)){
                printf("3\n");
                printf("%lld %lld %lld\n",C[0].i,C[1].i,C[2].i);
            }
            else{
                printf("-1\n");
            }
        }
    }
    else if(C.size() == 4){
        p2 piv;
        bool f=0;
        for(int i=0;i<n;i++){
            if(ison(p[i],C[0],C[2]))continue;
            if(ison(p[i],C[1],C[3]))continue;
            piv = p[i];f=1;
            break;
        }
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            p2 u = p2(x,y);
            if(!isin(u,C)){
                printf("-1\n");
                continue;
            }
            if(intri(u,C[0],C[1],C[2])){
                printf("3\n");
                printf("%lld %lld %lld\n",C[0].i,C[1].i,C[2].i);
                continue;
            }
            if(intri(u,C[1],C[2],C[3])){
                printf("3\n");
                printf("%lld %lld %lld\n",C[1].i,C[2].i,C[3].i);
                continue;
            }
            if(intri(u,C[2],C[3],C[0])){
                printf("3\n");
                printf("%lld %lld %lld\n",C[2].i,C[3].i,C[0].i);
                continue;
            }
            if(intri(u,C[3],C[0],C[1])){
                printf("3\n");
                printf("%lld %lld %lld\n",C[3].i,C[0].i,C[1].i);
                continue;
            }
            
            if(f){
                if(intri(u,C[0],C[1],piv)){
                    printf("3\n");
                    printf("%lld %lld %lld\n",C[0].i,C[1].i,piv.i);
                    continue;
                }
                if(intri(u,C[1],C[2],piv)){
                    printf("3\n");
                    printf("%lld %lld %lld\n",C[1].i,C[2].i,piv.i);
                    continue;
                }
                if(intri(u,C[2],C[3],piv)){
                    printf("3\n");
                    printf("%lld %lld %lld\n",C[2].i,C[3].i,piv.i);
                    continue;
                }
                if(intri(u,C[3],C[0],piv)){
                    printf("3\n");
                    printf("%lld %lld %lld\n",C[3].i,C[0].i,piv.i);
                    continue;
                }
            }
            else{
                printf("4\n");
                printf("%lld %lld %lld %lld\n",C[0].i,C[1].i,C[2].i,C[3].i);
            }
        }
    }
    else{
        int tp=0,tpl,tpr;
        for(int i=0;i<C.size();i++){
            if(C[i].y > C[tp].y)tp = i;
        }
        vector<p2> CC;
        for(int i=0;i<C.size();i++){
            if(i == tp)continue;
            else{
                CC.push_back(C[i]);
            }
        }
        O = C[tp];
        tpl = tp-1;tpr = tp+1;
        if(tpl < 0)tpl+=C.size();
        if(tpr >= C.size())tpr -= C.size();
        
        sort(CC.begin(),CC.end(),cmp);
        
        //for(p2 v:CC){
        //    printf("%lld %lld\n",v.x,v.y);
        //}
        
        
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            p2 u = p2(x,y);
            int v = lower_bound(CC.begin(),CC.end(),u,cmp)-CC.begin();
            //printf("i=%lld,v=%lld\n",i,v);
            if(v == CC.size()){
                printf("-1\n");
                continue;
            }
            p2 pv,pl,pr;
            pv = CC[v];
            if(v == 0)pl = C[tp];
            else pl = CC[v-1];
            if(v+1 == CC.size())pr = C[tp];
            else pr = CC[v+1];
            
            //printf("i = %lld,tp = %lld(%lld,%lld),v = %lld(%lld,%lld)\n",i,tp,C[tp].x,C[tp].y,v,pv.x,pv.y);fflush(stdout);
            
            if(intri(u,C[tp],pv,pl)){
                printf("3\n%lld %lld %lld\n",C[tp].i,pv.i,pl.i);
                continue;
            }
            if(intri(u,C[tp],pl,pr)){
                printf("3\n%lld %lld %lld\n",C[tp].i,pl.i,pr.i);
                continue;
            }
            if(intri(u,pv,pl,pr)){
                printf("3\n%lld %lld %lld\n",pv.i,pl.i,pr.i);
                continue;
            }
            if(intri(u,C[tpl],C[tpr],pv)){
                printf("3\n%lld %lld %lld\n",C[tpl].i,C[tpr].i,pv.i);
                continue;
            }
            printf("-1\n");
            //assert(0);
        }
        
    }
    
}
signed main(){
    int T;scanf("%lld",&T);while(T--){
        solve();
    }
}