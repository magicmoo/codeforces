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
    int T;
    string str;
    cin>>T;
    while(T--){
        cin>>str;
        int ans = 0;
        for(int i=0;i<str.length()-1;i++){
            if(str[i] == '0') continue;
            if(i+2<str.length()){
                if(str[i]==str[i+1] && str[i]==str[i+2]){
                    ans+=2;
                    str[i+1] = str[i+2] = '0';
                }else if(str[i]==str[i+1]){
                    ans++;
                    str[i+1] = '0';
                }else if(str[i]==str[i+2]){
                    ans++;
                    str[i+2] = '0';
                }
            }else if(i+1<str.length()){
                if(str[i]==str[i+1]){
                    ans++;
                    str[i+1] = '0';
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
