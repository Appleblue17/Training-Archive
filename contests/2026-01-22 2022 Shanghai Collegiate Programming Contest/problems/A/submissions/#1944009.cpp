#include <bits/stdc++.h>
using namespace std;
const int N=10;

char A[N],B[N];

char S[N],T[N];

int buc1[128],buc2[128],buc3[128];
bool cal(char *a,char *b,char *s){
    memset(buc1,0,sizeof(buc1));
    memset(buc2,0,sizeof(buc2));
    memset(buc3,0,sizeof(buc3));
    for(int i=0;i<8;i++){
        if((a[i]==b[i])!=(s[i]=='G')) return 0;
        if(a[i]==b[i]){
        }
        else{
            buc1[a[i]]++;
            buc2[b[i]]++;
            if(s[i]=='P') buc3[b[i]]++;
        }
    }
    for(int i=0;i<128;i++){
        if(buc3[i]!=min(buc1[i],buc2[i])){
            // cout<<i<<" "<<buc1[i]<<" "<<buc2[i]<<" "<<buc3[i]<<endl;
            return 0;
        }
    }
    return 1;
}

vector <string> ANS;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%s\n%s",A,B);
    
    for(int i=0;i<=99;i++){
        for(int j=0;j+i<=99;j++){
            // if(i!=11 || j!=42) continue;
            int k=i+j;
            S[0]=i/10+'0';
            S[1]=i%10+'0';
            S[2]='+';
            S[3]=j/10+'0';
            S[4]=j%10+'0';
            S[5]='=';
            S[6]=k/10+'0';
            S[7]=k%10+'0';
            
            if(cal(S,A,B)){
                ANS.push_back(string(S));
            }
        }
    }
    cout<<ANS.size()<<endl;
    for(string s: ANS) cout<<s<<endl;
    
}
