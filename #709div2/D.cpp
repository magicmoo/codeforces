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
const int maxn = 1e5+5;
int a[maxn],book[maxn];
int gcd(int a,int b){ return a%b==0?b:gcd(b,a%b); }
int post[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        vector<int> ans;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) book[i] = 0;
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        for(int i=1;i<n;i++) post[i] = i+1;
        post[n] = 1;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(book[now]) continue;
            if(gcd(a[now],a[post[now]])==1){
                ans.push_back(post[now]);
                book[post[now]] = 1;
                post[now] = post[post[now]];
                q.push(now);
            }
        }
        cout<<ans.size()<<" ";
        for(auto i : ans) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
