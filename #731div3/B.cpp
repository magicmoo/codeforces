#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;

int main(){
    IOS;
    string str;
    CAS {
        cin>>str;
        int index = -1;
        for(int i=0;i<str.length();i++){
            if(str[i] == 'a'){
                index = i;
                break;
            }
        }
        if(index == -1){
            cout<<"NO\n"; continue;
        }
        int l = index-1,r = index+1;
        char now = 1;
        bool flag = true;
        while(l>=0 || r<str.length()){
            if(l>=0 && str[l] == 'a'+now){
                l--; now++;
            }else if(r<str.length() && str[r]=='a'+now){
                r++; now++;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑      永无bug