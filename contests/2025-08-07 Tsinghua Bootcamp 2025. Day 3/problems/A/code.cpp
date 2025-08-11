#include <bits/stdc++.h>
using namespace std;
const int N=220;

int n,m;
char S[N][22];


int get_empty(int r){
    int tot=0;
    for(int i=1;i<=11;i++) tot+=(S[r][i]=='-');
    return tot;
}

int getdis(int r){
    return min({abs(r),abs(r-n/2-1),abs(r-n-2)});
}

int find_row(){
    int x=get_empty(1),y=get_empty(n/2+2);
    if(x || y){
        if(x>=y) return 1;
        else return n/2+2;
    }
    
    int mx=0,r=0;
    for(int i=n+1;i>=1;i--){
        int val=get_empty(i);
        int dr=getdis(r),di=getdis(i);
        if(val>mx || (val==mx && di<dr) || (val==mx && di==dr && i<r)) mx=val,r=i;
    }
    return r;
}

int L,R;
void select(int r,int x,int y,char c){
    if(S[r][x]=='-' && S[r][y]=='-'){
        if(L<=R){
            S[r][x]=c;
            L++;
        }
        else{
            S[r][y]=c;
            R++;
        }
    }
    else if(S[r][x]=='-'){
        S[r][x]=c;
        L++;
    }
    else if(S[r][y]=='-'){
        S[r][y]=c;
        R++;
    }
}


signed main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+2;i++){
        scanf("\n%s",S[i]+1);
        for(int j=1;j<=11;j++){
            if(S[i][j]=='#'){
                if(j<=5) L++;
                if(j>=7) R++;
            }
        }
    }
    
    for(int t=0;t<m;t++){
        int r=find_row();
        char c='a'+t;
        // cout<<c<<" "<<r<<endl;
        
        if(S[r][5]=='-' || S[r][7]=='-') select(r,5,7,c);
        else if(S[r][3]=='-' || S[r][9]=='-') select(r,3,9,c);
        else if(S[r][1]=='-' || S[r][11]=='-') select(r,1,11,c);
        else if(S[r][6]=='-'){
            S[r][6]=c;
        }
        else select(r,2,10,c);
    }
    
    for(int i=0;i<=n+2;i++){
        for(int j=1;j<=11;j++) putchar(S[i][j]);
        putchar('\n');
    }
    
}