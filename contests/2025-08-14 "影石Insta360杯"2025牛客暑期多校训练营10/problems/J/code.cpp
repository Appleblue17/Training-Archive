#include<bits/stdc++.h>
using namespace std;
double A,B;
int n;
vector<double> ans[3];
void aa(double a,double b,double c){
    ans[0].push_back(a);ans[1].push_back(b);ans[2].push_back(c);
}
void prin(){
    ans[0].push_back(ans[0][0]);ans[0].push_back(ans[0][1]);
    ans[1].push_back(ans[1][0]);ans[1].push_back(ans[1][1]);
    ans[2].push_back(ans[2][0]);ans[2].push_back(ans[2][1]);
    for(int i=0;i<n;i++){
        if(round(ans[0][i])==ans[0][i])printf("%d ",(int)round(ans[0][i]));
        else printf("%.8lf ",ans[0][i]);
        if(round(ans[1][i])==ans[1][i])printf("%d ",(int)round(ans[1][i]));
        else printf("%.8lf ",ans[1][i]);
        if(round(ans[2][i])==ans[2][i])printf("%d\n",(int)round(ans[2][i]));
        else printf("%.8lf\n",ans[2][i]);
    }
    double x[2][3];
    for(int i=0;i<n;i++){
        double dis=0;
        for(int o=0;o<=2;o++){
            x[0][o]=ans[o][i+1]-ans[o][i];
            dis += x[0][o]*x[0][o];
        }
        if(fabs(dis-1) > 1e-6){
            printf("WA dis!=1,dis=%.10lf,i=%d\n",dis,i);
        }
        double dot=0;
        for(int o=0;o<=2;o++){
            x[1][o]=ans[o][i+2]-ans[o][i+1];
            dot += x[1][o]*x[0][o];
        }
        if(fabs(dot) > 1e-6){
            printf("WA dot!=0,dot=%.10lf,i=%d\n",dot,i);
        }
    }
}
void solve(){
    ans[0].clear();ans[1].clear();ans[2].clear();
    double A=(sqrt(2)-1)/2;
    double B = sqrt(1-pow(A,2));
    //printf("%.10lf\n",A);
    scanf("%d",&n);
    if(n<4 || n==5){
        printf("-1\n");
        return;
    }
    if(n==4){
        aa(0,0,0);
        aa(1,0,0);
        aa(1,1,0);
        aa(0,1,0);
        prin();
        printf("1\n");
        return;
    }
    if(n==6){
        aa(0,0,0);
        aa(1,0,0);
        aa(1,0,1);
        aa(1,1,1);
        aa(1,1,0);
        aa(0,1,0);
        prin();
        printf("inf\n");
        return;
    }
    if(n==7){
        aa(0,0,0);
        aa(1,0,0);
        aa(1,1,0);
        aa(1-0.01401942,1,-0.99990172);
        aa(1-0.01401942+0.34999576,1-0.93673843,-0.99990172-0.00490722);
        aa(1-0.01401942+0.34999576-0.89096948,1-0.93673843-0.33126820,-0.99990172-0.00490722-0.31053948);
        aa(0.00000037,0.50496113,-0.86314208);
        prin();
        printf("inf\n");
        //printf("-1\n");
        return;
    }
    if(n%2==0){
        if(n%4==0){
            for(int i=1;i<=n;i+=4){
                aa(0,0,0);
                aa(1,0,0);
                aa(1,1,0);
                aa(0,1,0);
            }
            prin();
            printf("inf\n");
        }
        else{
            aa(0,0,0);
            aa(1,0,0);
            aa(1,0,1);
            aa(1,1,1);
            for(int i=7;i<=n;i+=4){
                aa(1,1,0);
                aa(1,0,0);
                aa(1,0,1);
                aa(1,1,1);
            }
            aa(1,1,0);
            aa(0,1,0);
            prin();
            printf("inf\n");
        }
    }
    else{
        if(n%4==3)aa(0,0,1);
        aa(0,0,0);
        aa(0,1,0);
        double t = sqrt(2)/2.0;
        aa(-A,1,B);
        aa(-A,2,B);
        aa(-A+t,2,B+t);
        for(int i=13;i<=n;i+=4){
            aa(1+A,2,B);
            aa(-A+t,2,B-t);
            aa(-A,2,B);
            aa(-A+t,2,B+t);
        }
        aa(1+A,2,B);
        aa(1+A,1,B);
        aa(1,1,0);
        aa(1,0,0);
        if(n%4==3)aa(1,0,1);
        prin();
        printf("inf\n");
    }
}
signed main(){
    int T;scanf("%d",&T);while(T--)solve();
}
