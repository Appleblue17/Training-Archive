#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin >> T;while(T--){
        int a,b,A,B;
        cin >> a >> b >> A >> B;
        int k = B/a-3;
        while(k*a < B)k++;
        k--;
        //cout << k << endl;
        A -= k*b;B -= k*a;
        if(A - 4*b <= 0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}