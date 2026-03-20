#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char originalChar = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = originalChar;
            }

        }
        return 0;
    }
};

int main(){
    string beginWord,endWord;
    cin>>beginWord>>endWord;
    int n;
    cin>>n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++){
        cin>>wordList[i];
    }
    Solution sol;
    cout<<sol.ladderLength(beginWord,endWord,wordList)<<endl;
}