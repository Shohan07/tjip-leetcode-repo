//TC : O(n + m * mxlen(m) * log(n)) where O(n) for building map + O(no.of words * max len of word * finding position with upper_bound) 
//SC : O(257)
class Solution {
public:
    bool isSubSeq(string word, vector<vector<int>>& freq){
        int prevPos = - 1;
        for(auto &ch : word){
            auto nextPos = upper_bound(freq[ch].begin(), freq[ch].end(), prevPos);
            if(nextPos == freq[ch].end()) return false;
            prevPos = *nextPos;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>freq(257, vector<int>());
        int noSubSeq = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]].push_back(i);
        }
        for(auto &word : words){
            noSubSeq += isSubSeq(word, freq);
        }
        return noSubSeq;
    }
};