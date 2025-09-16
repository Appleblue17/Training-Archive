#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
const int N=1005;
int n;
int ptp[N], pa[N], pb[N], pid[N], pnum[N], pres[N];
bool f[9][9][9][9][9];
int g[9][5][5][5][5];
bool check(int lim){
	memset(f, 0, sizeof f);
	f[0][0][0][0][0]=1;
	for(int id=1; id<=8; ++id){
		for(int c1=0; c1<=8; ++c1){
			for(int c2=0; c2<=8; ++c2){
				for(int c3=0; c3<=8; ++c3){
					for(int c4=0; c4<=8; ++c4)if(f[id-1][c1][c2][c3][c4]){
						for(int d1=0; d1<=4&&c1+d1<=8; ++d1){
							for(int d2=0; c2+d2<=8&&d1+d2<=4; ++d2){
								for(int d3=0; c3+d3<=8&&d1+d2+d3<=4; ++d3){
									if(c4+4-d1-d2-d3<=8&&g[id][d1][d2][d3][4-d1-d2-d3]>lim){
										f[id][c1+d1][c2+d2][c3+d3][c4+4-d1-d2-d3]=1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return f[8][8][8][8][8];
}
int bel[5], _bel[5], cnt[5];
void dfs(int x, int id){
	if(x==5){
		int &val=g[id][cnt[1]][cnt[2]][cnt[3]][cnt[4]];
		for(int i=1; i<=4; ++i) bel[i]=_bel[i];
		for(int i=1; i<=n; ++i){
			if(pid[i]!=id) continue;
			if(ptp[i]==1){
				if(bel[1]!=pa[i]||bel[2]!=pa[i]||bel[3]!=pa[i]||bel[4]!=pa[i]){
					val=max(val, i); return ;
				}
				bel[1]=bel[2]=bel[3]=bel[4]=0;
			}
			else{
				if(bel[1]!=pa[i]&&bel[2]!=pa[i]&&bel[3]!=pa[i]&&bel[4]!=pa[i]){
					val=max(val, i); return ;
				}
				if(pres[i]==1){
					if(bel[pnum[i]]==pb[i]){
						bel[pnum[i]]=pa[i];
						continue;
					}
					else{
						val=max(val, i); return ;
					}
				}
				else{
					if(bel[pnum[i]]==pb[i]){
						val=max(val, i); return ;
					}
					else{
						continue;
					}
				}
			}
		}
		val=max(val, n+1);
		return ;
	}
	for(int i=1; i<=4; ++i){
		_bel[x]=i;
		++cnt[i];
		dfs(x+1, id);
		--cnt[i];
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i){
		string tem;
		cin>>pa[i]>>tem;
		if(tem=="A"){
			ptp[i]=0;
			cin>>pb[i];
			cin>>tem;
			pid[i]=tem[0]-'0';
			pnum[i]=tem[1]-'A'+1;
			cin>>tem;
			pres[i]=(tem=="yes");
		}
		else{
			ptp[i]=1;
			cin>>pid[i];
		}
	}
	for(int id=1; id<=8; ++id){
		dfs(1, id);
	}
	int L=1, R=n, mid, ret=0;
	while(L<=R){
		mid=(L+R)>>1;
		if(check(mid)) {
			ret=mid; L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	if(ret==n){
		printf("yes\n");
	}
	else{
		printf("no\n%d\n", ret+1);
	}
	return 0;
}

