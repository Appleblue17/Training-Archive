#include<bits/stdc++.h>
using namespace std;
const int N=3300;
int n;
int main(){
    vector<int> vec;
    vec.push_back(50);
    vec.push_back(25);
    for(int i=1; i<=20; ++i){
        vec.push_back(i);
        vec.push_back(i*2);
        vec.push_back(i*3);
    }
    cin>>n;
    for(auto a:vec){
        if(a%2==0&&(a<=40||a==50)&&a==n){
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<a<<endl;
            return 0;
        }
        for(auto b:vec){
            if(b%2==0&&(b<=40||b==50)&&a+b==n){
                cout<<"YES"<<endl;
                cout<<2<<endl;
                cout<<a<<' '<<b<<endl;
                return 0;
            }
            for(auto c:vec){
                if(c%2==0&&(c<=40||c==50)&&a+b+c==n){
                    cout<<"YES"<<endl;
                    cout<<3<<endl;
                    cout<<a<<' '<<b<<' '<<c<<endl;
                    return 0;
                }
                
            }
        }
    }
    
    cout<<"NO\n";
}
