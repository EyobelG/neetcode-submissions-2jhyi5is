class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        // WIZARD
        // Whole Check, Inventory, Assemble, Repeat and Reduce, Done

        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map <int, int> freq;
        sort(hand.begin(), hand.end());

        for (int card : hand) {
            freq[card]++;
        }

        for (int card: hand) {
            if (freq[card] == 0) continue;

            for (int i = 0; i < groupSize; i++) {
                int current = card + i;

                if (freq[current] == 0) {
                    return false;
                    
                }
                freq[current]--;
               
            }
        
         
        }
        return true;
        
    }
};
