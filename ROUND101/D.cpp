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
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T; while(T--){
        int ans = 0;
        cin>>n;
        if(n <= 8){
            cout<<n-3+(int)(log(n*2-1)/log(2))<<"\n";
            for(int i=3;i<n;i++){
                cout<<i<<" "<<n<<"\n";
            }
            int nn = n;
            while(nn != 1){
                cout<<n<<" "<<2<<"\n";
                nn = (nn+1)/2;
            }
        }else{
            cout<<n-4+3+(int)(log(n*8-1)/log(8))<<"\n";
            for(int i=3;i<n;i++){
                if(i == 8) continue;
                cout<<i<<" "<<n<<"\n";
            }
            int nn = n;
            while(nn != 1){
                cout<<n<<" "<<8<<"\n";
                nn = (nn+7)/8;
            }
            cout<<"8 2\n";
            cout<<"8 2\n";
            cout<<"8 2\n";
        }
    }
    return 0;
}
