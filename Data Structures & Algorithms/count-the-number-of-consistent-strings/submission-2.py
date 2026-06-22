class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed_set = set(allowed)
        cons_count = 0

        for word in words:
            is_cons = True
            for char in word:
                if char not in allowed_set:
                    is_cons = False
                    break
            if is_cons:
                cons_count += 1
        return cons_count
        