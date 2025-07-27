#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int A,B,C;
const int N=5e6+5;
int y[100];
bool f[100];
vector <int> ans;
int as,cs,bs;
 
void cons(){// c>=b>=a or b>=c>=a
    as=bs=cs=0;
    while(a >> as > 0)as++;
    as--;
    while(c >> cs > 0)cs++;
    cs--;
    while(b >> bs > 0)bs++;
    bs--;
    //printf("construct a=%lld,b=%lld,c=%lld,as=%d,bs=%d,cs=%d\n",a,b,c,as,bs,cs);
    if(a == b && b == c)return;
     
    memset(y,0,sizeof(y));
    memset(f,0,sizeof(f));
     
    ll x=c^a;
     
    if(bs < cs){
        x = c^(a << (cs-bs));
    }
     
    //b = b << (30-bs);
    if(cs > bs){
    y[cs]=b<<(cs-bs);
     
    for(int i=cs-1;i>=cs-bs;i--){
        //y[bs+i] = b << i;
        if(i-bs >= 0){
            y[i] = (b<<(i-bs) & ((1<<31)-(1<<(cs-bs))));
        }
        else{
            y[i] = (b>>(bs-i) & ((1<<31)-(1<<(cs-bs))));
        }
    }
    for(int i=0;i<(cs-bs);i++){
        y[i] = 1<<i;
    }
    //cout << x << endl;
    for(int i=cs;i>=0;i--){
         
        if((x & (1<<i)) && (y[i] & (1<<i))){
            x = x^y[i];
            f[i]=1;
        }
        //printf("y[%d]=%d,f[%d]=%d\n",i,y[i],i,f[i]);
    }
    for(int i=cs;i>=cs-bs;i--){
        if(f[i])ans.push_back(3),a=a^b;
        if(i != cs-bs)ans.push_back(2),b/=2;
        //printf("a=%lld,b=%lld\n",a,b);
    }
    ans.push_back(1);a*=2;
    for(int i=cs-bs-1;i>=0;i--){
        if(f[i])ans.push_back(3),a=a^b;
        if(i != 0)ans.push_back(1),a*=2;
    }
    ans.push_back(2);
    b/=2;
    ans.push_back(4);
    b=b^a;
     
     
    }
    else{
        y[bs]=b;
        for(int i=bs-1;i>=0;i--){
            y[i]=b>>(bs-i);
        }
         
        for(int i=30;i>=0;i--){
         
            if((x & (1<<i)) && (y[i] & (1<<i))){
                x = x^y[i];
                f[i]=1;
            }
         
        }
         
        for(int i=bs;i>=0;i--){
            if(f[i])ans.push_back(3),a=a^b;
            ans.push_back(2),b/=2;
        }
         
        ans.push_back(4);
        b=b^a;
    }
    //printf("construction complete, a=%lld,b=%lld,c=%lld\n",a,b,c);
     
}
 
void solve(){
    as = bs = cs = 0;
     
    if(a == b && b == 0){
        if(c == 0){
            printf("0\n\n");
        }
        else{
            printf("-1\n");
        }
        return;
    }
    ans.clear();
    as=bs=cs=0;
    while(a >> as > 0)as++;
    as--;
    while(c >> cs > 0)cs++;
    cs--;
    while(b >> bs > 0)bs++;
    bs--;
     
    if(c!=0){
         
     
    /*if(a==0){
        a = a^b;
        ans.push_back(3);
        as=0;
        while(a >> as > 0)as++;
    as--;
    }*/
     
     
     
     
     
    }
    if(c == 0 || (cs < bs && cs < as)){
        while(bs > cs){
            ans.push_back(2);
            bs--;b/=2;
        }
        //swap(a,b);
        //swap(as,bs);
        //if(c != 0)ans.push_back(3);
        b = b^a;
        a = a^b;
        ans.push_back(4);ans.push_back(3);
        as=bs=cs=0;
    while(a >> as > 0)as++;
    as--;
    while(c >> cs > 0)cs++;
    cs--;
    while(b >> bs > 0)bs++;
    bs--;
        while(bs > cs){
            ans.push_back(2);
            bs--;b/=2;
        }
         
    }
 
    as=bs=cs=0;
    while(a >> as > 0)as++;
    as--;
    while(c >> cs > 0)cs++;
    cs--;
    while(b >> bs > 0)bs++;
    bs--;
 
    if(as > bs){
        b=b^a;
        bs=0;
        while(b >> bs > 0)bs++;
        bs--;
        ans.push_back(4);
    }
     
    cons();
 
    if(a != c || b != c){
        printf("input = %d %d %d\n",A,B,C);
        exit(-1);
    }
    if(ans.size()>64){
        printf("input = %d %d %d\n",A,B,C);
        exit(-1);
    }
 
    printf("%d\n",ans.size());
    for(int v:ans)printf("%d ",v);
    putchar('\n');
     
}
 
signed main(){
    //freopen("108300.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        A = a;B=b;C=c;
        solve();
    }
 
    /*for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                a=i;b=j;c=k;
                A=a;B=b;C=c;
                if(i == 100)A = a = 1073741824;
                if(j == 100)B = b = 1073741824;
                if(k == 100)C = c = 1073741824;
                if(i == 99)A = a = 2147483647;
                if(j == 99)B = b = 2147483647;
                if(k == 99)C = c = 2147483647;
                if(i == 98)A = a = 65535;
                if(j == 98)B = b = 65535;
                if(k == 98)C = c = 65535;
                 
                solve();
            }
        }
    }*/
     
}
