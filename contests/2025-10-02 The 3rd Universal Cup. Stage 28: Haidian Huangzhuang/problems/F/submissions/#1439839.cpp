#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=330;
int n,ans;
char S[N];
int a[N][N],b[N][N],s[N][N];

mt19937_64 rng(123);
ull bas[N];
ull has[N][N];


int row_cnt[N],row_cur[N],is_valid[N];
int col_lim1[N],col_lim2[N];

unordered_map <ull,int> mp;
ull f[N];


vector <int> V[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) bas[i]=rng();
    for(int i=1;i<=n;i++){
        scanf("\n%s",S+1);
        for(int j=1;j<=n;j++) a[i][j]=S[j]-'0';
    }
    
    for(int L=1;L<=n;L++){
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        memset(has,0,sizeof(has));
        for(int i=1;i<=n;i++){
            for(int j=L;j<=n;j++){
                b[i][j]=b[i][j-1]^a[i][j];
                s[i][j]=s[i-1][j]^b[i][j];
                has[i][j]=has[i][j-1]+(ull)s[i][j]*bas[j];
            }
        }
        
        for(int i=1;i<=n;i++){
            row_cnt[i]=row_cur[i]=0;
            is_valid[i]=1;
            col_lim1[i]=col_lim2[i]=0;
        }
        
        for(int R=L;R<=n;R++){
            // cout<<L<<" "<<R<<": "<<endl;
            for(int i=1;i<=n;i++){
                V[i].clear();
            }
            
            int cur=0,lim=0;
            for(int i=1;i<=n;i++){
                if(a[i][R]){
                    row_cnt[i]++;
                    row_cur[i]++;
                }
                else{
                    if(row_cur[i] & 1) is_valid[i]=0;
                    row_cur[i]=0;
                }
                if(!is_valid[i] || (row_cnt[i] & 1)) lim=i;
                
                if(b[i][R]){
                    cur++;
                    if(cur & 1) col_lim1[i]=max(col_lim1[i],i-cur);
                }
                else{
                    if(cur & 1) col_lim2[i]=max(col_lim2[i],i-cur);
                    cur=0;
                }
                
                lim=max(lim,col_lim2[i]);
                int pos=max(lim,col_lim1[i]);
                V[pos].push_back(i);
                // cout<<i<<" -> "<<pos<<endl;
            }
            
            for(int i=1;i<=n;i++) f[i]=has[i][R];
            // for(int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
            
            mp.clear(); mp[0]++;
            int nw=0,tot=0;
            for(int i=1;i<=n;i++){
                for(int pos: V[i]){
                    tot-=mp[f[pos]];
                }
                tot+=mp[f[i]];
                mp[f[i]]++;
            }
            
            // cout<<L<<" "<<R<<" "<<tot<<endl;
            ans+=tot;
        }
    }
    cout<<ans;
}
