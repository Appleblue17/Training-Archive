#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, a[4],u,v,w,cur;

vector<int> ans[2];
void add(int x,int y){
    ans[0].push_back(x);
    ans[1].push_back(y);
}

void solve(){
    ans[0].clear();ans[1].clear();
    scanf("%d%d%d%d",&n,&a[1],&a[2],&a[3]);
    if(n == 2){
        if(a[1] == 1 && a[2] == 0 && a[3] == 0){
            printf("1 2\n1 2\n");
        }
        else{
            printf("-1\n");
        }
        return;
    }
    if(a[1] == 0 && a[2] == 0){
        if(a[3] < 9){
            printf("-1\n");
            return;
        }
        add(4,1);add(6,1);add(1,10);add(3,10);add(10,5);add(10,7);
        add(5,8);add(5,2);add(2,9);
        u = 10;v = 5;w = 2;
        a[3] -= 9;
    }
    else if(a[1] == 0 && a[2] != 0){
        if(a[2] == 1){
            
            if(a[3] < 5){
                printf("-1\n");
                return;
            }
            add(1,3);add(3,6);add(1,5);add(1,7);add(7,4);add(7,2);
            u = 7;v = 1;w = 3;
            a[3] -= 5;
            a[2] -= 1;
            
        }
        else{
            if(a[3] < 2){
                printf("-1\n");
                return;
            }
            add(4,1);add(1,3);add(3,5);add(5,2);
            u = 5;v = 3;w = 1;
            a[3] -= 2;
            a[2] -= 2;
        }
        
    }
    else if(a[1] != 0 && a[2] == 0){
        if(a[1] == 1){
            
            if(a[3] < 4){
                printf("-1\n");
                return;
            }
            add(1,2);add(2,5);add(1,4);add(1,6);add(6,3);
            u = 6;v = 1;w = 2;
            a[3] -= 4;
            a[1] -= 1;
            
        }
        else{
            add(1,2);add(2,3);
            u = 3;v = 2;w = 1;
            a[1] -= 2;
        }
        
    }
    else{
        add(1,2);add(1,3);
        u = 3;v = 1;w = 2;
        a[1]--;a[2]--;
    }
    cur = u;
    while(a[1] > 0){
        cur++;a[1]--;
        add(cur,u);
        w = v;v = u;u = cur;
    }
    while(a[2] > 0){
        cur++;a[2]--;
        add(cur,v);
        u = cur;
    }
    while(a[3] > 0){
        cur++;a[3]--;
        add(cur,w);
        swap(v,w);
        u = cur;
    }
    
    for(int i=0;i<ans[0].size();i++){
        printf("%d %d\n",ans[0][i],ans[1][i]);
    }
    for(int i=1;i<=n;i++)printf("%d ",i);
    printf("\n");
}

signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}