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
const int maxn = 1e5+5;

int a[maxn],b[maxn],c[maxn];
int book[maxn],map[maxn],ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,m;
    vector<int> v[maxn];
    vector<int> mv[maxn];
    set<int> s;
    cin>>T;
    while(T--){
        for(int i=0;i<maxn;i++){
            v[i].clear();
            mv[i].clear();
        }
        s.clear();
        memset(map,0,sizeof(map));
        memset(book,0,sizeof(book));
        cin>>n>>m;
        int sum = 0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=m;i++) cin>>c[i];
        for(int i=1;i<=n;i++){
            if(a[i] != b[i]){
                if(!book[b[i]]) s.insert(b[i]);
                book[b[i]]++;
                sum++;
                v[b[i]].push_back(i);
            }
            map[b[i]]++;
            mv[b[i]].push_back(i);
        }
        int last = 0;
        vector<int> lasti;
        for(int i=1;i<=m;i++){
            if(sum==0){
                if(!map[c[i]]){
                    last = 1;
                    lasti.push_back(i);
                }
                else if(last){
                    last = 0;
                    for(int j=0;j<lasti.size();j++){
                        ans[lasti[j]] = mv[c[i]][0];
                    }
                    ans[i] = mv[c[i]][0];
                }else{
                    ans[i] = mv[c[i]][0];
                }
            }else{
                if(book[c[i]]){
                    ans[i] = v[c[i]][book[c[i]]-1];
                    book[c[i]]--;
                    sum--;
                    if(!book[c[i]]) s.erase(c[i]);
                }else{
                    // for(auto i=s.begin();i!=s.end();i++){
                    //     cout<<*i<<" ";
                    // }
                    ans[i] = v[*(s.begin())][0];
                }
            }
        }
        if(last > 0 || sum>0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            for(int i=1;i<=m;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
