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
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int l = 1, r = n;
    int m2,temp;
    int mid = (l+r)/2;
    while(l+1 < r){
        int mid = (l+r)/2;
        cout<<"? "<<l<<" "<<r<<"\n";
        cin>>m2;
        cout.flush();
        if(m2 < mid){
            cout<<"? "<<l<<" "<<mid<<"\n";
            cin>>temp;
            cout.flush();
            if(temp == m2) r = mid;
            else l = mid+1;
        }else{
            cout<<"? "<<mid<<" "<<r<<"\n";
            cin>>temp;
            cout.flush();
            if(temp != m2) r = mid-1;
            else l = mid;
        }
    }
    if(l == r) cout<<"! "<<l<<"\n";
    else if(l+1 == r){
        cout<<"? "<<l<<" "<<r<<"\n";
        cin>>temp;
        cout.flush();
        if(temp == l) cout<<"! "<<r<<"\n";
        else cout<<"! "<<l<<"\n";
    }
    cout.flush();
    return 0;
}
