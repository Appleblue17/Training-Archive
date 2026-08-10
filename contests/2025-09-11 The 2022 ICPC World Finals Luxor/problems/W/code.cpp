#include <bits/stdc++.h>
using namespace std;

int fx[6][3]={{},{1,0,0},{0,1,0},{0,0,1},{1,1,2},{2,1,1}};
int f[6];
int x,y,z;

int xx,yy,zz,k;
int qry(int t,int a,int b,int c){
    return a*xx+b*yy+c*zz+(t==k)*1;
}

signed main(){
    // cin>>xx>>yy>>zz>>k;
    
    for(int i=1;i<=5;i++){
        for(int j=0;j<3;j++) cout<<fx[i][j]<<" "; cout<<endl;
        cin>>f[i];
        // f[i]=qry(i,fx[i][0],fx[i][1],fx[i][2]);
        // cout<<f[i]<<endl;
    }
    
    int A=(f[4]==f[1]+f[2]+2*f[3]);
    int B=(f[5]==2*f[1]+f[2]+f[3]);
    int C=(f[4]-2*f[5]==-3*f[1]-f[2]);
    int D=(f[5]-2*f[4]==-f[2]-3*f[3]);
    
    // cout<<"> "<<A<<B<<C<<D<<endl;
    
    if(!A && !B && !C && D){
        y=f[2],z=f[3];
        x=f[4]-y-2*z;
    }
    else if(!A && !B && !C && !D){
        x=f[1],z=f[3];
        y=f[4]-x-2*z;
    }
    else if(!A && !B && C && !D){
        x=f[1],y=f[2];
        z=f[5]-x*2-y;
    }
    else{
        x=f[1],y=f[2],z=f[3];
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
}
