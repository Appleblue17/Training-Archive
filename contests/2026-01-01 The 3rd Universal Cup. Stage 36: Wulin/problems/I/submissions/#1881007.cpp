#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m;
vector<int> a,b;

bool f=0;

int read(){
    int ret=0;
    char c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = ret*10+c-'0';
        c = getchar();
    }
    if(c != '.')f=1;
    return ret;
}

int main(){
    cin>>T;
    while(T--){
        a.clear();b.clear();
        f=0;
        while(!f){
            int x = read();
            //printf("x = %d\n",x);
            a.push_back(x);
        }
        f=0;
        while(!f){
            b.push_back(read());
        }
        f=0;
        bool fl=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<b[i]){
                printf("B\n");
                fl=1;
                break;
            }
            if(a[i] > b[i]){
                printf("A\n");
                fl=1;
                break;
            }
        }
        if(!fl){
            printf("Equal\n");
        }
    }
    
    
}
