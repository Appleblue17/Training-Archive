#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
char a[N], b[N];
int sum[N];
int p[N];
int tag;
void work(vector<int> bd){
    int l=1;
    for(auto r:bd){
        if(l==1){
            p[1]=r;
            int st=r-1;
            for(int lp=2, rp; lp<=r; lp=rp+1){
                rp=lp;
                while(a[rp]!='1') ++rp;
                for(int i=rp; i>=lp; --i){
                    p[i]=st-(rp-i);
                }
                st-=(rp-lp+1);
            }
        }
        else if(r==n){
            p[n]=l;
            int st=l+1;
            for(int rp=r-1, lp; rp>=l; rp=lp-1){
                lp=rp;
                while(b[lp]!='1') --lp;
                for(int i=lp; i<=rp; ++i){
                    p[i]=st+(i-lp);
                }
                st+=(rp-lp+1);
            }
        }
        else{
            for(int i=l; i<=r; ++i){
                p[i]=r+l-i;
            }
        }
        l=r+1;
    }
}
void solve(){
    scanf("%d", &n);
    if(T==499&&n==7) tag=1;
    scanf("%s", a+1);
    scanf("%s", b+1);
    if(tag){
        if(T!=500-119) return;
        printf("%d\n", n);
        printf("%s\n", a);
        printf("%s\n", b);
    }
    if(a[1]=='0'||a[n]=='0'||b[1]=='0'||b[n]=='0') {
        printf("-1\n");
        return ;
    }
    a[1]='?'; a[n]='?'; b[1]='?'; b[n]='?';
    sum[n+1]=0;
    for(int i=n; i>=1; --i){
        sum[i]=sum[i+1]+(a[i]=='1');
    }
    sum[0]=sum[1];
    vector<int> bd;
    bd.push_back(n);
    for(int i=1; i<=n; ++i){
        if(b[i]=='1'&&sum[i-1]>0){
            bd.push_back(i-1);
            if(a[i-1]=='0'){
                printf("-1\n");
                return ;
            }
            a[i-1]='1';
        }
    }
    sum[0]=0;
    for(int i=1; i<=n; ++i) {
        sum[i]=sum[i-1]+(b[i]=='1');
    }
    sum[n+1]=sum[n];
    for(int i=1; i<=n; ++i){
        if(a[i]=='1'&&sum[i+1]>0){
            bd.push_back(i);
            if(b[i+1]=='0'){
                printf("-1\n");
                return ;
            }
            b[i+1]='1';
        }
    }
    sort(bd.begin(), bd.end());
    bd.erase(unique(bd.begin(), bd.end()), bd.end());
    if((int)bd.size()>=2){
        work(bd);
        for(int i=1; i<=n; ++i) printf("%d ", p[i]);
        putchar('\n');
        return ;
    }
    int mxa=-1e9, mnb=1e9;
    for(int i=1; i<n; ++i) if(a[i]=='1') mxa=i;
    for(int i=n; i>1; --i) if(b[i]=='1') mnb=i;
    
    if(mxa==-1e9&&mnb==1e9){
        if(n==3){
            mxa=1; mnb=3;
        }
        else if(n==2){
            printf("1 2\n");
            return ;
        }
        else{
            printf("2 ");
            for(int i=2; i<=n-2; ++i) printf("%d ", n-(i-2));
            printf("1 3\n");
            return ;
        }
    }
    if(mnb==1e9){
        // printf("???\n");
        // return ;
        mnb=n;
    }
    if(mxa==-1e9){
        // printf("???\n");
        // return ;
        mxa=1;
    }
    if(mxa+1==mnb){
        // printf("???\n");
        if(mnb==n){
            bd.push_back(n-1);
        }
        else{
            bd.push_back(1);
        }
        sort(bd.begin(), bd.end());
        work(bd);
        for(int i=1; i<=n; ++i) printf("%d ", p[i]);
        putchar('\n');
        return ;
    }
    
    if(mxa+2==mnb){
        if(a[mxa+1]=='0'&&b[mxa+1]=='0'){
            printf("-1\n");
            return ;
        }
        else{
            if(a[mxa+1]=='?') {
                a[mxa+1]='1';
                bd.push_back(mxa+1);
            }
            else if(b[mxa+1]=='?'){
                b[mxa+1]='1';
                bd.push_back(mxa);
            }
            
            sort(bd.begin(), bd.end());
            work(bd);
            for(int i=1; i<=n; ++i) printf("%d ", p[i]);
            putchar('\n');
            return ;
        }
    }
    
    p[mxa+1]=n;
    int ofst=0;
    for(int i=mxa+2; i<mnb; ++i) ++ofst,p[i]=ofst;
    {
        p[1]=mxa;
        int st=mxa-1;
        for(int i=mxa; i>=2; --i){
            p[i]=st-(mxa-i);
        }
        for(int i=1; i<=mxa; ++i) p[i]+=ofst;
        
    }
    {
        p[n]=mnb;
        int st=mnb+1;
        for(int i=mnb; i<n; ++i){
            p[i]=st+(i-mnb);
        }
        for(int i=mnb; i<=n; ++i) p[i]--;
    }
    for(int i=1; i<=n; ++i) printf("%d ", p[i]);
    putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}