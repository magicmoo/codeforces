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
int a[maxn],book[maxn],ans[maxn],pre[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) book[i] = 0;
        for(int i=1;i<=n;i++) cin>>a[i];
        book[a[1]] = 1; cout<<a[1]<<" ";
        int now = 1;
        for(int i=2;i<=n;i++){
            if(a[i] != a[i-1]){
                cout<<a[i]<<" ";
                book[a[i]] = 1;
            }else{
                while(book[now]) now++;
                cout<<now<<" ";
                book[now] = 1;
            }
        }
        cout<<"\n";
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        cout<<a[1]<<" "; s.erase(a[1]);
        for(int i=2;i<=n;i++){
            if(a[i] != a[i-1]){
                cout<<a[i]<<" ";
                s.erase(a[i]);
            }else{
                auto it = s.lower_bound(a[i]);
                cout<<*(--it)<<" ";
                s.erase(it);
            }
        }
        cout<<"\n";
    }
    return 0;
}
