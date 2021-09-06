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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    string s;
    CAS {
        cin>>s;
        int cnt = 0,ans = 0;
        for(int i=0;i<s.length();i++) if(s[i] == 'a') cnt++;
        if(cnt == s.length()){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<s.length();i++){
            if(s[i] != 'a'){
                ans = i;
                break;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<s.length()-ans;i++) cout<<s[i];
        cout<<'a';
        for(int i=s.length()-ans;i<s.length();i++) cout<<s[i];
        cout<<"\n";
    }
    return 0;
}
