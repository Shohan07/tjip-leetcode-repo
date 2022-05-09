//TC : O(NK) where N is the length of strs, and K is the maximum length of a string in strs
//SC : O(NK)
class Solution {
public:
    unsigned long long getHash(string &str){
        unsigned long long h = 1;
        for(auto c : str){
            h = (h * (257 + (c - 'a')));
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unsigned long long, vector<string>> buckets;
        for(auto str : strs){
            buckets[getHash(str)].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(auto &item : buckets){
            anagrams.push_back(item.second);
        }
        return anagrams;
    }
};

 
..............................................................................................................

//TC : O(NKLOGK) where N is the length of strs, and KK is the maximum length of a string in strs
//SC : O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for(auto &str : strs){
            auto key = str;
            sort(key.begin(), key.end());
            buckets[key].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(auto &item : buckets){
            anagrams.push_back(item.second);
        }
        return anagrams;
    }
};

 