#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5, mod1=998244353, mod2=993244853;
int n,k;
char s[N];
char ans[4][N];


struct que{
    int st,ed,mn,mx;//st before 0, ed after 0
    que(int st,int ed):st(st),ed(ed){
        if(s[st]=='1' && s[ed]=='0'){
            mn = 1;
            mx = (ed-st-1)/2*2+1;
        }
        else if(s[st]=='0' && s[ed]=='1'){
            mn = 1;
            mx = (ed-st-1)/2*2+1;
        }
        else if(s[st]=='0' && s[ed]=='0'){
            mn = 0;
            mx = (ed-st)/2*2;
        }
        else{
            mn = 0;
            mx = (ed-st)/2*2;
        }
    }
};

void fill(que q,int k,int o){
    //printf("fill q.st=%d,q.ed=%d,k=%d\n",q.st,q.ed,k);
    if(s[q.st] == '0' && s[q.ed] == '1'){
        int i;
        for(i=q.ed-2;i>q.st && k>1;i-=2){
            ans[o][i] = '1';
            ans[o][i+1] = '0';
            k-=2;
        }
        i++;
        while(i>q.st){
            ans[o][i]='0';i--;
        }
        
    }
    else if(s[q.st] == '1' && s[q.ed] == '0'){
        int i;
        for(i=q.ed-2;i>q.st && k>1;i-=2){
            ans[o][i] = '0';
            ans[o][i+1] = '1';
            k-=2;
        }
        i++;
        while(i>q.st){
            ans[o][i]='0';i--;
        }
    }
    else if(s[q.st] == '0' && s[q.ed] == '0'){
        for(int i=q.st+1;i<=q.ed-1;i++){
                ans[o][i]='0';
            }
        int i;
        for(i=q.ed-2;i>=q.st && k>=2;i-=2){
            ans[o][i] = '0';
            ans[o][i+1] = '1';
            k-=2;
        }
    }
    else{
        if(k == 0){
            for(int i=q.st+1;i<=q.ed-1;i++){
                ans[o][i]='1';
            }
            return;
        }
        for(int i=q.st+1;i<=q.ed-1;i++){
                ans[o][i]='0';
            }
        int i;
        for(i=q.ed-2;i>=q.st && k>=4;i-=2){
            //cout << i << endl;
            ans[o][i] = '1';
            ans[o][i+1] = '0';
            k-=2;
        }
        
        //i++;
        
        while(i>q.st){
            ans[o][i]='0';i--;
        }
    }
    
    
}

char ans2[N];

void solve2(){
    for(int i=0;i<(1<<n);i++){
        bool f=1;
        for(int o=1;o<=n;o++){
            if(s[n-o+1] != '?'){
                if(s[n-o+1]-48 != (0 < (i & (1<<(o-1))))){
                    f=0;
                }
            }
        }
        
        int cnt=0;
        for(int o=1;o<n;o++){
            //cout << (i&(1<<(o-1))) << ' ' << (i&(1<<(o))) << endl;
            if(((i&(1<<(o-1))) != 0) != ((i&(1<<o)) != 0))cnt++;
        }
        //if(i==0)cout << "i=" << i << ' ' << cnt << ' ' << f << endl;
        if(f && cnt==k){
            //cout << i << endl;
            for(int o=1;o<=n;o++){
                ans2[o]=48+((i&(1<<(o-1)))>0);
            }
            return;
        }
    }
    ans2[1]='2';
}




