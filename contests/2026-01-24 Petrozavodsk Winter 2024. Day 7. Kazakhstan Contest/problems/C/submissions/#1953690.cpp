#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int n,k,d;
vector<int> a,b,c;

int hs(vector<int> a){
    sort(a.begin(),a.end());
    int ret=0;
    for(int i=0;i<=5;i++){
        ret = ret*10007+a[i];
        ret %= 6;
    }
    return ret;
}

signed main(){
    /*double ans=0;
    for(int i=1;i<=120;i++){
        ans += log(i);
    }
    cout << ans << endl;*/
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;a.push_back(x);
    }
    if(n == 6){
        sort(a.begin(),a.end());
        int x = hs(a);
        //cout << x << endl;
        int ans=0;
        for(int i=0;i<6;i++){
            if(x==i){
                ans = a[i];
                continue;
            }
            b.push_back(a[i]);
        }
        vector<int> tb;
        for(int i=1;i<=245;i++){
            bool f=0;
            int sm=0;
            for(int v:b){
                if(v == i){
                    f=1;
                    break;
                }
                if(v<i)sm++;
            }
            if(f)continue;
            b.push_back(i);
            int x = hs(b);
            b.pop_back();
            if(x == sm){
                tb.push_back(i);
                //printf("tb add %lld\n",i);
            }
        }
        int kx=0;
        for(int i=0;i<tb.size();i++){
            if(tb[i] == ans){
                kx = i;
                break;
            }
        }
        
        //int p[5] = {1,2,3,4,5};
        //printf("kx = %lld\n",kx);
        sort(b.begin(),b.end());
        for(int i=1;i<=kx;i++){
            next_permutation(b.begin(),b.end());
        }
        
        for(int v:b){
            cout << v << ' ';
        }
        
    }
    else{
        b = a;
        vector<int> tb;
        for(int i=1;i<=245;i++){
            bool f=0;
            int sm=0;
            for(int v:b){
                if(v == i){
                    f=1;
                    break;
                }
                if(v<i)sm++;
            }
            if(f)continue;
            b.push_back(i);
            int x = hs(b);
            b.pop_back();
            if(x == sm){
                tb.push_back(i);
            }
        }
        sort(b.begin(),b.end());
        int kx=0;
        for(int i=1;i<=120;i++){
            bool f=0;
            for(int j=0;j<5;j++){
                if(a[j] != b[j])f=1;
            }
            if(!f){
                kx = i;
                break;
            }
            next_permutation(b.begin(),b.end());
        }
        kx--;
        //printf("kx = %lld\n",kx);
        cout << tb[kx] << endl;
    }
}
