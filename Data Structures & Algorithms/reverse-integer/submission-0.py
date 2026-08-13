class Solution:
    def reverse(self, x: int) -> int:
        MAX_INT = 2**31 - 1
        MIN_INT = -2**31

        # Determine sign and work with absolute value
        sign = -1 if x < 0 else 1
        x = abs(x)

        res = 0
        while x != 0:
            pop = x % 10
            x //= 10

            # Overflow check before pushing the digit
            if res > MAX_INT // 10 or (res == MAX_INT // 10 and pop > 7):
                return 0

            res = res * 10 + pop

        res *= sign

        # Ensure final signed result fits within 32-bit bounds
        if res < MIN_INT or res > MAX_INT:
            return 0

        return res