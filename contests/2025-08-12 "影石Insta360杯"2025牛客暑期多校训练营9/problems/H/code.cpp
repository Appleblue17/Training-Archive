#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
 
void gmod(int &x){
    x%=mod;
    // x-=mod;
    // x+=x>>31 & mod;
}
 
void read(int& ret){
    char c = getchar();
    ret=0;
    while(!(c >= '0' && c <= '9'))c=getchar();
    while(c >= '0' && c <= '9'){
        ret=ret*10+c-48;
        c=getchar();
    }
}
 
int n,a[N],len[N],f[N][3];
int monthlength[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};//29 because start in year 2000
unordered_map<int,int> ma;
signed main(){
    int yy=1999,mm=12,dd=31,cnt=1;
    while(yy < 3001){
        ma[yy*10000+mm*100+dd]=cnt;
        dd++;cnt++;
        if(dd > monthlength[mm]){
            dd=1;
            mm++;
        }
        if(mm == 13){
            mm=1;
            yy++;
            bool isleap=0;
            if(yy%4==0){ // mod 4 = 0
                if(yy%400==0) isleap=1; // mod 400 = 0
                else if(yy%100!=0) isleap=1; // mod 100 != 0
            }
            if(isleap)monthlength[2]=29;
            else monthlength[2]=28;
        }
    }
    //cout << ma[20250812] << endl;
    // cout<<sizeof(f)/1024/1024;
    // return 0;
    read(n);
    int h,m,s;
    for(int i=1;i<=n;i++){
        read(yy);read(mm);read(dd);read(h);read(m);read(s);
        s = h*3600 + m*60+s;
        dd = yy*10000+mm*100+dd;
        if(s < 18*3600){
            a[i]=ma[dd]-1;
            len[i]=2;
        }
        else if(s < 20*3600){
            a[i]=ma[dd]-1;
            len[i]=3;
        }
        else{
            a[i]=ma[dd];
            len[i]=2;
        }
        //printf("dd=%d,a=%d,len=%d\n",dd,a[i],len[i]);
    }
    a[0]=-1e9;
    memset(f,-48,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=0;j<len[i];j++){
            f[i][j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            f[i][1]=max(f[i][1],f[i-1][0]+1);
            f[i][2]=max(f[i][2],f[i-1][1]+1);
            f[i][0]=max(f[i][0],f[i-1][0]);
            f[i][1]=max(f[i][1],f[i-1][1]);
            f[i][2]=max(f[i][2],f[i-1][2]);
        }
        if(a[i]==a[i-1]+1){
            f[i][0]=max(f[i][0],f[i-1][0]+1);
            f[i][1]=max(f[i][1],f[i-1][1]+1);
            f[i][2]=max(f[i][2],f[i-1][2]+1);
            f[i][0]=max(f[i][0],f[i-1][1]);
            f[i][1]=max(f[i][1],f[i-1][2]);
        }
        if(a[i]==a[i-1]+2){
            f[i][0]=max(f[i][0],f[i-1][1]+1);
            f[i][1]=max(f[i][1],f[i-1][2]+1);
            f[i][0]=max(f[i][0],f[i-1][2]);
        }
        if(a[i]==a[i-1]+3){
            f[i][0]=max(f[i][0],f[i-1][2]+1);
        }
        if(len[i]!=3)f[i][2]=-1e9;
        ans = max(max(ans,f[i][0]),max(f[i][1],f[i][2]));
    }
    printf("%d 1\n",ans);
}
