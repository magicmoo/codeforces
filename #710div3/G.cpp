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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;
int book[30],map[30];
char ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T;
    string s;
    cin>>T; while(T--){
        cin>>s;
        memset(book,0,sizeof(book));
        memset(map,0,sizeof(map));
        for(int i=1;i<s.length();i++) book[s[i]-'a']++;
        int last = -1;
        ans[++last] = s[0];
        map[s[0]-'a']++;
        for(int i=1;i<s.length();i++){
            book[s[i]-'a']--;
            if(map[s[i]-'a']) continue;
            while(last>=0 && s[i]>ans[last] && book[ans[last]-'a']){ map[ans[last]-'a']--; last--; }
            ans[++last] = s[i];
            map[s[i]-'a']++;
        }
        for(int i=0;i<=last;i++) cout<<ans[i];
        cout<<"\n";
    }
    return 0;
}
