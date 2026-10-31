#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,m,x,y,tarx,tary,pos;

vector<int> a;
bool sw;

void add(int x,int y){
    if(sw)a.push_back(y*100+x);
    else a.push_back(x*100+y);
}

void solve(){
    a.clear();
    scanf("%d%d%d%d",&n,&m,&x,&y);
    sw=0;
    if(n%2==0 && m%2 != 0){
        swap(n,m);
        sw = 1;
    }
    //cout << n << ' ' << m << endl;
    if(m % 2 == 0){
        //cout << '*' << endl;
        for(int j=1;j<=m;j++){
            if(j%2==1){
                for(int i=2;i<=n;i++){
                    add(i,j);
                }
            }
            else{
                for(int i=n;i>=2;i--){
                    add(i,j);
                }
            }
        }
        for(int j=m;j>=1;j--){
            add(1,j);
        }
    }
    else{
        for(int o=0;o<=1;o++){
            for(int i=1;i<=n-2;i++){
                if(i%2==1){
                    for(int j=m-1;j>=1;j--){
                        add(i,j);
                    }
                }
                else{
                    for(int j=1;j<=m-1;j++){
                        add(i,j);
                    }
                }
            }
            add(n-1,1);
            if(o == 0){
                add(n-1,2);
                
            }
            else{
                add(n,1);
            }
            add(n,2);
            for(int j=3;j<=m-1;j++){
                if(j%2==1){
                    add(n,j);
                    add(n-1,j);
                }
                else{
                    add(n-1,j);
                    add(n,j);
                }
            }
            for(int i=n;i>=1;i--){
                add(i,m);
            }
        }
    }
    
    for(int j=0;j<a.size();j++){
        int v = a[j];
        //printf("a contain %d,%d\n",v/100,v%100);
        if(v/100 == x && v%100 == y){
            pos = j;
        }
    }
    //cout << endl;
    
    for(int t=1;t<=n*m-1;t++){
        scanf("%d%d",&tarx,&tary);
        while(x != tarx || y != tary){
            pos++;
            if(pos >= a.size())pos = 0;
            int nx = a[pos]/100,ny = a[pos]%100;
            if(nx > x)printf("D");
            else if(nx < x)printf("U");
            else if(ny > y)printf("R");
            else if(ny < y)printf("L");
            x = nx;y = ny;
        }
        printf("\n");fflush(stdout);
    }
    
}


signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}