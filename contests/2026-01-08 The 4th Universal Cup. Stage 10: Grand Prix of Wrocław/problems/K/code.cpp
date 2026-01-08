#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
    int n;
    scanf("%d",&n);
    if(n&1){
        printf("NO\n");
        return 0;
    }
    int m = n/2;
    for(int i=1;i<=m;i++){
        ans.push_back(i);
        ans.push_back(i%m+1);
        ans.push_back(i+m);
        ans.push_back((i+1)%m+1+m);
        ans.push_back(i);
        ans.push_back(i+m);
    }
    
    printf("%d\n",m*3);
    for(int i=0;i<ans.size();i+=2){
        printf("%d %d\n",ans[i],ans[i+1]);
    }
    
    
    return 0;
}
