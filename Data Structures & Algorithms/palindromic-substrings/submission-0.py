class Solution:
    def countSubstrings(self, s: str) -> int:
        total = 0
        def expandCenter(left: int, right: int) -> int:
            count = 0
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                count += 1
                left -= 1
                right += 1
            return count
        
        for i in range(len(s)):
            # Even-length palindromes
            total += expandCenter(i, i)

            # Odd-length palindromes
            total += expandCenter(i, i + 1)

        return total
            




        