#include<bits/stdc++.h>
using namespace std;
const int N=3300;
int T,n;
char S[3][N];
int buc[3][2];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("\n%s\n%s\n%s",S[0],S[1],S[2]);
        
        memset(buc,0,sizeof(buc));
        for(int t=0;t<3;t++){
            for(int i=0;i<n;i++) buc[t][S[t][i]-'0']++;
        }
        cout<<max(min({buc[0][0],buc[1][0],buc[2][0]}),min({buc[0][1],buc[1][1],buc[2][1]}))<<endl;
    }
}
