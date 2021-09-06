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
    int n;
    string str;
    CAS {
        cin>>n>>str;
        int num1 = 0,num2 = 0;
        vector<int> v1,v2,v;
        for(int i=0;i<n;i++){
            if(str[i] == 'T') num1++;
            else num2++;
        }
        if(2*num2 != num1){
            cout<<"NO\n"; continue;
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt<num1/2 && str[i]=='T'){ v1.push_back(i); cnt++; }
            else if(str[i] == 'T') v2.push_back(i);
            else v.push_back(i);
        }
        bool flag = true;
        for(int i=0;i<v.size();i++){
            if(v1[i]>v[i] || v2[i]<v[i]){
                flag = false;
                break;
            }
        }
        YON;
    }
    return 0;
}
