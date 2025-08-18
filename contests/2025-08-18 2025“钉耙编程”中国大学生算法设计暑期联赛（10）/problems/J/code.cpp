#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
char s[N];
int n,m;
vector<bool> a[N];
vector<bool> x;
int r0[N*5*2],cr0[N*5],ansr0[N*5];
int ls0=0;
void read(vector<bool>& x){
    x.clear();
    scanf("%s",s);
    for(int i=0;i<m;i++){
        char c = s[i];
        if(c >= 'a')c = c-'a'+10;
        else c = c-'0';
        x.push_back(c/16);
        x.push_back(c/8%2);
        x.push_back(c/4%2);
        x.push_back(c/2%2);
        x.push_back(c%2);
    }
}
void Prin(vector<bool> x){
    for(int i=0;i<m;i++){
        printf("%d",(int)x[i]);
    }
    putchar('\n');
}
void mian(){
    scanf("%d%d",&n,&m);
    read(x);
    ls0=-1;
    for(int j=m*5-1;j>=0;j--){
        //printf("x[%d]=%d\n",j,(int)x[j]);
        if(x[j]==0){
            ls0 = j;
            break;
        }
    }
    //cout << ls0 << endl;
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    if(ls0==-1){
        printf("%d\n",n);
        return;
    }
    m*=5;
    for(int i=n;i>=0;i--){
        //r0[i].resize(m);
        
        for(int j=0;j<m;j++){
            if(i==n){
                //r0[i][j]=n+1;
                r0[i*m+j]=n+1;
                continue;
            }
            r0[i*m+j]=r0[(i+1)*m+j];
            //r0[i][j] = r0[i+1][j];
            //if(a[i+1][j]==0)r0[i][j]=i+1;
            if(a[i+1][j]==0)r0[i*m+j]=i+1;
            //printf("r0[%d][%d]=%d\n",i,j,r0[i][j]);
        }
    }
    //Prin(x);Prin(a[1]);
    //cr0.resize(n+1);
    for(int i=0;i<=n;i++){
        cr0[i]=i+1;
    }
    int ans=0;
    for(int j=0;j<m;j++){
        if(x[j]==0){
            for(int i=0;i<=n;i++){
                cr0[i]=max(cr0[i],r0[i*m+j]);
            }
        }
        if(x[j]==1 || j==ls0){
            //ansr0.resize(n+1);
            for(int i=0;i<=n;i++){
                ansr0[i]=max(cr0[i],r0[i*m+j]);
                //printf("j=%d,ansr0[%d]=%d\n",j,i,ansr0[i]);
            }
            int u=0,cnt=0;
            while(u<=n){
                u=ansr0[u];
                cnt++;
            }
            cnt--;
            ans = max(ans,cnt);
            //printf("j=%d,cnt=%d\n",j,cnt);
            if(j==ls0)break;
        }
        
    }
    if(ans==0)ans--;
    printf("%d\n",ans);
    // double sum=0;
    // for(int i=0; i<=n; ++i){
    //     sum+=a[i].end()-a[i].begin();
    // }
    // sum/=1024*1024;
    // cout<<sum<<endl;
}
signed main(){
    int T;
    scanf("%d",&T);while(T--){mian();};
    
}