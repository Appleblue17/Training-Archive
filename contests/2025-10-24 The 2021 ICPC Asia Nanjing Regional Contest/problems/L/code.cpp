#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n;
char S[N];
bool a[N],aa[N],b[N];

bool cal(){
    for(int f=0;f<=1;f++){
        for(int g=0;g<=1;g++){
            
            for(int i=0;i<n;i++) aa[i]=a[i],b[i]=0;
            if(f) aa[1]^=1,aa[0]^=1,aa[n-1]^=1;
            if(g) aa[0]^=1,aa[n-1]^=1,aa[n-2]^=1;
            
            b[n-1]=g; b[0]=f;
            
            for(int i=0;i<n-2;i++){
                if(!aa[i]){
                    b[i+1]=1;
                    aa[i]^=1,aa[i+1]^=1,aa[i+2]^=1;
                }
            }
            if(aa[n-1] && aa[n-2]) return 1;
        }
    }
    return 0;
}

queue <int> P,Q,R;
vector <int> ANS;

inline int NXT(int x){
    return (x+1)%n;
}
inline int LST(int x){
    return (x+n-1)%n;
}
void upd(int pos){
    int nxt=NXT(pos);
    int lst=LST(pos);
    if(b[pos] && !a[pos]) P.push(pos);
    if(b[pos] && a[pos] && !a[nxt]) Q.push(pos);
    if(b[pos] && a[pos] && !a[lst]) R.push(pos);
}

void oper(int pos){
    assert(!a[pos]);
    
    int nxt=NXT(pos);
    int lst=LST(pos);
    a[pos]^=1,a[lst]^=1,a[nxt]^=1;
    b[pos]^=1;
    upd(pos),upd(lst),upd(nxt);
    upd(LST(lst)); upd(NXT(nxt));
    ANS.push_back(pos);
}

void solve(){
    if(!cal()){
        printf("0\n");
        return ;
    }
    ANS.clear();
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<b[i]<<" ";
    // cout<<endl;
    
    for(int i=0;i<n;i++) upd(i);
    
    while(1){
        if(!P.empty()){
            int pos=P.front(); P.pop();
            if(!(b[pos] && !a[pos])) continue;
            oper(pos);
        }
        else if(!Q.empty()){
            int pos=Q.front(); Q.pop();
            int nxt=NXT(pos),lst=LST(pos);
            if(!(b[pos] && a[pos] && !a[nxt])) continue;
            oper(nxt); oper(pos); oper(lst); oper(nxt);
        }
        else if(!R.empty()){
            int pos=R.front(); R.pop();
            int nxt=NXT(pos),lst=LST(pos);
            if(!(b[pos] && a[pos] && !a[lst])) continue;
            oper(lst); oper(pos); oper(nxt); oper(lst);
        }
        else break;
    }
    // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
    // for(int i=0;i<n;i++) cout<<b[i]<<" "; cout<<endl;
    
    for(int i=0;i<n;i++) assert(a[i]);
    
    int siz=ANS.size();
    assert(siz<=2*n);
    printf("%d\n",siz);
    for(int i=0;i<siz;i++){
        printf("%d",ANS[i]+1);
        if(i+1<siz) printf(" ");
    }
    printf("\n");
}


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("\n%s",S);
        for(int i=0;i<n;i++) a[i]=S[i]-'0';
        
        solve();
        
    }
    
    
}
