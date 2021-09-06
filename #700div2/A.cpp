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
    cin>>T;
    string str;
    while(T--){
        cin>>str;
        bool flag = true;
        for(int i=0;i<str.length();i++){
            if(flag && str[i]=='a') str[i] = 'b';
            else if(!flag && str[i]=='z') str[i] = 'y';
            else if(flag) str[i] = 'a';
            else str[i] = 'z';
            flag = !flag;
        }
        // if(flag){
        //     if(str[str.length()-1]=='a') str[str.length()-1] = 'b';
        //     else str[str.length()-1] = 'a';
        // }else{
        //     if(str[str.length()-1]=='z') str[str.length()-1] = 'y';
        //     else str[str.length()-1] = 'z';
        // }
        cout<<str<<"\n";
    }
    return 0;
}
