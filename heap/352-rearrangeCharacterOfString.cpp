/*
Rearrange characters in a string such that no two adjacent are same

    Difficulty Level : Hard
    Last Updated : 28 Jun, 2021

Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
Examples: 
 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible
*/

/*

*/

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    if (s.length() == 0)
        return s;

    int n = s.length();
    int maxPossible = n / 2 + n % 2;
    string res = "";
    map<char, int> mp;

    // store the freq for each character in map
    for (auto i : s)
    {
        mp[i]++;
        if (mp[i] > maxPossible)
            return "";
    }

    priority_queue<pair<int, char>> pq;

    // push (freq, char) pair in heap
    for (auto i : mp)
        pq.push({i.second, i.first});

    // now extract char having highest freq and add it to res and decrement its freq
    // don't store it right now. Now pop next pair from heap and add it to res if its character is not equal to previous pairs character  else return empty string
    //now push previously stored pair if its freq is greater than 0 (first decrement it by one)
    // and store current pair as a previous pair for next iteration
    // repeat same procedure till heap is not empty
    int prevFreq = pq.top().first;
    char prevCh = pq.top().second;
    pq.pop();
    prevFreq--;
    res += prevCh;

    while (!pq.empty())
    {
        int nextFreq = pq.top().first;
        char nextCh = pq.top().second;
        pq.pop();

        if (prevCh == nextCh)
            return "";

        res += nextCh;
        if (prevFreq > 0)
            pq.push({prevFreq, prevCh});

        prevCh = nextCh;
        prevFreq = nextFreq - 1;
    }

    return res;
}
int main()
{
    string str;
    cin >> str;

    cout << reorganizeString(str) << endl;

    return 0;
}