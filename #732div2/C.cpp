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
const int maxn = 1e5+5;
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
        vector<int> v1,v2,v;
        for(int i=1;i<=n;i++){
            if(i%2) v1.push_back(arr[i]);
            else v2.push_back(arr[i]);
        }
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        int now = 0;
        while(now<v1.size() || now<v2.size()){
            if(now < v1.size()) v.push_back(v1[now]);
            if(now < v2.size()) v.push_back(v2[now]);
            now++;
        }
        bool flag = true;
        for(int i=1;i<v.size();i++){
            if(v[i]<v[i-1]) flag = false;
        }
        YON;
    }
    return 0;
}
