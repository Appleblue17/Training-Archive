#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char S[N];

struct Bitset {
    int N,LEN;
    unsigned long long MASK;
    
    vector <unsigned long long> as;
    Bitset(int N_) {
        N=N_;
        LEN=(N+64)>>6;
        MASK=(1ull<<(N+64-(LEN<<6)))-1;
        
        // cout<<N<<" "<<LEN<<" "<<MASK<<endl;
        
        as=vector <unsigned long long>(LEN,0ull);
    }
    void print(){
        for(int i=0;i<LEN;i++){
            for(int t=0;t<64;t++) putchar((as[i] >> t & 1ull)+'0');
            putchar(' ');
        }
        putchar('\n');
    }
    void clear(){
        for(int x=0;x<LEN;x++) as[x]=0;
    }
    void set(int i){
        if(i>=N) return ;
        as[i>>6] |= 1ull<<(i & 63);
    }
    void reset(int i){
        if(i>=N) return ;
        as[i>>6] &= ~1ull<<(i & 63);
    }
    bool operator[](int i) const{
        return as[i>>6] >> (i & 63) & 1ull;
    }
    void operator &=(const Bitset &bs){
        for(int x=0;x<LEN;x++) as[x] &= bs.as[x];
        as[LEN-1] &= MASK;
    }
    void operator |=(const Bitset &bs){
        for(int x=0;x<LEN;x++) as[x] |= bs.as[x];
        as[LEN-1] &= MASK;
    }
    int bitc(){
        int tot=0;
        for(int x=0;x<LEN;x++) tot += __builtin_popcountll(as[x]);
        return tot;
    }
    
    void cpy(const Bitset &bs,int L){
        clear();
        int NN=bs.N;
        for(int l=0,r;l<N && l+L<NN;l=r){
            int b=(l>>6),bb=((l+L)>>6);
            int d=(l & 63),dd=((l+L) & 63);
            
            int lim1=min((b+1)<<6,N);
            int lim2=min((bb+1)<<6,L+N)-L;
            r=min(lim1,lim2);
            // r=l+1;
            
            as[b] |= (bs.as[bb] >> dd) << d;
        }
        as[LEN-1] &= MASK;
    }
};

bool f[N];

int main(){
    // freopen("B.out","w",stdout);
    scanf("%d",&n);
    scanf("\n%s",S);
    
    Bitset P(n),Q(n);
    for(int i=0;i<n;i++){
        if(S[i]=='1') P.set(i);
        else if(S[i]=='?') Q.set(i);
    }
    
    // P.print();
    // Q.print();
    
    for(int k=1;k<=n;k++){
        // cout<<k<<": "<<endl;
        int tot=0;
        Bitset F(k),P0(k),Q0(k);
        
        for(int i=0;i<n;i+=k){
            // cout<<"   "<<i<<endl;
            P0.cpy(P,i);
            Q0.cpy(Q,i);
            
            // P0.print();
            // Q0.print();
            // F.print();
            
            F &= Q0;
            F |= P0;
            
            tot+=F.bitc();
        }
        printf("%d\n",tot);
    }
    
    
    
}
