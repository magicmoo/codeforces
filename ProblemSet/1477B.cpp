#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int a[maxn],b[maxn],l[maxn],r[maxn];
struct edge
{
	long long l,r,tag,multag,sum;
}tree[maxn << 2];//开4倍 
ll n,m,op,x,y,p = INF,k;
void pass(long long x)
{
	tree[x*2].sum=((tree[x].multag*tree[x*2].sum)+tree[x].tag*(tree[x*2].r-tree[x*2].l)%p)%p;//左区间修改一下 
	tree[x*2|1].sum=((tree[x].multag*tree[x*2|1].sum)+tree[x].tag*(tree[x*2|1].r-tree[x*2|1].l)%p)%p;

	tree[x*2].multag*=tree[x].multag;//左区间乘法标记更新 
	tree[x*2|1].multag*=tree[x].multag;

    tree[x*2].tag=tree[x*2].tag*tree[x].multag+tree[x].tag;
    tree[x*2|1].tag=tree[x*2|1].tag*tree[x].multag+tree[x].tag;

	tree[x].tag=0;tree[x].multag=1;//清空本身标记 
	return ;
}
void build(long long x,long long l,long long r)//我们现在已经建树建到x点了，然后目前的区间是[l,r)
{
	tree[x].l=l,tree[x].r=r,tree[x].tag=0,tree[x].sum=0;tree[x].multag=1;
	if(r-l==1)//如果是叶节点
		tree[x].sum=a[l];
	else 
	{
		long long mid=(l+r)>>1;//找到中间节点来划分左右儿子 
		build(x*2,l,mid);
		build((x*2)|1,mid,r);
		tree[x].sum=(tree[x*2].sum+tree[(x*2)|1].sum);
	}
	return ;
} 
void add(long long x,long long l,long long r,long long k)//我们当前已经修改到了点x，然后目前区间是[l,r),修改的差值(即要加上多少)为k 
{
	if(l<=tree[x].l && r>=tree[x].r)//如果整个区间都是我们要修改的直接修改就好了 
	{
		tree[x].sum+=k*(tree[x].r-tree[x].l);
		tree[x].tag+=k;
	}
	else 
	{
		long long mid=(tree[x].l+tree[x].r)>>1;
		pass(x);
		if(l<mid)
			add(x*2,l,min(mid,r),k);//这边我们取min(mid,r)的原因就是r有可能比mid小 
		if(mid<r)
			add((x*2)|1,max(mid,l),r,k);//同理 
		tree[x].sum=tree[x*2].sum+tree[(x*2)|1].sum;
	}
	return ;
}

void  mul(ll x,ll l,ll r,ll k)
{
	if(l<=tree[x].l && r>=tree[x].r)//如果整个区间都是我们要修改的直接修改就好了 
	{
		tree[x].sum*=k;
		tree[x].tag*=k;
        tree[x].multag*=k;
	}
	else 
	{
		long long mid=(tree[x].l+tree[x].r)>>1;
		pass(x);
		if(l<mid)
			mul(x*2,l,min(mid,r),k);//这边我们取min(mid,r)的原因就是r有可能比mid小 
		if(mid<r)
			mul((x*2)|1,max(mid,l),r,k);//同理 
		tree[x].sum=tree[x*2].sum+tree[(x*2)|1].sum;
	}
	return ;
}
long long ask(long long x,long long l,long long r)
{
	if(l<=tree[x].l && r>=tree[x].r)//如果整个区间都是我们要查询的直接加就好了 
		return tree[x].sum;//回溯 
	else 
	{
		long long mid=(tree[x].l+tree[x].r)>>1,ans=0;
		pass(x);
		if(l<mid)
			{ans+=ask(x*2,l,min(mid,r));}
		if(mid<r)
			{ans+=ask((x*2)|1,max(mid,l),r);}
		return ans;
	}
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,q,ll,rr;
    cin>>T; while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%1d",&b[i]);
        for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
        build(1,1,n+1);
        for(int i=1;i<=q;i++){
            cin>>ll>>rr;
            l[i] = min(ll,rr);
            r[i] = max(ll,rr);
        }
        bool flag = true;
        for(int i=q;i>=1;i--){
            int len = r[i]-l[i]+1;
            int temp = ask(1,l[i],r[i]+1);
            if(len%2==0 && temp==len/2){ flag = false; break; }
            mul(1,l[i],r[i]+1,0);
            if(temp > len/2) add(1,l[i],r[i]+1,1);
        }
        if(!flag){ cout<<"NO\n"; continue; }
        for(int i=1;i<=n;i++){
            if(b[i] != ask(1,i,i+1)){ flag = false; break; }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
