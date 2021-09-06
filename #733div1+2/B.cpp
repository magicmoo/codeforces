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
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m;
    CAS {
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            if(i%2==1) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(i%2==0) v.push_back(1);
            else v.push_back(0);
        }
        for(int i=2;i<n;i++){
            if(v[i] && i!=n-1) cout<<1;
            else cout<<0;
            for(int j=2;j<m;j++) cout<<0;
            if(v[i] && i!=n-1) cout<<1;
            else cout<<0;
            cout<<"\n";
        }
        for(int i=1;i<=m;i++){
            if(i%2==1) cout<<1;
            else cout<<0;
        }
        cout<<"\n\n";
    }
    return 0;
}
