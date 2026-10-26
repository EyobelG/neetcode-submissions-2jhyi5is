class Solution:
    def isHappy(self, n: int) -> bool:
        # Input is positive: sum(dig(n)))
        # loop until n == 1
        # If it stops at 1, return true, else false
        visited = set()

        while n != 1 and n not in visited:
            visited.add(n)
            n = sum(int(digit) ** 2 for digit in str(n))
        return n == 1

            
            



        