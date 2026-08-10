#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef unsigned long long ull;
const int N=6e5+5,INF=1e9;

int b[11]={64,53,43,34,26,19,13,8,4,1,0};

void Alice(){
    ull x;
    vector<int> a;
    scanf("%llu",&x);
    ull yx = x;
    for(int i=0;i<=63;i++){
        a.push_back(x&1);
        x/=2;
    }
    x = yx;
    
    int k=0;
    bool f=0;
    
    for(k=0;k<=9;k++){
        for(int i=b[k]-1;i>=b[k+1];i--){
            printf("send %d\n",a[i]);fflush(stdout);
        }
        printf("receive\n");fflush(stdout);
        int t=0;scanf("%d",&t);
        if(t == 0){
            f=1;
            break;
        }
    }
    
    if(f){
        ull ans=0;
        for(int i=b[k]-1;i>=0;i--){
            printf("receive\n");fflush(stdout);
            int t=0;scanf("%d",&t);
            a[i]=t;
        }

        for(int i=63;i>=0;i--){
            ans=ans*2;
            ans += a[i];
        }
        
        printf("answer %llu\n",ans);fflush(stdout);
        return;
    }
    
    printf("answer %llu\n",x);fflush(stdout);
    
    
    
}

void Bob(){
    ull x,yx;
    vector<int> a;
    scanf("%llu",&x);yx = x;
    for(int i=0;i<=63;i++){
        a.push_back(x&1);
        x/=2;
    }
    x = yx;
    int k=0;
    bool f=1;
    bool f2=2;
    for(k=0;k<=9;k++){
        f=1;
        for(int i=b[k]-1;i>=b[k+1];i--){
            printf("receive\n");fflush(stdout);
            int t=0;scanf("%d",&t);
            if(!f2){
                a[i]=t;
                continue;
            }
            if(!f){
                continue;
            }
            
            
            if(t!=a[i]){
                if(t>a[i])f=0;
                else{
                    f2=0;
                    a[i]=t;
                }
                
            }
        }
        if(!f2){
            printf("send 1\n");fflush(stdout);
            continue;
        }
        
        printf("send %d\n",(int)f);fflush(stdout);
        if(!f)break;
    }
    
    if(!f){
        for(int i=b[k]-1;i>=0;i--){
            printf("send %d\n",a[i]);fflush(stdout);
        }
        //cout << x << endl;
        printf("answer %llu\n",x);fflush(stdout);
        return;
    }
    ull ans=0;
    for(int i=63;i>=0;i--){
        ans=ans*2;
        ans += a[i];
    }
    printf("answer %llu\n",ans);fflush(stdout);
    
    
    
}

char role[10];

signed main(){
    //cout << ((ull)1<<63) << endl;
    //cout << ((ull)1<<31) << endl;
    scanf("%s",role);
    if(role[0]=='A')Alice();
    else Bob();
    
}
