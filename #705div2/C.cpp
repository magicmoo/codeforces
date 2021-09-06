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

int book[30];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k;
    string s;
    cin>>T; while(T--){
        cin>>n>>k;
        cin>>s;
        int ans = 0;
        memset(book,0,sizeof(book));
        if(n%k != 0){
            cout<<-1<<"\n";
            continue;
        }
        for(int i=0;i<n;i++) book[s[i]-'a']++;
        int sum = 0;
        for(int j=0;j<26;j++){
            sum += book[j]/k;
        }
        if(sum == n/k){
            cout<<s<<"\n";
            continue;
        }
        int mid = 0;
        for(int i=n-1;i>=0;i--){
            bool flag = false;
            sum = 0;
            if(s[i] == 'z'){
                book[25]--;
                continue;
            }
            for(int j=0;j<26;j++) sum += (book[j]+k-1)/k;
            while(s[i] < 'z'){
                book[s[i]-'a']--;
                s[i]++;
                book[s[i]-'a']++;
                if(book[s[i]-'a'-1]%k == 0) sum--;
                if(book[s[i]-'a']%k == 1) sum++;
                if(sum <= n/k){
                    mid = i;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            book[s[i]-'a']--;
        }
        int cnt = mid+1;
        for(int i=0;i<26;i++){
            for(int j=book[i];j%k!=0;j++){
                cnt++;
            }
        }
        for(int i=0;i<=mid;i++) cout<<s[i];
        for(int i=cnt;i<n;i++) cout<<'a';
        for(int i=0;i<26;i++){
            for(int j=book[i];j%k!=0;j++){
                cout<<(char)(i+'a');
            }
        }
        cout<<"\n";
    }
    return 0;
}
