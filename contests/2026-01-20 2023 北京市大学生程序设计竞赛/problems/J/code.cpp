#include<bits/stdc++.h>
using namespace std;
const int N=550,INF=1e9;
int n;
int a[N][N],dis[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            dis[i][j]=a[i][j];
        }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                putchar('0');
                continue;
            }
            int mn=INF;
            for(int k=1;k<=n;k++){
                if(k==i || k==j) continue;
                mn=min(mn,dis[i][k]+dis[k][j]);
            }
            putchar((mn>a[i][j])+'0');
        }
        putchar('\n');
    }
                
}
