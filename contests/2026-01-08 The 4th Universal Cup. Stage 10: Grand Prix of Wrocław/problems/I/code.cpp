#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
char S[N];
int a[N];
vector <int> A,B;

mt19937 rng(time(NULL));

int main(){
    // freopen("I.out","w",stdout);
    scanf("%d",&n);
    scanf("\n%s",S);
    // for(int i=0;i<n;i++) S[i]=rng()%2+'0';
    for(int i=0;i<n;i++) a[i]=S[i]-'0';
    a[n]=-1;
    
    int i=0;
    while(1){
        int x=a[i];
        if(i+1<n && a[i+1]==x){
            A.push_back(i);
            B.push_back(i+1);
            i+=2;
        }
        else if(i+2<n && a[i+2]==1-x){
            A.push_back(i+1);
            B.push_back(i+2);
            i+=3;
        }
        else if(i+3<n && a[i+3]==x){
            A.push_back(i);
            B.push_back(i+2);
            i+=3;
        }
        else if(i+3<n){
            A.push_back(i);
            A.push_back(i+1);
            B.push_back(i+2);
            B.push_back(i+3);
            i+=4;
        }
        else break;
    }
    // cout<<1.0*A.size()*2/n;
    printf("%d\n",A.size());
    for(int x: A) printf("%d ",x); printf("\n");
    for(int x: B) printf("%d ",x); printf("\n");
}
