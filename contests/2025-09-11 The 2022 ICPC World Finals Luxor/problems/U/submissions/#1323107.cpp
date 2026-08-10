#include <bits/stdc++.h>
using namespace std;
int s,c;

signed main(){
    scanf("%d%d",&s,&c);
    s=(s/2)*2; c=(c/2)*2;
    if(s==0){
        c=(c/4)*4;
        if(c==8) c=4;
        if(c%8==4){
            c-=4;
            printf("RR");
            for(int i=1; i<=c/8; ++i) printf("LRRL");
            printf("RR");
            for(int i=1; i<=c/8; ++i) printf("LRRL");
            return 0;
        }
        if(c%8==0){
            c-=16;
            printf("RR");
            for(int i=1; i<=c/8; ++i) printf("LRRL");
            printf("LRLRRLRRLRLRRL");
            for(int i=1; i<=c/8; ++i) printf("LRRL");
            return 0;
        }
        return 0;
    }
    if(c%8==4){
        printf("SRRS");
        s-=2;
        c-=4;
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        printf("RR");
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        return 0;
    }
    if(c%8==0){
        printf("RR");
        s-=2;
        c-=8;
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        printf("LRRSSRRL");
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        return 0;
    }
    if(c%8==6){
        printf("RR");
        s-=2;
        c-=6;
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        printf("LRRSRS");
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        return 0;
    }
    if(c%8==2){
        printf("RSR");
        s-=2;
        c-=10;
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        printf("LRRLRRLRS");
        for(int i=1; i<=s/2; ++i) printf("S");
        for(int i=1; i<=c/8; ++i) printf("LRRL");
        return 0;
    }
    return 0;
}
