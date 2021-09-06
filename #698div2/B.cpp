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

int num[100];
bool check(int x,int d){
    while(x){
        if(x%10 == d) return true;
        x /= 10;
    }
    return false;
}

void init(int d){
    memset(num,0,sizeof(num));
    num[0] = 1;
    for(int i=1;i<d*10;i++){
        if(i>=d && num[i-d]) num[i] = 1;
        else if(check(i,d)) num[i] = 1;
        else{
            for(int j=1;j<d;j++){
                if(i < 10*j+d) break;
                if(num[i-10*j-d]) num[i] = 1;
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,q,d,n;
    cin>>T;
    while(T--){
        cin>>q>>d;
        init(d);
        // for(int i=1;i<=100;i++) cout<<num[i]<<"\n";
        // cout<<"\n";
        for(int i=0;i<q;i++){
            cin>>n;
            if(n >= d*10) cout<<"YES\n";
            else if(num[n%(d*10)]) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}

