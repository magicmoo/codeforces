#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
int arr[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        vector<int> v;
        for(int i=1;i<=n;i++) if(arr[i]%2==0) v.push_back(arr[i]);
        for(int i=1;i<=n;i++) if(arr[i]%2!=0) v.push_back(arr[i]);
        int ans = 0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(__gcd(v[i],2*v[j])!=1) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