void solve(int o){
    //printf("solve start,s=%s\n",s+1);
    int j=0;
    int mn=0,mx=0;
    vector<que> a;
    for(int i=1;i<n;i++){
        if(s[i+1] != '?'){
            mn += (int)(s[i+1] != s[i]);
            mx += (int)(s[i+1] != s[i]);
        }
        else{
            j=i+1;
            while(s[j] == '?')j++;
            que tmp = que(i,j);
            //printf("add tmp, st=%d,ed=%d,mn=%d,mx=%d\n",tmp.st,tmp.ed,tmp.mn,tmp.mx);
            mn += tmp.mn;
            mx += tmp.mx;
            a.push_back(tmp);
            i=j-1;
        }
    }
    //printf("mn=%d,mx=%d,k=%d\n",mn,mx,k);
    if((mn&1) != (k&1)){
        //printf("o=%d,impossible\n",o);
        ans[o][1]='2';//impossible
        return;
    }
    if(!(mn <= k && k <= mx)){
        //printf("o=%d,impossible\n",o);
        ans[o][1]='2';//impossible
        return;
    }
    int m = a.size();
    for(int i=0;i<m;i++){
        if((s[a[i].st] == '1' && s[a[i].ed]=='1')){
            bool f=0;
            for(int j=a[i].mn+2;j<=a[i].mx;j+=2){
                int nmn = mn - a[i].mn+j;
                int nmx = mx - a[i].mx+j;
                if(nmn <= k && k <= nmx){
                    fill(a[i],j,o);
                    mn = nmn;
                    mx = nmx;
                    f=1;
                    break;
                }
            }
            if(f)continue;
            int j = a[i].mn;
            int nmn = mn - a[i].mn+j;
            int nmx = mx - a[i].mx+j;
            if(nmn <= k && k <= nmx){
                fill(a[i],j,o);
                mn = nmn;
                    mx = nmx;
                f=1;
            }
        }
        else{
            for(int j=a[i].mn;j<=a[i].mx;j+=2){
                int nmn = mn - a[i].mn+j;
                int nmx = mx - a[i].mx+j;
                if(nmn <= k && k <= nmx){
                    fill(a[i],j,o);
                    mn = nmn;
                    mx = nmx;
                    break;
                }
            }
        }
        //printf("i=%d,mn=%d,mx=%d,k=%d\n",i,mn,mx,k);
    }
    for(int i=1;i<=n;i++){
        if(s[i]!='?')ans[o][i]=s[i];
    }
}

int id[4];

bool cmp(int x,int y){
    for(int i=1;i<=n;i++){
        if(ans[x][i] != ans[y][i]){
            return ans[x][i] < ans[y][i];
        }
    }
    return 0;
}

signed main(){
    //freopen("Itest.in","r",stdin);
    //freopen("I.out","w",stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        //solve2();
        bool f[2]={0,0};
        if(s[1]=='?')f[0]=1;
        if(s[n]=='?')f[1]=1;
        for(int i=0;i<=1;i++){
            if(f[0])s[1]=i+48;
            for(int j=0;j<=1;j++){
                if(f[1])s[n]=j+48;
                solve(i*2+j);
            }
        }
        
        for(int i=0;i<=3;i++)id[i]=i;
        sort(id,id+4,cmp);
        if(ans[id[0]][1]=='2'){
            printf("Impossible\n");
        }
        else{
            for(int i=1;i<=n;i++){
                putchar(ans[id[0]][i]);
            }
            
            putchar('\n');
            //for(int i=n;i>=1;i--){
            //    putchar(ans2[i]);
            //}
            //putchar('\n');
        }
        
        /*if(ans[id[0]][1] == '2' && '2' == ans2[1]){
            
        }
        else{
            bool fl=0;
            for(int i=1;i<=n;i++){
                if(ans[id[0]][i] != ans2[n-i+1]){
                    fl=1;
                }
            }
            if(fl){
                printf("WA.n=%d,k=%d\n",n,k);
                for(int i=1;i<=n;i++){
                putchar(ans[id[0]][i]);
            }
            putchar('\n');
            for(int i=1;i<=n;i++){
                putchar(ans2[n-i+1]);
            }
            putchar('\n');
                if(f[0])s[1]='?';
                if(f[1])s[n]='?';
            
            for(int i=1;i<=n;i++){
                putchar(s[i]);
            }
            putchar('\n');
            }
            
        }*/
        
        
        
    }
}
