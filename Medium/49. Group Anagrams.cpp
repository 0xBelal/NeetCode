#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:

        vector<vector<string>> groupAnagrams(vector<string>& strs) {

            vector<vector<string>> res;

            unordered_map<string, vector<string>> m;

            for (string s : strs) {
                vector<int> freq(26, 0);

                for (char c : s) {
                    freq[c - 'a']++;
                }

                string key = "";
                for (int count : freq) {
                    key += to_string(count) + "#";
                }

                m[key].push_back(s);
            }


            for(auto it : m){
                res.push_back(it.second);
            }


            return res;
        }


    /*vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        // sort the key for anageams words
        unordered_map<string,vector<string>> string_map;

        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            string_map[temp].push_back(s);
        }

        for(auto it : string_map){
            res.push_back(it.second);
        }
        return res;
    }*/
};