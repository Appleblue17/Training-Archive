#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ans;
void fill(int n,int m,int oi,int oj,bool revx,bool revy){
    if(n<=0 || m <= 0)return;
    int N=n,M=m;
    if(n >= m-1 && m%2==0){
        for(int j=1;j<=n;j+=2){
            if(revx)ans.push_back(N-j+1);
            else ans.push_back(j+oi);
            if(revy)ans.push_back(M);
            else ans.push_back(1+oj);
        }
        for(int j=2;j<n;j+=2){
            if(revx)ans.push_back(N-j+1);
            else ans.push_back(j+oi);
            if(revy)ans.push_back(M-m+1);
            else ans.push_back(m+oj);
        }
        return;
    }
    if(n == m && m%2==1){
        n -= 2;
    }
    if(n%2==0)n--;
    if(m%2==0)m--;
    
    for(int j=1;j<=n;j+=2){
            if(revx)ans.push_back(N-j+1);
            else ans.push_back(j+oi);
            if(revy)ans.push_back(M);
            else ans.push_back(1+oj);
        }
        for(int j=1;j<=n;j+=2){
            if(revx)ans.push_back(N-j+1);
            else ans.push_back(j+oi);
            if(revy)ans.push_back(M-m+1);
            else ans.push_back(m+oj);
        }
    for(int i=(n+1)/2+2;i<=(m-(n+1)/2-1);i+=2){
        if(revx)ans.push_back(N-(n+1)/2+1);
        else ans.push_back((n+1)/2+oi);
        if(revy)ans.push_back(M-i+1);
        else ans.push_back(i+oj);
        
    }
}

int main(){
    bool f=0;
    scanf("%d%d",&n,&m);
    
    
    if(n>m){
        f=1;
        swap(n,m);
    }
    if(n == 1){
        printf("%d\n",m);
        for(int i=1;i<=m;i++){
            if(!f)printf("%d %d\n",1,i);
            else printf("%d %d\n",i,1);
        }
        return 0;
    }
    if(n%2 == 1 && m%2==1){
        fill(n,m,0,0,0,0);
        fill(n-1,m,1,0,0,0);
    }
    else if(m%2==0){
        fill(n,m,0,0,0,0);
        fill(n,m,0,0,0,1);
    }
    else{
        fill(n,m,0,0,0,0);
        fill(n,m,0,0,1,0);
    }
    printf("%d\n",ans.size()/2);
    for(int i=0;i<ans.size();i+=2){
        if(f)swap(ans[i],ans[i+1]);
        printf("%d %d\n",ans[i],ans[i+1]);
    }
}
