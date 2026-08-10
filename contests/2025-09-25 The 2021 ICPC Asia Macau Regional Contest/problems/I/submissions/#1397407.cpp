#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+50;
int n;
char s[N];
int l[N], r[N];
struct node{
    int len, fa;
    int ch[26];
}empty_node;
node sam[N]; int cnt;
int id[N];
int extend(int c, int lst){
    if(sam[lst].ch[c]){
        int p=lst, q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) return q;
        else{
            int nq=++cnt;
            id[nq]=id[q];
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[q].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
            return nq;
        }
    }
    int p=lst, np=++cnt;
    sam[np].len=sam[p].len+1;
    for(; p&&!sam[p].ch[c]; p=sam[p].fa) sam[p].ch[c]=np;
    if(!p) sam[np].fa=1;
    else{
        int q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) sam[np].fa=q;
        else{
            int nq=++cnt;
            id[nq]=id[q];
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[np].fa=sam[q].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
        }
    }
    return np;
}
int fa[N];
vector<int> bin[N];
int que[N], len;
inline int get(int x){
    if(x==fa[x]) return x;
    return get(fa[x]);
}
bool merge(int x, int y){
    x=get(x); y=get(y);
    if(x==y) return false;
    if(bin[x].size()<bin[y].size()) swap(x, y);
    for(auto t:bin[y]){
        fa[t]=x;
        bin[x].push_back(t);
    }
    bin[y].clear();
    return true;
}
int best[N], bestid[N];
void clr(){
    for(int i=1; i<=cnt; ++i){
        sam[i]=empty_node; id[i]=0; 
    }
    cnt=1;
}
int main(){
    scanf("%d", &n);
    for(int i=1, c; i<=n; ++i){
        l[i]=r[i-1]+1;
        scanf("%s", s+l[i]);
        c=strlen(s+l[i]);
        r[i]=l[i]+c-1;
        fa[i]=i; bin[i].push_back(i);
    }
    int tot=n;
    long long ans=0;
    while(tot>1){
        len=0;
        for(int i=1; i<=n; ++i) if(i==get(i)){
            que[++len]=i;
            best[i]=-1; bestid[i]=0;
        }
        clr();
        for(int i=1, rt; i<=len; ++i){
            rt=que[i];
            for(auto x:bin[rt]){
                int p=1, len=0;
                for(int j=l[x]; j<=r[x]; ++j){
                    while(p&&(sam[p].ch[s[j]-'a']==0)) p=sam[p].fa, len=sam[p].len;
                    if(p==0){
                        p=1; len=0;
                    }
                    else{
                        ++len; p=sam[p].ch[s[j]-'a'];
                    }
                    if(len>best[rt]){
                        best[rt]=len;
                        bestid[rt]=id[p];
                    }
                    else if(len==best[rt]&&get(id[p])>bestid[rt]){
                        bestid[rt]=id[p];
                    }
                }
            }
            for(auto x:bin[rt]){
                int lst=1;
                for(int j=l[x]; j<=r[x]; ++j){
                    lst=extend(s[j]-'a', lst), id[lst]=rt;
                }
            }
        }
        clr();
        for(int i=len, rt; i>=1; --i){
            rt=que[i];
            for(auto x:bin[rt]){
                int p=1, len=0;
                for(int j=l[x]; j<=r[x]; ++j){
                    while(p&&(sam[p].ch[s[j]-'a']==0)) p=sam[p].fa, len=sam[p].len;
                    if(p==0){
                        p=1; len=0;
                    }
                    else{
                        ++len; p=sam[p].ch[s[j]-'a'];
                    }
                    if(len>best[rt]){
                        best[rt]=len;
                        bestid[rt]=id[p];
                    }
                    else if(len==best[rt]&&get(id[p])>bestid[rt]){
                        bestid[rt]=id[p];
                    }
                }
            }
            for(auto x:bin[rt]){
                int lst=1;
                for(int j=l[x]; j<=r[x]; ++j){
                    lst=extend(s[j]-'a', lst), id[lst]=rt;
                }
            }
        }
        // for(int i=1; i<=len; ++i){
        //     cout<<que[i]<<' '<<best[que[i]]<<' '<<bestid[que[i]]<<endl;
        // }
        sort(que+1, que+len+1, [&](int x, int y){return best[x]>best[y];});
        for(int i=1; i<=len; ++i){
            if(merge(que[i], bestid[que[i]])){
                ans+=best[que[i]];
                --tot;
            }
        }
        // cout<<"---------------------"<<endl;
    }
    printf("%lld\n", ans);
}

