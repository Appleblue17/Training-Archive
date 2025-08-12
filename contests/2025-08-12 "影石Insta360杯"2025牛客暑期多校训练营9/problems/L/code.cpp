#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n, k;
int a[N], b[N];
int sum[N], add[N];
void solve(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), sum[i]=0, b[i]=a[i];
    sort(b+1, b+n+1);
    for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1, b+n+1, a[i])-b;
    queue<int> que;
    int cur=1, cnt=0;
    for(int i=2; i<=n; ++i) que.push(i);
    int tim=0;
    if(tim<k){
        do{
            ++tim;
            sum[cur]++; sum[que.front()]++;
            if(a[que.front()]>a[cur]) {
                que.push(cur);
                cur=que.front(), que.pop(), cnt=1;
            }
            else {
                ++cnt;
                if(cnt!=n){
                    que.push(que.front()), que.pop();
                }
                else{
                    que.push(cur);
                    cur=que.front(), que.pop(), cnt=1;
                }
            }
        }while(tim<k&&(a[cur]!=n||a[que.front()]!=n-1));
    }
    if(tim<k){
        do{
            ++tim;
            sum[cur]++; sum[que.front()]++;
            if(a[que.front()]>a[cur]) {
                que.push(cur);
                cur=que.front(), que.pop(), cnt=1;
            }
            else {
                ++cnt;
                if(cnt!=n){
                    que.push(que.front()), que.pop();
                }
                else{
                    que.push(cur);
                    cur=que.front(), que.pop(), cnt=1;
                }
            }
        }while(tim<k&&(a[cur]!=n||a[que.front()]!=n-1));
    }
    int cir=0;
    if(tim<k){
        do{
            ++tim; ++cir;
            sum[cur]++; sum[que.front()]++;
            if(a[que.front()]>a[cur]) {
                que.push(cur);
                cur=que.front(), que.pop(), cnt=1;
            }
            else {
                ++cnt;
                if(cnt!=n){
                    que.push(que.front()), que.pop();
                }
                else{
                    que.push(cur);
                    cur=que.front(), que.pop(), cnt=1;
                }
            }
        }while(tim<k&&(a[cur]!=n||a[que.front()]!=n-1));
    }
    if(tim==k){
        for(int i=1; i<=n; ++i) printf("%d ", sum[i]);
        putchar('\n');
        return ;
    }
    int mul=(k-tim)/cir;
    k=(k-tim)%cir;
    if(mul!=0){
        do{
            sum[cur]+=mul; sum[que.front()]+=mul;
            if(a[que.front()]>a[cur]) {
                que.push(cur);
                cur=que.front(), que.pop(), cnt=1;
            }
            else {
                ++cnt;
                if(cnt!=n){
                    que.push(que.front()), que.pop();
                }
                else{
                    que.push(cur);
                    cur=que.front(), que.pop(), cnt=1;
                }
            }
        }while(a[cur]!=n||a[que.front()]!=n-1);
    }
     
    tim=0;
    if(tim<k){
        do{
            ++tim; 
            sum[cur]++; sum[que.front()]++;
            if(a[que.front()]>a[cur]) {
                que.push(cur);
                cur=que.front(), que.pop(), cnt=1;
            }
            else {
                ++cnt;
                if(cnt!=n){
                    que.push(que.front()), que.pop();
                }
                else{
                    que.push(cur);
                    cur=que.front(), que.pop(), cnt=1;
                }
            }
        }while(tim<k&&(a[cur]!=n||a[que.front()]!=n-1));
    }
    for(int i=1; i<=n; ++i) printf("%d ", sum[i]);
    putchar('\n');
}
signed main() {
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
