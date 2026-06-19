class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        car = {}
        stack = []
        for i in range(len(position)):
            car[position[i]] = speed[i]
        position.sort(reverse = True)
        for i in range(len(position)):
            p = position[i]
            s = car[p]
            
            time = float(target - p) / float(s)
            if not stack or time > stack[-1]:
                stack.append(time)
        return len(stack)
        