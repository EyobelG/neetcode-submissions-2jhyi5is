class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 32-bit mask to handle Python's infinite precision
        mask = 0xFFFFFFFF
        
        while b:
            # Calculate the carry, but keep it within 32 bits
            tmp = ((a & b) << 1) & mask
            # Sum without carry, kept within 32 bits
            a = (a ^ b) & mask
            b = tmp
            
        # If 'a' is a negative number in 32-bit signed format, 
        # convert it back to a Python negative integer.
        return a if a <= 0x7FFFFFFF else ~(a ^ mask)