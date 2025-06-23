//
// Created by Belal on 28-Apr-25.
//
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char,int> freq;
        for(char &c:t) freq[c]++;

        for( char c : s ){

            if(freq[c] != 0 )freq[c]--;
            else return false;

        }

        return true;
    }
};