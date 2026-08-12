#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, cnt[17],rem[17],mn[17],c[17],L[17],R[17],t[17][10], C;
char s[40];
bool checkb(){
    for(int i=1;i<=15;i++){
        if(c[i]<0)return 0;
    }
    if(c[14] + c[15] != 4 && c[14] + c[15] != 0)return 0;
    for(int i=13;i>=1;i--){
        if(c[i] > 0 && c[i] < mn[i])return 0;
    }
    return 1;
}
bool checkbp(){
    for(int i=1;i<=15;i++){
        if(c[i]<0)return 0;
    }
    int f[20][8];
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    for(int i=1;i<=15;i++){
        for(int j=0;j<=6;j++){
            for(int k=0;k<=4;k++){
                if(t[i][k] && j-k>=0)
                    f[i][j] = max(f[i][j],f[i-1][j-k]);
            }
        }
    }
    if(f[15][C])return 1;
    else return 0;
}
bool checksc(){
    for(int i=1;i<=15;i++){
        if(c[i]<0)return 0;
    }
    memset(t,0,sizeof(t));
    if(c[14] + c[15] != 4 && c[14] + c[15] != 0 && c[14]+c[15] != 2)return 0;
    if(c[14] == 1 || c[15] == 1)return 0;
    if(c[14] + c[15] == 2){
        t[14][1] = 1;
        t[15][0] = 1;
    }
    else{
        t[14][0] = 1;
        t[15][0] = 1;
    }
    for(int i=1;i<=13;i++){
        if(c[i] == 1 || c[i] == 3 || c[i] == 5){
            return 0;
        }
        if(c[i] == 7){
            if(mn[i] > 7)
                return 0;
            else
                t[i][0] = 1;
        }
        
        for(int j=0;j<=c[i];j+=2){
            // play (c[i]-j)/2 duels
            if(mn[i] <= c[i]-j || j==c[i]){
                t[i][(c[i]-j)/2] = 1;
            }
        }
        
    }
    return checkbp();
}

void solve(){
    scanf("%s",s);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=13;i++){
        rem[i] = 8;
        mn[i]=0;
    }
    
    rem[14] = rem[15] = 2;
    for(int i=0;i<33;i++){
        int x=0;
        if(s[i]>='3' && s[i] <= '9')x = s[i]-'2';
        else if(s[i] == 'T')x = 8;
        else if(s[i] == 'J')x = 9;
        else if(s[i] == 'Q')x = 10;
        else if(s[i] == 'K')x = 11;
        else if(s[i] == 'A')x = 12;
        else if(s[i] == '2')x = 13;
        else if(s[i] == 'w')x = 14;
        else if(s[i] == 'W')x = 15;
        cnt[x]++;
        rem[x]--;
    }

    for(int i=13;i>=1;i--){
        R[i] = max(R[i+1],rem[i]);
    }
    for(int i=1;i<=13;i++){
        L[i] = max(L[i-1],rem[i]);
    }
    for(int i=1;i<=13;i++){
        mn[i] = max(L[i-1],R[i+1]+1);
    }
    
    if(rem[14] == rem[15] && rem[15] == 2){
        for(int i=1;i<=13;i++){
            mn[i] = 9;
        }
    }
    
    //for(int i=1;i<=13;i++){
    //    printf("mn[%d]=%d\n",i,mn[i]);
    //}
    
    
    //for(int i=1;i<=15;i++)c[i] = cnt[i];
    for(int l=1;l<=12;l++){
        for(int r=l+4;r<=12;r++){
            for(int i=1;i<=15;i++)c[i] = cnt[i];
            for(int j=l;j<=r;j++)c[j]--;
            if(checkb()){
                printf("Yes\n");
                return;
            }
        }
    }
    
    for(int l=1;l<=12;l++){
        for(int r=l+2;r<=12;r++){
            for(int i=1;i<=15;i++)c[i] = cnt[i];
            for(int j=l;j<=r;j++)c[j]-=2;
            if(checkb()){
                printf("Yes\n");
                return;
            }
        }
    }
    
    for(int l=1;l<=12;l++){
        for(int r=l+1;r<=12;r++){
            for(int i=1;i<=15;i++)c[i] = cnt[i];
            for(int j=l;j<=r;j++)c[j]-=3;
            if(checkb()){
                printf("Yes\n");
                return;
            }
        }
    }
    
    for(int l=1;l<=15;l++){
        for(int r=0;r<=cnt[l];r++){
            for(int i=1;i<=15;i++)c[i] = cnt[i];
            c[l] -= r;
            if(checkb()){
                printf("Yes\n");
                return;
            }
        }
    }
    
    //SC
    for(int l=1;l<=12;l++){
        for(int r=l+1;r<=12;r++){
            for(int i=1;i<=15;i++)c[i] = cnt[i];
            for(int j=l;j<=r;j++)c[j]-=3;
            C = r-l+1;
            //if(l == 1 && r == 5){
            //    for(int i=1;i<=15;i++)cout << c[i] << ' ';
            //    cout << endl;
            //}
            if(checksc()){
                printf("Yes\n");
                return;
            }
        }
    }
    
    printf("No\n");
    
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}