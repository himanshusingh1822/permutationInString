#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void r_r(string& s,int i, int j){
    char temp = s[j];
    for(int k=j;k>=i;k--){
        s[k]=s[k-1];
    }
    s[i]=temp;
}

void l_r(string& s,int i,int j){
    char temp = s[i];
    for(int k=i;k<=j;k++){
        s[k]=s[k+1];
    }
    s[j]=temp;
}

void permutation_string(string& s,int i){
    if(i==s.size()-1){
        cout << s << endl;
        return;
    }
    int freq[26]={0};
    for(int j=i;j<s.size();j++){
        if(freq[s[j]-'a']==0){
            swap(s[i],s[j]);
            permutation_string(s,i+1);
            swap(s[i],s[j]);
        }
        freq[s[j]-'a']++;
    }
}

void lexicographic_permutation_string(string& s,int i){
    if(i==s.size()-1){
        cout << s << endl;
        return;
    }
    int freq[26]={0};
    for(int j=i;j<s.size();j++){
        if(freq[s[j]-'a']==0){
            r_r(s,i,j);
            lexicographic_permutation_string(s,i+1);
            l_r(s,i,j);
        }
        freq[s[j]-'a']++;
    }
}

int main (){
    string s;
    cin >> s;
    permutation_string(s,0);
    return 0;
}