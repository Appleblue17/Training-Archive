#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n; ll m;
int a[N], b[N];
int pos[N];
int res[N];
int main() {
    scanf("%d%lld", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    for(int i=1; i<=n; ++i){
        a[i]=pos[i];
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &b[i]);
    }
    printf("Yes\n");
    for(int i=1; i<=n; ++i){
        printf("%d ", a[i]-1);
    }
    putchar('\n');
    for(int i=1; i<=n; ++i){
        int id=b[i];
        if(m==0){
            res[id]=n;
            continue;
        }
        if(m>=id-1){
            m-=id-1;
            res[id]=-n;
            continue;
        }
        sort(a+1, a+id);
        res[id]=-(a[m+1]-1);
        m=0;
    }
    for(int i=1; i<=n; ++i){
        printf("%d ", res[i]);
    }
}
