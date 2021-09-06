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
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T; cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n == 1) cout<<9<<"\n";
        else{
            cout<<98;
            for(int i=2,num=9;i<n;i++,num++){
                cout<<num%10;
            }
            cout<<"\n";
        }
    }
    return 0;
}
