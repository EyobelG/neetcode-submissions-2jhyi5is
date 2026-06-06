class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        
        # If the total sum is odd, we can never split it evenly
        if total_sum % 2 != 0:
            return False
            
        target = total_sum // 2
        
        # A set to store all unique sums we can generate so far
        # We start with 0 because an empty subset has a sum of 0
        dp = {0}
        
        for num in nums:
            # We must iterate over a copy or new set to avoid changing 
            # the set size while looping through it
            next_dp = set(dp)
            
            for current_sum in dp:
                new_sum = current_sum + num
                
                # Early Exit: If we hit the target, we are done immediately
                if new_sum == target:
                    return True
                    
                # Only add to the set if it doesn't exceed our target
                if new_sum < target:
                    next_dp.add(new_sum)
            
            dp = next_dp
            
        return False