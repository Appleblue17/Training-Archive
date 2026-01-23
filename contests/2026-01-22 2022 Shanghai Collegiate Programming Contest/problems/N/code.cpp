#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    cin >> a;cin >> b;
    cout << a;
    if(a<b)putchar('<');
    else if(a==b)putchar('=');
    else putchar('>');
    cout << b;
}
