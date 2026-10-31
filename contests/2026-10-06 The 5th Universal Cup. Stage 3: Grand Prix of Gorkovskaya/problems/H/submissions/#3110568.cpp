#include<bits/stdc++.h>
using namespace std;
// #define double long double

namespace SIMPLEX {
	
int n,m;  // Number of constraints and variables.
vector< vector<double> > tab;
vector<int> B, N;               // Basic and nonbasic variables.
constexpr double eps = 1e-8;  // Precision.

// Pivot on (N[x], B[y]).
void pivot(int x, int y) {
	swap(N[x], B[y]);
	double v = -1 / tab[x][y];
	for (int j = 0; j <= m + 1; ++j) {
	tab[x][j] = j == y ? -v : v * tab[x][j];
	}
	for (int i = 0; i <= n; ++i) {
	if (i == x) continue;
	v = tab[i][y];
	tab[i][y] = 0;
	for (int j = 0; j <= m + 1; ++j) {
		tab[i][j] += v * tab[x][j];
	}
	}
}

// First phase: find an initial BFS.
// Return false if no feasible solution.
bool initialize() {
	int neg_count = 0;
	for (int j = 0; j < m; ++j) {
	if (tab[n][j] < -eps) {
		for (int i = 0; i <= n; ++i) {
		tab[i][m + 1] += tab[i][j];
		}
		B[j] = ~B[j];
		++neg_count;
	}
	}
	while (neg_count) {
	int x = -1;
	double mi = -eps;
	for (int i = 0; i < n; ++i) {
		if (tab[i][m + 1] < mi) {
		x = i;
		mi = tab[i][m + 1];
		}
	}
	if (x == -1) return false;
	int y = -1;
	mi = INFINITY;
	for (int j = 0; j < m; ++j) {
		if ((B[j] < 0 && tab[x][j] < -eps) || (B[j] >= 0 && tab[x][j] > eps)) {
		auto tmp = tab[n][j] / tab[x][j] + (B[j] < 0 ? -eps : eps);
		if (tmp < mi) {
			y = j;
			mi = tmp;
		}
		}
	}
	if (B[y] < 0) {
		--neg_count;
		B[y] = ~B[y];
		pivot(x, y);
		tab[x][m + 1] += 1;
	} else {
		pivot(x, y);
	}
	}
	return true;
}

// Second phase: find an optimal BFS.
// Return false if the problem is unbounded.
bool simplex() {
	while (true) {
		int x = -1;
		double mi = -eps;
		for (int i = 0; i < n; ++i) {
			if (tab[i][m] < mi) {
				x = i;
				mi = tab[i][m];
			}
		}
		// No column with a negative reduced cost => Optimal.
		if (x == -1) break;
		int y = -1;
		mi = INFINITY;
		for (int j = 0; j < m; ++j) {
			if (tab[x][j] <= eps) continue;
			if (tab[n][j] / tab[x][j] < mi) {
				y = j;
				mi = tab[n][j] / tab[x][j];
			}
		}
		// No row with a positive ratio => Unbounded.
		if (y == -1) return false;
		pivot(x, y);
	}
	return true;
}

// -1 = Infeasible
// 1 = Unbounded
int solve(int n_,int m_) {
	n=n_,m=m_;
	B.resize(m);
	N.resize(n);
	iota(B.begin(), B.end(), n);
	iota(N.begin(), N.end(), 0);
	if(!initialize()) return -1;
	if(simplex()) return 0;
	else return 1;
}

double getmax(){
	return tab[n][m];
}

vector<double> getsol(){
	vector<double> x(n);
	for(int j = 0; j < m; j++) {
		if (B[j] < n) x[B[j]] = tab[n][j];
	}
	return x;
}

// using SIMPLEX::tab;
// cin >> n >> m;
// tab.assign(n + 1, vector<double>(m + 2));
// for (int i = 0; i < n; ++i) {
// 	cin >> tab[i][m];
// 	tab[i][m] = -tab[i][m];
// }
// for (int j = 0; j < m; ++j) 
// 	for (int i = 0; i <= n; ++i) 
// 		cin >> tab[i][j];

// switch (SIMPLEX::solve(n,m)) {
// 	case -1:
// 		cout << "Infeasible" << endl;
// 		break;
// 	case 1:
// 		cout << "Unbounded" << endl;
// 		break;
// 	case 0: {
// 		double ans=SIMPLEX::getmax();
// 		vector <double> sol=SIMPLEX::getsol();
// 		cout << fixed << setprecision(10)<<ans<<endl;
// 		for (double x: sol) cout << fixed << setprecision(10) << x << " ";
// 		cout << endl;
// 		break;
// 	}
// }

}

int T,n;
int buc[8];
bool vis[8];

int lcm(int x,int y){
	return x/__gcd(x,y)*y;
}

int ID(int x,int y){
	return x*(x+1)/2+y;
}


vector< vector<double> > tab;

int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n); int ans=0;
		memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;i++){
			int x; scanf("%d",&x); buc[x]++;
		}
		vector <int> V;
		for(int i=1;i<=7;i++) if(buc[i]) V.push_back(i);
		int k=V.size();
		
		int sn=k*(k+1)/2,sm=k+(1<<k)-2;
		tab.clear();
		tab.assign(sn + 1, vector<double>(sm + 2));
		
		for(int i=0;i<k;i++){
			for(int j=0;j<=i;j++){
				int id=ID(i,j);
				// cout<<i<<" "<<j<<" "<<id<<endl;
				tab[id][sm]=-lcm(V[i],V[j]);
			}
		}
		
		for(int t=0;t<k;t++){
			for(int i=0;i<k;i++){
				for(int j=0;j<=i;j++){
					int id=ID(i,j);
					tab[id][t]=(t==i)+(t==j);
				}
			}
			tab[sn][t]=2*buc[V[t]];
		}
		
		for(int mac=1;mac+1<(1<<k);mac++){
			int pos=mac+k-1;
			for(int i=0;i<k;i++){
				for(int j=0;j<=i;j++){
					int id=ID(i,j);
					tab[id][pos]= ((mac>>i & 1) && (mac>>j & 1));
				}
			}
			int sum=0;
			for(int i=0;i<k;i++)
				if(mac>>i & 1) sum+=buc[V[i]];
			
			tab[sn][pos]=sum-1;
		}
		
		// for(int i=0;i<=sn;i++){
		// 	for(int j=0;j<=sm;j++){
		// 		cout<<tab[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		
		for(int p=0;p<k;p++){
			int u=p*(p+1)/2;
			// (V[0],V[u]) must be chosen
			
			// cout<<" u = "<<u<<endl;
			
			auto & stab=SIMPLEX::tab;
			stab=tab;
			stab[sn][0]--;
			stab[sn][u]--;
			
			for(int mac=1;mac+1<(1<<k);mac++){
				int pos=mac+k-1;
				if((mac & 1) && (mac>>u & 1)) stab[sn][pos]--;
			}
			
			// for(int i=0;i<=sn;i++){
			// 	for(int j=0;j<=sm;j++){
			// 		cout<<stab[i][j]<<" ";
			// 	}
			// 	cout<<endl;
			// }
			// cout<<endl;
			
			int res=SIMPLEX::solve(sn,sm);
			if(res==0){
				double mx=SIMPLEX::getmax();
				vector <double> sol=SIMPLEX::getsol();
				
				// cout<<u<<": "<<mx<<endl;
				// for (double x: sol) cout << x << " ";
				// cout << endl;
				
				ans=max(ans,(int)(mx+0.5));
			}
		}
		
		cout<<ans<<endl;
	}
}