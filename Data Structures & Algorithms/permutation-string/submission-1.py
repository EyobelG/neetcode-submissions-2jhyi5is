class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        counts = [0] * 26
        left = matches = 0

        for i in range(len(s1)):
            counts[ord(s1[i]) - ord('a')] += 1
            counts[ord(s2[i]) - ord('a')] -= 1
        
        for i in range(26):
            if (counts[i] == 0):
                matches += 1
        
        if matches == 26:
            return True
        
        for right in range(len(s1), len(s2)):
            r_idx = ord(s2[right]) - ord('a')
            if (counts[r_idx] == 0):
                matches -= 1
            counts[r_idx] -= 1
            if (counts[r_idx] == 0):
                matches += 1
            
            l_idx = ord(s2[left]) - ord('a')
            if (counts[l_idx] == 0):
                matches -= 1
            counts[l_idx] += 1
            if (counts[l_idx] == 0):
                matches += 1
            left += 1

            if matches == 26:
                return True
            
        return False