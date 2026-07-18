class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        state = [False] * 3
        for triplet in triplets:
            if (triplet[0] > target[0]) or (triplet[1] > target[1]) or (triplet[2] > target[2]):
                continue
            for i in range(3):
                if triplet[i] == target[i]:
                    state[i] = True
        return False not in state


"""
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastIndex = {}

        for i, c in enumerate(s):
            lastIndex[c] = i
        
        size, end = 0, 0
        res = []
        for i, c in enumerate(s):
            size += 1
            end = max(end, lastIndex[c])
            if i == end:
                res.append(size)
                size = 0
        return res

"""