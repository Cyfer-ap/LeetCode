class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Create a hash map to store the index of each number
        num_to_index = {}
        
        # Iterate through the list of numbers
        for i, num in enumerate(nums):
            complement = target - num
            
            # If the complement exists in the map, return the indices
            if complement in num_to_index:
                return [num_to_index[complement], i]
            
            # Otherwise, store the current number and its index
            num_to_index[num] = i