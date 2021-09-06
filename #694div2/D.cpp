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
const int MAXN = 3e5+5;
const int MAX = 1e6+5;
int book[MAX];
int book2[MAX];
int n,num,q;
void init(){
    for(int i=1;i*i<MAX;i++){
        for(int j=1;i*i*j<MAX;j++){
            book[i*i*j] = i*i;
        }
    }
    for(int i=1;i<MAX;i++){
        book2[i]=i;
        while(book[book2[i]] > 1) book2[i] /= book[i];
    }
}
void solve(){
    map<int,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        num = book2[num];
        m[num]++;
    }
    int ans1 = 0,ans2 = 0;
    for(auto number: m) ans1 = max(ans1,number.second);
    for(auto number: m)
        if(number.second%2==0 || number.first==1) ans2 += number.second;
    ans2 = max(ans2,ans1);
    cin>>q;
    while(q--){
        ll number; cin>>number;
        cout<<(number?ans2:ans1)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T; cin>>T;
    init();
    while(T--) solve();
    return 0;
}
