class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = {}
        maxCount = left = maxLength = 0

        for right in range(len(s)):
            counts[s[right]] = counts.get(s[right], 0) + 1
            maxCount = max(maxCount, counts[s[right]])

            while (right - left + 1) - maxCount > k:
                counts[s[left]] -= 1
                left += 1

            maxLength = max(maxLength, right - left + 1)
        return maxLength
        