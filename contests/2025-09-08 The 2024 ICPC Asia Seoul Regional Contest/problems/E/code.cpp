#include <bits/stdc++.h>
using namespace std;
const int N=220000;
int n,ta[N];
double ans[N][2];
#define v2 p2
struct p2{
    double x,y;
    p2(double x=0.0,double y=0.0):x(x),y(y){}
    friend v2 operator - (const p2& A,const p2& B){return v2(A.x-B.x,A.y-B.y);}
    friend bool operator < (const p2& A,const p2& B){return A.x < B.x || (A.x == B.x && A.y < B.y);}
};
double Cross(const v2& A,const v2& B){
    return A.x * B.y - A.y * B.x;
}
double Dot(const v2& A,const v2& B){
    return A.x*B.x + A.y * B.y;
}
double Length(const v2& A){return sqrt(Dot(A,A));}
vector<p2> p;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ta[i]);
    }
    for(int i=0;i<=n*2+1;i++){
        ans[i][0]=ans[i][1]=1e9;
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            p.push_back(p2(ta[i-1],ta[i]));
        }
        else{
            p.push_back(p2(ta[i],ta[i-1]));
        }
    }
    //sort(p.begin(),p.end());
    int x,y;
    scanf("%d%d",&x,&y);
    p2 S = p2(x,y);
    scanf("%d%d",&x,&y);
    p2 T = p2(x,y);
    int sid,tid;
    //sid = lower_bound(p.begin(),p.end(),S)-p.begin();
    //tid = lower_bound(p.begin(),p.end(),T)-p.begin();
    n = p.size();
    for(int i=0;i<n;i++)p.push_back(p[i]);
    int l=0,r=n-1,m;
    while(l<r){
        m=(l+r)/2;
        if(p[m].x < S.x){
            l = m+1;
        }
        else r = m;
    }
    sid = l;
    l=0;r=n-1;
    while(l<r){
        m=(l+r)/2;
        if(p[m].x < T.x){
            l = m+1;
        }
        else r = m;
    }
    tid = l;
    if(S.y < 0)sid = 0;
    
    //printf("sid=%d,tid=%d\n",sid,tid);fflush(stdout);
    
    m=0;
    vector<p2> res(n+1);
    double dis=0;
    
    m=0;dis=0;
    res[m++]=S;
    //printf("sid = %d,n=%d\n",sid,n);
    //for(int i=0;i<n;i++){
    //    printf("i=%d,(%.5lf,%.5lf)\n",i,p[i].x,p[i].y);
    //}
    for(int i=sid;i<n+sid;i++){
        while(m > 1 && Cross(res[m-1]-res[m-2],p[i]-res[m-2]) >= 0){
            dis -= Length(res[m-1]-res[m-2]);m--;
        }
        dis += Length(p[i]-res[m-1]);
        ans[i%n][0] = min(ans[i%n][0],dis);
        res[m++] = p[i];
    }
    
    m=0;dis=0;
    res[m++]=S;
    for(int i=sid-1+n;i>sid-1;i--){
        while(m > 1 && Cross(res[m-1]-res[m-2],p[i]-res[m-2]) <= 0){
            dis -= Length(res[m-1]-res[m-2]);
            //printf("i=%d,delete length %.5lf\n",i,Length(res[m-1]-res[m-2]));
            m--;
        }
        dis += Length(p[i]-res[m-1]);
        //printf("i=%d,add length %.5lf\n",i,Length(p[i]-res[m-1]));
        ans[i%n][0] = min(ans[i%n][0],dis);
        res[m++] = p[i];
    }
    
    //for(int i=0;i<n;i++){
    //    printf("%.5lf ",ans[i][0]);
    //}putchar('\n');
    
    m=0;dis=0;
    res[m++]=T;
    //printf("tid = %d,n=%d\n",tid,n);
    for(int i=tid;i<n;i++){
        while(m > 1 && Cross(res[m-1]-res[m-2],p[i]-res[m-2]) <= 0){
            dis -= Length(res[m-1]-res[m-2]);
            //printf("i=%d,delete length %.5lf\n",i,Length(res[m-1]-res[m-2]));
            m--;
        }
        dis += Length(p[i]-res[m-1]);
        //printf("i=%d,add length %.5lf\n",i,Length(p[i]-res[m-1]));
        ans[i][1] = dis;
        res[m++] = p[i];
    }
    
    m=0;dis=0;
    res[m++]=T;
    for(int i=tid;i>=0;i--){
        while(m > 1 && Cross(res[m-1]-res[m-2],p[i]-res[m-2]) >= 0){
            dis -= Length(res[m-1]-res[m-2]);m--;
        }
        dis += Length(p[i]-res[m-1]);
        ans[i][1] = dis;
        res[m++] = p[i];
    }
    double lb = -1e9,rb = 1e9;
    for(int i=0;i<n;i++){
        if(p[i].y < 0.5){
            if(p[i].x < T.x){
                lb = max(lb,p[i].x);
            }
            else{
                rb = min(rb,p[i].x);
            }
        }
    }
    //cout << endl << lb << ' ' << rb << endl;
    for(int i=0;i<n;i++){
        if(p[i].x <= lb-0.1 || p[i].x >= rb+0.1){
            ans[i][1]=1e9;
        }
    }
    
    // for(int i=0;i<n;i++){
    //     printf("%.5lf ",ans[i][1]);
    // }putchar('\n');
    
    double mn = ans[0][0]+ans[0][1];
    for(int i=1;i<n;i++){
        mn = min(mn,ans[i][0]+ans[i][1]);
    }
    printf("%.10lf\n",mn);
    
}



