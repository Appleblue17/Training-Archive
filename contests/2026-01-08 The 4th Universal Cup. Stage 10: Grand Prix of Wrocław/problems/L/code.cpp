#include<bits/stdc++.h>
using namespace std;
int main(){
    string s[3];
    getline(cin,s[0]);
    getline(cin,s[1]);
    getline(cin,s[2]);
    for(int i=0;i<=2;i++){
        if(s[i]=="cerc"){
            printf("YES\n1\n%d\n",i+1);
            return 0;
        }
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i==j)continue;
            if(s[i]+s[j] == "cerc"){
                printf("YES\n2\n%d %d\n",i+1,j+1);
                return 0;
            }
        }
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i==j)continue;
            for(int k=0;k<=2;k++){
                if(k == i ||k == j)continue;
                if(s[i]+s[j]+s[k] == "cerc"){
                    printf("YES\n3\n%d %d %d\n",i+1,j+1,k+1);
                    return 0;
                }
            }
            
        }
    }
    printf("NO\n");
    return 0;
}
