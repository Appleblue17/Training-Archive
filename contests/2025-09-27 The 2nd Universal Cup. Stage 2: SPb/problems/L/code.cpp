#include<bits/stdc++.h>
using namespace std;
const int N=55,INF=1e9;

namespace Judge{
    mt19937 rng(time(0));
    int n=25;
    
    char S0[N];
    string S;
    
    bool state;
    int prev;
    int count,step;
    bool vis[N];
    
    void gen(){
        for(int i=0;i<n;i++) S0[i*2]=S0[i*2+1]='A'+i;
        shuffle(S0,S0+n*2,rng);
        S.clear();
        for(int i=0;i<n*2;i++) S+=S0[i];
        // cout<<S<<endl;
    }
    
    void init(){
        state=0;
        count=step=0;
        memset(vis,0,sizeof(vis));
    }
    
    
    string ask(int pos){
        assert(pos>=0 && pos<n*2);
        assert(!vis[pos]);
        char c=S0[pos];
        
        string R; R+=c;
        if(!state){
            prev=pos;
            R+='.';
        }
        else{
            char c=S0[pos];
            
            if(c==S0[prev]){
                count++;
                vis[prev]=vis[pos]=1;
                if(count==n) R+='!';
                else R+='+';
                
            }
            else{
                step++;
                R+='-';
            }
        }
        state^=1;
        
        // cout<<"? "<<pos<<" -> "<<R<<endl;
        return R;
    }
}

namespace Bob{
    mt19937 rng;
    int n=25;

    bool vis[N],suc[N];
    vector <int> V[N];
    
    int p[N],pid;
    int q[N],qid;
    
    string ask(int pos){
        // string R = Judge::ask(pos);
        cout<<pos+1<<endl;
        string R; cin>>R;
        if(R[0]=='#') exit(0);
        return R;
    }
    
    void solve(string S){
        rng.seed(12345);
        
        memset(vis,0,sizeof(vis));
        memset(suc,0,sizeof(suc));
        for(int i=0;i<n;i++) V[i].clear();
        
        while(1){
            pid=qid=0;
            for(int i=0;i<n*2;i++){
                if(!vis[i]){
                    if(S[i]=='0') p[++pid]=i;
                    else q[++qid]=i;
                }
            }
            // cout<<pid<<" "<<qid<<endl;
            if(!pid && !qid) break;
            
            if(pid<qid) swap(p,q),swap(pid,qid);
            int x=p[rng()%pid+1];
            string R1=ask(x);
            int c1=R1[0]-'A';
            V[c1].push_back(x);
            vis[x]=1;
            
            if(V[c1].size()==2){
                int y=V[c1][0];
                ask(y);
                suc[x]=suc[y]=1;
            }
            else{
                int y=q[rng()%qid+1];
                string R2=ask(y);
                int c2=R2[0]-'A';
                V[c2].push_back(y);
                vis[y]=1;
                
                if(c1==c2){
                    suc[x]=suc[y]=1;
                }
            }
        }
        for(int c=0;c<n;c++){
            int x=V[c][0],y=V[c][1];
            if(!suc[x] && !suc[y]){
                ask(x); ask(y);
            }
        }
    }
}



namespace FakeJudge{
    int n=25;
    
    string S;
    
    bool state;
    int prev;
    int count,step;
    bool vis[N];
    
    void init(string S_){
        state=0;
        count=step=0;
        memset(vis,0,sizeof(vis));
        S=S_;
    }
    
    string ask(int pos){
        assert(pos>=0 && pos<n*2);
        assert(!vis[pos]);
        char c=S[pos];
        
        string R; R+=c;
        if(!state){
            prev=pos;
            R+='.';
        }
        else{
            char c=S[pos];
            
            if(c==S[prev]){
                count++;
                vis[prev]=vis[pos]=1;
                if(count==n) R+='!';
                else R+='+';
                
            }
            else{
                step++;
                R+='-';
            }
        }
        state^=1;
        
        // cout<<"? "<<pos<<" -> "<<R<<endl;
        return R;
    }
}

namespace FakeBob{
    mt19937 rng;
    int n=25;

    bool vis[N],suc[N];
    vector <int> V[N];
    
    int p[N],pid;
    int q[N],qid;
    
    string ask(int pos){
        string R = FakeJudge::ask(pos);
        if(R[0]=='#') exit(0);
        return R;
    }
    
    void solve(string S){
        rng.seed(12345);
        
        memset(vis,0,sizeof(vis));
        memset(suc,0,sizeof(suc));
        for(int i=0;i<n;i++) V[i].clear();
        
        while(1){
            pid=qid=0;
            for(int i=0;i<n*2;i++){
                if(!vis[i]){
                    if(S[i]=='0') p[++pid]=i;
                    else q[++qid]=i;
                }
            }
            // cout<<pid<<" "<<qid<<endl;
            if(!pid && !qid) break;
            
            if(pid<qid) swap(p,q),swap(pid,qid);
            int x=p[rng()%pid+1];
            string R1=ask(x);
            int c1=R1[0]-'A';
            V[c1].push_back(x);
            vis[x]=1;
            
            if(V[c1].size()==2){
                int y=V[c1][0];
                ask(y);
                suc[x]=suc[y]=1;
            }
            else{
                int y=q[rng()%qid+1];
                string R2=ask(y);
                int c2=R2[0]-'A';
                V[c2].push_back(y);
                vis[y]=1;
                
                if(c1==c2){
                    suc[x]=suc[y]=1;
                }
            }
        }
        for(int c=0;c<n;c++){
            int x=V[c][0],y=V[c][1];
            if(!suc[x] && !suc[y]){
                ask(x); ask(y);
            }
        }
    }
}

namespace Alice{
    mt19937 rng(12345);
    int n=25;
    vector <int> V[N];
    bool a[N];
    
    string solve(string S){
        for(int i=0;i<n;i++) V[i].clear();
        for(int i=0;i<n*2;i++){
            int c=S[i]-'A';
            V[c].push_back(i);
        }
        
        int mn=INF;
        string mnT;
        for(int t=1;t<=1000;t++){
            string T;
            for(int i=0;i<n;i++){
                int x=V[i][0],y=V[i][1];
                if(rng()%2) swap(x,y);
                a[x]=0,a[y]=1;
            }
            for(int i=0;i<n*2;i++) T+='0'+a[i];
            
            FakeJudge::init(S);
            FakeBob::solve(T);
            
            int cost=FakeJudge::step;
            // cout<<T<<" "<<cost<<endl;
            
            if(cost<mn){
                mn=cost;
                mnT=T;
            }
        }
        return mnT;
    }
}

string msg,S;
int n;
int main(){
    cin>>msg>>n;
    if(msg=="prepare"){
        while(n--){
            cin>>S;
            string T=Alice::solve(S);
            cout<<T<<endl;
        }
    }
    else{
        while(n--){
            cin>>S;
            Bob::solve(S);
        }
    }
}
