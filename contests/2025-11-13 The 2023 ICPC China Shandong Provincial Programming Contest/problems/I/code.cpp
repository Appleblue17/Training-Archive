#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b=0,A,B;
    scanf("%d%d",&A,&B);
    for(int i=1;i<=6;i++){
        if(i == 1 || i == 4)a+=i;
        else b += i;
        for(int j=1;j<=6;j++){
            if(j==1||j==4)a+=j;
            else b+=j;
            for(int k=1;k<=6;k++){
                if(k==1||k==4)a+=k;
                else b+=k;
                if(a==A && b==B){
                    printf("Yes\n");
                    return 0;
                }
                if(k==1||k==4)a-=k;
                else b-=k;
            }
            if(j==1||j==4)a-=j;
            else b-=j;
        }
        if(i == 1 || i == 4)a-=i;
        else b -= i;
    }
    printf("No\n");
}
