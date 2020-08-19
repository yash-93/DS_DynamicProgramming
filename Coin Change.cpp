#include <bits/stdc++.h>
using namespace std;

int main(){
    int total; cin >> total;
    int no_coins; cin >> no_coins;
    vector<int> coins(no_coins);
    for(int i=0; i<no_coins; i++)
        cin >> coins[i];

    coins.insert(coins.begin(),0);

    /*for(auto i:coins)
        cout << i << " ";*/

    vector<vector<int>> dp(no_coins+1, vector<int> (total+1));

    for(int i=0; i<=no_coins; i++)
        dp[i][0] = 1;

    for(int i=1; i<=total; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=no_coins; i++){
        for(int j=1; j<=total; j++){
            if(j<coins[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            }
        }
    }

    cout << dp[no_coins][total];
    /*cout << endl;
    for(int i=0; i<=no_coins; i++){
        for(int j=0; j<=total; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
