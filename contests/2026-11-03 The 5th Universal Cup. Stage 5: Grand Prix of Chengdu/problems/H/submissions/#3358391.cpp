#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 1000010
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
const int mo=1e9+7;
using namespace std;
vector<int> a,b;
int n;
bool ilessequalj(int i,int j){
	printf("? %d %d\n",i,j);fflush(stdout);
	int ret=0;
	scanf("%d",&ret);
	return ret;
}
void solve(){
	scanf("%lld",&n);
	a.clear();b.clear();
	a.push_back(1);
	int u = 1;
	for(int i=2;i<=n;i++){
		if(ilessequalj(u,i)){//N-1
			a.push_back(i);
			u = i;
		}
		else{
			b.push_back(i);
		}
	}

	if(b.size() == 0){
		printf("! ");
		for(int v:a)printf("%d ",v);
		printf("\n");fflush(stdout);
		return;
	}
	
	vector<int> L,M,R,al,ar;
	int piv=-1;
	for(int i=0;i+1<b.size();i++){
		if(!ilessequalj(b[i],b[i+1])){//M-1
			piv = i;
			R.push_back(b[i]);
			L.push_back(b[i+1]);
			for(int j=i+2;j<b.size();j++){
				if(ilessequalj(b[piv],b[j])){//(1 <= b[j])?
					R.push_back(b[j]);
				}
				else{
					L.push_back(b[j]);
				}
			}
			break;
		}
		else{
			M.push_back(b[i]);
		}
	}
	if(piv == -1){
		M.push_back(b.back());
		piv = b.size()-1;
	}

	/*if(a.size() == 1){
		ar = a;
	}*/

	if(a.size() == 1 || ilessequalj(b[piv],a[0])){//1
		ar = a;
	}
	else{
		bool f=0;
		for(int i=0;i+2<(int)a.size();i++){//k-2
			al.push_back(a[i]);
			if(!ilessequalj(a[i+1],a[i])){
				f=1;
				for(int j=i+1;j<a.size();j++){
					ar.push_back(a[j]);
				}
				break;
			}
		}
		if(!f){
			ar.push_back(a.back());
			a.pop_back();al.push_back(a.back());
		}
	}
	printf("! ");
	for(int v:al)printf("%d ",v);
	//cout << '*' << endl;
	for(int v:L)printf("%d ",v);
	for(int v:M)printf("%d ",v);
	for(int v:R)printf("%d ",v);
	//cout << '*' << endl;
	for(int v:ar)printf("%d ",v);
	printf("\n");fflush(stdout);
}
signed main(){
	int T;cin >> T;for(int i=1;i<=T;i++){
		solve();
	}
}
