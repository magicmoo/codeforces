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
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int arr[maxn],a[maxn],b[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int num = 0;
        for(int i=1;i<=n;i++){
            num += a[i]-b[i];
        }
        if(num!=0) cout<<"-1\n";
        else{
            vector<pair<int,int>> v1,v2;
            int m = 0;
            for(int i=1;i<=n;i++){
                if(a[i]<b[i]){ v1.push_back({i,b[i]-a[i]}); m+=b[i]-a[i]; }
                else if(a[i]>b[i]) v2.push_back({i,a[i]-b[i]});
            }
            int now1 = 0,now2 = 0;
            cout<<m<<"\n";
            while(now1<v1.size() && now2<v2.size()){
                cout<<v2[now2].first<<" "<<v1[now1].first<<"\n";
                v1[now1].second--; v2[now2].second--;
                if(v1[now1].second == 0) now1++;
                if(v2[now2].second == 0) now2++;
            }
        }
    }
    return 0;
}
