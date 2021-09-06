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
int book[maxn],ans[maxn],num[maxn],sum[maxn];
set<int> s[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m,cnt;
    cin>>T; while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) book[i] = sum[i] = 0;
        for(int i=1;i<=m;i++) ans[i] = num[i] = 0;
        for(int i=1;i<=m;i++) s[i].clear();
        int mid = (m+1)/2;
        for(int i=1;i<=m;i++){
            cin>>num[i];
            for(int j=1;j<=num[i];j++){
                cin>>cnt;
                s[i].insert(cnt);
                book[cnt]++;
            }
        }
        int Max = 0,Mi = 0;
        for(int i=1;i<=n;i++){
            if(book[i] > Max){
                Max = book[i];
                Mi = i;
            }
        }
        if(Max <= mid){
            cout<<"YES\n";
            for(int i=1;i<=m;i++){
                cout<<(*s[i].begin())<<" ";
            }
            cout<<"\n";
        }else{
            for(int i=1;i<=m;i++){
                if(num[i] == 1){
                    cnt = *(s[i].begin());
                    ans[i] = cnt;
                    sum[cnt]++;
                }
            }
            if(sum[Mi] > mid){ cout<<"NO\n"; continue; }
            for(int i=1;i<=m;i++){
                if(num[i] == 1) continue;
                if(sum[Mi]<mid && s[i].count(Mi)==1){
                    ans[i] = Mi;
                    sum[Mi]++;
                }else{
                    for(auto index : s[i]){
                        if(index != Mi){ ans[i] = index; break; }
                    }
                }
            }
            cout<<"YES\n";
            for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
