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
    int n;
    string str;
    CAS {
        cin>>n;
        cin>>str;
        int cnt = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == '0') cnt++;
        }
        if(n%2 == 1 && str[n/2] == '0' && cnt>1){
            cout<<"ALICE\n";
        }else cout<<"BOB\n";
    }
    return 0;
}
