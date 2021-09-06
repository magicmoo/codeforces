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
set<int> s;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k,num;
    cin>>T; while(T--){
        cin>>n>>k;
        s.clear();
        int Max = 0;
        for(int i=0;i<n;i++){
            cin>>num;
            Max = max(Max,num);
            s.insert(num);
        }
        int mex = 0;
        for(int i:s){
            if(i == mex) mex++;
            else break;
        }
        if(mex > Max){
            cout<<(k+s.size())<<"\n";
        }else{
            num = (mex+Max+1)/2;
            if(!s.count(num) && k>0) cout<<(s.size()+1)<<"\n";
            else cout<<(s.size())<<"\n";
        }
    }
    return 0;
}
