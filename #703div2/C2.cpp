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
void solve1(int n,int m2){
    int l = m2, r = n,mid,temp;
    while(l+1 < r){
        mid = (l+r)>>1;
        cout<<"? "<<m2<<" "<<mid<<"\n";
        cin>>temp;
        cout.flush();
        if(m2 == temp) r = mid;
        else l = mid+1;
    }
    if(l == r) cout<<"! "<<l<<"\n";
    else if(l+1 == r){
        cout<<"? "<<l<<" "<<r<<"\n";
        cin>>temp;
        cout.flush();
        if(temp == l) cout<<"! "<<r<<"\n";
        else cout<<"! "<<l<<"\n";
    }
}

void solve2(int m2){
    int l = 1, r = m2,mid,temp;
    while(l+1 < r){
        mid = (l+r)>>1;
        cout<<"? "<<mid<<" "<<m2<<"\n";
        cin>>temp;
        cout.flush();
        if(m2 == temp) l = mid;
        else r = mid-1;
    }
    if(l == r) cout<<"! "<<l<<"\n";
    else if(l+1 == r){
        cout<<"? "<<l<<" "<<r<<"\n";
        cin>>temp;
        cout.flush();
        if(temp == l) cout<<"! "<<r<<"\n";
        else cout<<"! "<<l<<"\n";
    }
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m2;
    cin>>n;
    cout<<"? 1 "<<n<<"\n";
    cin>>m2;
    cout.flush();
    if(m2 == 1) solve1(n,1);
    else{
        int temp;
        cout<<"? 1 "<<m2<<"\n";
        cin>>temp;
        cout.flush();
        if(temp == m2) solve2(m2);
        else solve1(n,m2);
    }
    cout.flush();
    return 0;
}
