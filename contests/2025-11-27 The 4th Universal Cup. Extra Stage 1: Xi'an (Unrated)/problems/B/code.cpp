#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int T,n,pos[N],pre[N][3],l,r;

char s[N];

int cnt[3],id[3],st,ed;

bool cmp(int i,int j){
    return cnt[i] > cnt[j];
}



bool check(vector<int> S,int st,int ed){
    id[0]=0;id[1]=1;id[2]=2;cnt[0]=S[0];cnt[1]=S[1];cnt[2]=S[2];
    sort(id,id+3,cmp);
    int ist=-1,ied=-1;
    for(int o=0;o<3;o++){
        if(st == id[o])ist = o;
        if(ed == id[o])ied = o;
    }
    
    int C=S[id[0]],P=S[id[1]],W=S[id[2]];
    
    //printf("S = %lld,%lld,%lld,ist=%lld,ied=%lld\n",C,P,W,ist,ied);
    
    if(W==0){
        if(C == P+1){
            if(ist != 0 && ied != 0)return 1;
            else return 0;
        }
        else if(C == P){
            if(ist == 0 && ied == 0)return 0;
            else if(ist == 1 && ied == 1)return 0;
            else return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(C > P+W+1){
            return 0;
        }
        else if(C == P+W+1){
            if(ist != 0 && ied != 0)return 1;
            else return 0;
        }
        else{
            if(C == P+W && ist == 0 && ied == 0)return 0;
            return 1;
        }
    }
}



int lans,rans;

bool C(int len){
    for(int le = max(r-len+1,1ll),ri=le+len-1;ri <= n && le <= l;le++,ri++){
        
        vector<int> S;
        for(int o=0;o<3;o++){
            S.push_back(pre[ri][o]-pre[le-1][o]);
        }
        if(check(S,s[le-1],s[ri+1])){
            lans = le,rans = ri;
            return 1;
        }
    }
    return 0;
}

char ans[N];

void construct(vector<int> S,int st,int ed,int lans,int rans){
    id[0]=0;id[1]=1;id[2]=2;cnt[0]=S[0];cnt[1]=S[1];cnt[2]=S[2];
    int rt[3];
    sort(id,id+3,cmp);
    int ist=-1,ied=-1;
    for(int o=0;o<3;o++){
        if(st == id[o])ist = o;
        if(ed == id[o])ied = o;
    }
    for(int i=0;i<3;i++){
        rt[id[i]] = i;
    }
    
    int C=S[id[0]],P=S[id[1]],W=S[id[2]];
    
    //printf("original S = %lld,%lld,%lld\n",S[0],S[1],S[2]);
    
    //printf("construct, C=%lld,P=%lld,W=%lld,ist=%lld,ied=%lld,id=%lld,%lld,%lld,rt = %lld,%lld,%lld\n",C,P,W,ist,ied,id[0],id[1],id[2],rt[0],rt[1],rt[2]);
    
    if(W==0){
        if(C == P+1){
            for(int i=lans;i<=rans;i++){
                if(i%2 == lans%2){
                    ans[i] = id[0];
                }
                else ans[i] = id[1];
            }
        }
        else if(C == P){
            if(ist == 0 || ied==1){//start with p
                for(int i=lans;i<=rans;i++){
                    if(i%2 == lans%2){
                        ans[i] = id[1];
                    }
                    else ans[i] = id[0];
                }
            }
            else{
                for(int i=lans;i<=rans;i++){
                    if(i%2 == lans%2){
                        ans[i] = id[0];
                    }
                    else ans[i] = id[1];
                }
            }
        }
    }
    else{
        lans++;
        for(int o=0;o<3;o++){
            if(S[o]==0)continue;
            if(o == st)continue;
            S[o]--;
            st = o;
            if(check(S,st,ed)){
                ans[lans-1] = o;
                construct(S,st,ed,lans,rans);
                return;
            }
            S[o]++;
        }
    }
    
}

void solve(){
    
    for(int i=1;i<=n;i++){
        pos[i]=0;
        if(s[i] == 'C')s[i]=0;
        else if(s[i] == 'P')s[i]=1;
        else s[i]=2;
    }
    s[0]=-1;s[n+1]=-1;
    l = n*2;r = -1;
    for(int i=1;i<=n;i++){
        if(s[i] == s[i+1]){
            l = min(l,i+1);
            r = max(r,i);
            pos[i]=1;
        }
        for(int o=0;o<3;o++){
            pre[i][o]=pre[i-1][o] + (int)(s[i]==o);
        }
    
    }
    
    //printf("l=%lld,r=%lld\n",l,r);
    
    if(r == -1){
        printf("Beautiful\n");
        return;
    }
    int L = max(2ll,r-l+1);
    int R = n,M;
    while(L<R){
        M = (L+R)/2;
        if(C(M)){
            R = M;
        }
        else L = M+1;
    }
    if(C(L)){
        printf("Possible\n");
        printf("%lld %lld\n",lans,rans);
        vector<int> S;
        for(int o=0;o<3;o++){
            S.push_back(pre[rans][o]-pre[lans-1][o]);
        }
        for(int i=1;i<=n;i++){
            ans[i] = s[i];
        }
        construct(S,s[lans-1],s[rans+1],lans,rans);
        for(int i=1;i<=n;i++){
            if(ans[i]==0)putchar('C');
            else if(ans[i]==1)putchar('P');
            else putchar('W');
        }putchar('\n');
        /*bool f=0;
        for(int i=1;i<n;i++){
            if(ans[i] == ans[i+1])f=1;
        }
        
        if(f){
            printf("WA. s = ");
            for(int i=1;i<=n;i++){
            if(s[i]==0)putchar('C');
            else if(s[i]==1)putchar('P');
            else putchar('W');
            }
            putchar('\n');
        }*/
    }
    else{
        printf("Impossible\n");
    }
    
    
}
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        scanf("%s",s+1);
        /*n = 20;
        for(int i=1;i<=n;i++){
            int x = rand()%3;
            if(x==0)s[i]='C';
            else if(x==1)s[i]='P';
            else s[i]='W';
        }*/
        solve();
    }
    
}
