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
const ll INF = 0x3f3f3f3f;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,x,y;
    string str;
    cin>>T;
    while(T--){
        cin>>x>>y>>str;
        ll xx = 0, yy = 0;
        for(ll i=0;i<str.length();i++){
            if(x<0 && str[i]=='L'){
                xx--;
            }else if(x>0 && str[i]=='R'){
                xx++;
            }else if(y>0 && str[i]=='U'){
                yy++;
            }else if(y<0 && str[i]=='D'){
                yy--;
            }
        }
        if(x>=0 && xx>=x){
            if(y>=0 && yy>=y){
                cout<<"YES\n";
            }else if(y<0 && yy<=y){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else if(x<0 && xx<=x){
            if(y>=0 && yy>=y){
                cout<<"YES\n";
            }else if(y<0 && yy<=y){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
