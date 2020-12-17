#include <bits/stdc++.h>
using namespace std;

int **memo;

bool isPalindrome(string s, int i, int j){
    bool isPalin = true;
    while(i<=j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return isPalin;
}

int PP(string s, int i, int j){
    if(i>=j) return 0;
    if(isPalindrome(s,i,j)) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    int minn = INT_MAX;
    for(int k=i; k<j; k++){
        int left, right;
        if(memo[i][k] != -1){
            left = memo[i][k];
        }
        else {
            left = PP(s,i,k);
            memo[i][k] = left;
        }
        if(memo[k+1][j] != -1){
            right = memo[k+1][j];
        }
        else {
            left = PP(s,k+1,j);
            memo[k+1][j] = right;
        }
        int temp = left + right + 1;
        minn = min(temp,minn);
    }
    return memo[i][j] = minn;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    memo = new int*[n];
    for(int i=0; i<n; i++){
        memo[i] = new int[n];
        memset(memo[i],-1,sizeof(int)*n);
    }
    cout << PP(s,0,n-1);

    return 0;
}
