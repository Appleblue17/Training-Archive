#include <bits/stdc++.h>
using namespace std;
int T,a[110];
vector<int> ans;
signed main(){
    scanf("%d",&T);
    while(T--){
        ans.clear();
        int n=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        //cout << '*' << endl;
        for(int i=1;i<=n;i++){
            //cout << 'i' << i << ' ' << a[i] << endl;
            if(a[i] != i){
                int j=1;
                for(j=n;j>=i;j--){
                    if(a[j] == a[i]-1 || a[j]==i)break;
                }
                ans.push_back(i);ans.push_back(j);
                //printf("sort %d %d\n",i,j);fflush(stdout);
                sort(a+i,a+j+1);
            }
        }
        //cout << ans.size() << endl;
        printf("%d\n",ans.size()/2);
        for(int i=0;i<ans.size();i+=2){
            printf("%d %d\n",ans[i],ans[i+1]);
        }
    }
    
}
