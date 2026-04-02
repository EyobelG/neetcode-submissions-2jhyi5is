class Solution {
public:
   int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        if (n & 0x80000000u) ++count; // check the current MSB
        n <<= 1;                     // shift left to bring next bit into MSB
    }
    return count;
}
};
