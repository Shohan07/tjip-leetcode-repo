// TC : O(10n) = O(n)
// SC : O(n)
class Solution {
public:
    int calcScore(string &ref, string &cand){
        int res = 0;
        for(int i = 0; i < ref.size(); i++){
            res += ref[i] == cand[i];
        }
        return res;
    }
        
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(wordlist.size() > 1){
            int rdx = rand() % wordlist.size();
            string querryString = wordlist[rdx];
            int score = master.guess(querryString);
            
            vector<string> newlist;
            for(auto &w : wordlist){
                if(calcScore(querryString, w) == score){
                    newlist.push_back(w);
                }
            }
            wordlist = newlist;
        }
        master.guess(wordlist[0]);
    }
};