#include <bits/stdc++.h>
using namespace std;

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

    int minn = INT_MAX;
    for(int k=i; k<j; k++){
        int temp = PP(s,i,k) + PP(s,k+1,j) + 1;
        minn = min(temp,minn);
    }
    return minn;
}

int main(){
    string s; cin >> s;
    cout << PP(s,0,s.size()-1);
    return 0;
}
