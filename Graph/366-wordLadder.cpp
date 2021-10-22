#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();

        unordered_set<string> words;

        for (auto i : wordList)
            words.insert(i);

        if (words.find(endWord) == words.end())
            return 0;
        int len = 0;

        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
        {
            len++;
            int qlen = q.size();
            while (qlen--)
            {
                string s = q.front();
                q.pop();
                for (int i = 0; i < s.length(); i++)
                {
                    char ch = s[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if (s == endWord)
                            return len + 1;
                        if (words.find(s) == words.end())
                            continue;

                        words.erase(s);
                        q.push(s);
                    }
                    s[i] = ch;
                }
            }
        }

        return 0;
    }
};

/*
class Solution {
public:
    
    int getDiff(string a, string b){
        int ans = 0;
        int i = 0;
        while(i < a.length()){
            if(a[i] != b[i])
                ans++;
            i++;
        }
        return ans;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int found = 0;
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord){
                found = 1;
                break;
            }
        }
        if(!found) return 0;
        
        if(beginWord == endWord) return 1;
        
        vector<vector<int>> grp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and getDiff(wordList[i], wordList[j]) == 1){
                    grp[i].push_back(j);
                }
            }
        }
        
        queue<pair<int, int>>q;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(getDiff(beginWord, wordList[i]) == 1){
                q.push({i, 2});
                vis[i] = 1;
            }
        }
        
        int curr;
        int wordCount = 1;
        while(!q.empty()){
            curr = q.front().first;
            wordCount = q.front().second;
            q.pop();
            if(wordList[curr] == endWord)
                break;
            
            for(auto i: grp[curr]){
                if(!vis[i] and getDiff(wordList[curr], wordList[i]) == 1){
                    vis[i] = 1;
                    q.push({i, wordCount+1});
                }
            }
        }
        return wordCount;
    }
};
*/