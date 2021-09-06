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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T;
    string a,b;
    cin>>T; while(T--){
        cin>>a>>b;
        int ans = a.length()+b.length();
        if(a==b){ cout<<"0\n"; continue;}
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length();j++){
                if(a[i] != b[j]) continue;
                for(int k=0;i+k<a.length()&&j+k<b.length();k++){
                    if(a[i+k] != b[j+k]) break;
                    int temp = (a.length()+b.length()) - 2*(k+1);
                    ans = min(temp,ans);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
