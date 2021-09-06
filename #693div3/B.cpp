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
    int T,num1,num2,n,num;
    cin>>T;
    while(T--){
        num1 = num2 = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num;
            if(num == 1) num1++;
            else num2++;
        }
        if(num2%2==0){
            if(num1%2 == 0) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            if(num1%2 != 0) cout<<"NO\n";
            else if(num1>=2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
