class Solution {
public:
    int numRabbits(vector<int>& answer) {
        
        // in this we asking to rabbits as how many there are others rabiit are thre they say answer[i] excluing them ,,

        unordered_map<int,int>mp ;

        for (int i = 0 ; i<answer.size() ; i++){
            mp[answer[i]]++ ; 
        }
            int total = 0;
        for (auto [x, freq] : mp) {
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize;  // ceil(freq / groupSize)
            total += groups * groupSize;
        }

        return total;
    }
};