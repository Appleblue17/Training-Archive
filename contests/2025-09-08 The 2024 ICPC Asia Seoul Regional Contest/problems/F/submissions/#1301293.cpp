#include <bits/stdc++.h>
using namespace std;
const int N=120;

int a[N][2],n;
vector<int> ans;
void addans(int i,int idi,int idi1){
    ans.push_back(i);ans.push_back(a[i][idi]);ans.push_back(a[i+1][idi1]);
    swap(a[i][idi],a[i+1][idi1]);
}

void prin(){
    for(int i=1;i<=n;i++){
        printf("%d ",a[i][0]);
    }
    putchar('\n');
    for(int i=1;i<=n;i++){
        printf("%d ",a[i][1]);
    }
    putchar('\n');
    fflush(stdout);
}
// mt19937 rng(923499);

void solve(){
    ans.clear();
    //cout << 0.7*90*90;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i][0]=a[i][1]=n-i+1;
    }
    //prin();
    for(int i=n;i>=1;i--){
        for(int o=0;o<=1;o++){
        for(int j=1;j<=i-1;j++){
            int idj = 0;
            if(a[j][0] == i || a[j][1] == i){
                if(a[j][0] == i)idj = 0;
                else idj = 1;
                if(a[j+1][0] < a[j+1][1]){
                    addans(j,idj,0);
                }
                else addans(j,idj,1);
            }
        }
        //prin();
        }
    }
    //prin();
    bool f=0;
    for(int i=1;i<=n;i++){
        if(a[i][0] != i)f=1;
        if(a[i][1] != i)f=1;
    }
    //cout << f << endl;
    cout << ans.size()/3 << endl;
    if(ans.size()/3 >= 0.7*n*n){
        printf("exceeded at n=%d\n",n);
    }
    if(f){
        printf("wrong answer\n");
    }
    for(int i=0;i<ans.size();i+=3){
        printf("%d %d %d\n",ans[i],ans[i+1],ans[i+2]);
    }
    
}

int main(){
    solve();
    //for(n=1;n<=100;n++){
    //    solve();
    //}
}



