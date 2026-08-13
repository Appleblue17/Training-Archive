#include<bits/stdc++.h>
using namespace std;
int d,s,n,rt[4005],rtt[4005];
#define mid ((l+r)>>1)
struct js
{
	int tr[2000005],tag[2000005],cnt=0,ls[2000005],rs[2000005];
	void push_down(int p)
	{
		if(!ls[p]) ls[p]=++cnt;
		if(!rs[p]) rs[p]=++cnt;
		tag[ls[p]]=max(tag[ls[p]],tag[p]),tr[ls[p]]=max(tr[ls[p]],tag[p]);
	 	tag[rs[p]]=max(tag[rs[p]],tag[p]),tr[rs[p]]=max(tr[rs[p]],tag[p]);
		tag[p]=0;
	}
	void push_up(int p)
	{
		tr[p]=max(tr[ls[p]],tr[rs[p]]);
	}
	void update(int &p,int l,int r,int L,int R,int w)
	{
		if(!p) p=++cnt;
		if(L<=l&&R>=r)
		{
			tr[p]=max(tr[p],w),tag[p]=max(tag[p],w);
			return ;
		}
		push_down(p);
		if(L<=mid&&!ls[p]) ls[p]=++cnt;
		if(R>mid&&!rs[p]) rs[p]=++cnt;
		if(L<=mid) update(ls[p],l,mid,L,R,w);
		if(R>mid) update(rs[p],mid+1,r,L,R,w);
		push_up(p); 
	}
	int query(int p,int l,int r,int L,int R)
	{
		if(!p) return 0;
		if(L<=l&&R>=r) return tr[p];
		int res=0;
		push_down(p);
		if(L<=mid) res=max(res,query(ls[p],l,mid,L,R));
		if(R>mid) res=max(res,query(rs[p],mid+1,r,L,R));
		return res;
	}
}tr,trr;
//tr是mx,trr是tag 
void update(int p,int l,int r,int L,int R,int ll,int rr,int w)
{
	tr.update(rt[p],1,s,ll,rr,w);
	if(L<=l&&R>=r)
	{
		trr.update(rtt[p],1,s,ll,rr,w);
		return ;
	}
	if(L<=mid) update(p<<1,l,mid,L,R,ll,rr,w);
	if(R>mid) update((p<<1)|1,mid+1,r,L,R,ll,rr,w);
}
int query(int p,int l,int r,int L,int R,int ll,int rr)
{
	int res=0;
	res=trr.query(rtt[p],1,s,ll,rr);
	if(L<=l&&R>=r)
	{
		res=max(res,tr.query(rt[p],1,s,ll,rr));
		return res;
	}
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R,ll,rr));
	if(R>mid) res=max(res,query((p<<1)|1,mid+1,r,L,R,ll,rr));
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>d>>s>>n;
	while(n--)
	{
		int dd,ss,w,x,y;
		cin>>dd>>ss>>w>>x>>y;
		x++,y++,update(1,1,d,x,x+dd-1,y,y+ss-1,w+query(1,1,d,x,x+dd-1,y,y+ss-1)); 
	}
	cout<<query(1,1,d,1,d,1,s);
	return 0;
}