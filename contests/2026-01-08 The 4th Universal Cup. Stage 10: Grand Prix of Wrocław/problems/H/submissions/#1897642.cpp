#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
int a[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        unordered_map<int, int> h;
        int mn=1e9;
        for(int i=1, x; i<=n; ++i){
            scanf("%d", &x);
            h[x]++;
            mn=min(mn, x);
        }
        set<int> st;
        for(auto t:h) st.insert(t.first);
        st.erase(mn);
        int mx=mn*2;
        if(h.find(mx)!=h.end()) st.erase(mx);
        int rp=n;
        deque<int> que;
        while(!st.empty()){
            vector<int> bin;
            for(auto t:st){
                bin.push_back(t);
                h[t]--;
            }
            for(auto t:bin) if(h[t]==0) st.erase(t);
            
            if(h[mn]!=0){
                h[mn]--; que.push_back(mn);
            }
            else if(h[mx]!=0){
                h[mx]--; que.push_back(mx);
            }
            for(auto t:bin){
                que.push_back(t);
            }
        }
        while(h[mn]!=0) --h[mn], que.push_front(mn);
        while(h[mx]!=0) --h[mx], que.push_back(mx);
        for(int i=1; i<=n; ++i) a[i]=que.front(), que.pop_front();
        int num=0;
        for(int i=1; i<n; ++i) num+=a[i]/a[i+1];
        printf("%d\n", num);
        for(int i=1; i<=n; ++i) printf("%d ", a[i]);
        putchar('\n');
    }
}
