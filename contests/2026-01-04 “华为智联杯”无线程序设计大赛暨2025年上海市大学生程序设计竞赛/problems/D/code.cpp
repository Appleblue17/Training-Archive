#include<bits/stdc++.h>
using namespace std;
int T; long long a, b, x, y;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>x>>y;
        if((a&x)==x&&b==y){
            printf("Yes\n");
        }
        else if((b&y)==b&&a==x){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
