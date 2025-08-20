#pragma GCC Optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
 
 
ll n,m,cnt[N],ans;
ll s0;
 
const double eps=1e-10;
int dcmp(double x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
 
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        double s;
        scanf("%lf",&s);
        //cout << s << endl;
        ans=0;
        s0 = round(s*100);
        bool inf=0;
        ll l=ceil(sqrt(s)),r=floor(sqrt(s *2));
        ll ol=l,outr=r;
        if(l*l*100 == s0){
            if(l == n){
                printf("1\n");
                continue;
            }
            else{
                printf("-1\n");
                continue;
            }
        }
        if(r*r*100 == s0*2){
            //printf("out r overlap\n");
            if(n-r+1 >=0 ){
                ans -= (n-r+1)*(n-r+1);
            }
            
        }
        
        
        for(int i=l;i<=r;i++){
            if(n-i+1 >= 0){
                ans += (n-i+1)*(n-i+1)*2;
            }
            
        }
        l = floor(sqrt(s));
        int be=0;
        if(s*2>n*n)be = floor(sqrt(s*2-n*n));
        for(int i=be;i<=l;i++){
            
            int x = ceil(sqrt(s*2-i*i));
            int x0 = round(sqrt(s*2-i*i));
            
            
            if(dcmp(x0-sqrt(s*2-i*i))==0){
                if((x0&1)^(i&1)){

                }
                else{
                    if(n > x0){
                        inf=1;
                        break;
                    }
                    //printf("grid point,s*2=%Lf,i=%d,x0=%d\n",s*2,i,x0);
                    //if(ol <= x && x <= or)
                    continue;
                }
                //if(n == round(sqrtl(s*2-i*i))){
                //    cnt[n]++;
                //}
                
            }
            
            if((i&1)^(x&1)){
                x++;
            }
            
            //printf("s=%LF,x=%d,i=%d\n",s,x,i);
            if(i==0)cnt[x]++;
            else cnt[x]+=2;
            l = min(l,(ll)x);
            r = max(r,(ll)x);
        }
        for(int i=l;i<=r;i++){
            if(n-i+1 >= 0){
                ans += cnt[i]*(n-i+1)*(n-i+1);
            }
            cnt[i]=0;
        }
        if(inf)printf("-1\n");
        else printf("%lld\n",ans);
    }
}