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
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,num,cnt;
    CAS {
        cin>>n;
        vector<int> v;
        while(n--){
            cin>>num;
            if(num == 1){
                for(int i=0;i<v.size();i++) cout<<v[i]<<"."; 
                cout<<"1\n";
                v.push_back(1);
            }else{
                int index = 0;
                for(int i=v.size()-1;i>=0;i--){
                    v.pop_back();
                    if(num == v[i]+1) break;
                }
                for(int i=0;i<v.size();i++) cout<<v[i]<<".";
                cout<<num<<"\n";
                v.push_back(num);
            }
        }
    }
    return 0;
}
