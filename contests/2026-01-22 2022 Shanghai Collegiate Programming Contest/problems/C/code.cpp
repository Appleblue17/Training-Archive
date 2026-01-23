#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve1(int s,int c){
    int st = ((s-1)/(c+1)+1)*c,ans=0,ed=0;
    if(st > s){
        int st2 = st-c;
        st=s;
        ed = st%(c+1);
        ans = max(ans,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
        //printf("solve1 examine st=%lld,ed=%lld,get%lld\n",st,ed,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
        st = st2;
        ed = st%(c+1);
        ans = max(ans,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
        //printf("solve1 examine st=%lld,ed=%lld,get%lld\n",st,ed,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
    }
    else{
        ed = st%(c+1);
        ans = max(ans,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
        //printf("solve1 examine st=%lld,ed=%lld,get%lld\n",st,ed,(st+ed)*((st-ed)/(c+1)+1)/2*c+(s+st+1)*(s-st)/2);
    }
    return ans;
}

int solve2(int s,int c){
    int top = (c*c-c-2)/2+c+1,ans=0;
    top = min(top,s);
    for(int x=1;x<=c;x++){
        int t = (top-x)/(c+1)*(c+1)+x;
        //printf("x=%lld,t=%lld %lld\n",x,t,(x+t)*((t-x)/(c+1)+1)/2*c+(s+t+1)*(s-t)/2);
        ans = max(ans,(x+t)*((t-x)/(c+1)+1)/2*c+(s+t+1)*(s-t)/2);
    }
    return ans;
}

mt19937 rng(0);

signed main(){
    int t;cin >> t;while(t--){
        int s,c,ans1,ans2;
        scanf("%lld%lld",&s,&c);
        //s=rng()%100000;c=rng()%2000;
        //if(s<c)swap(s,c);
        if((c*c-c-2)/2+c+1>s){
            ans1 = solve1(s,c);
            //ans2 = solve2(s,c);
            //printf("remenber to delete\n");
            //if(ans1 != ans2){
            //    printf("s=%lld,c=%lld,ans1=%lld,ans2=%lld\n",s,c,ans1,ans2);
            //}
            printf("%lld\n",ans1);
        }
        else{
            ans2 = solve2(s,c);
            printf("%lld\n",ans2);
        }
        
    }
}
