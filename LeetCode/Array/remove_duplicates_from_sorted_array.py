# # -*- coding: utf-8 -*-

# Time:  O(n)
# Space: O(1)
#
# Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
# Do not allocate extra space for another array, you must do this in place with constant memory.
# 
# For example,
# Given input array A = [1,1,2],
# Your function should return length = 2, and A is now [1,2].
# 
# 思路
# 逆向思维，删除不重复元素，也就是找unique elements，并一个一个插入到数组最前面
# 插入的indexing label使用新建的index，与原数组的label比较
# 

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        index = 0
        for i in range(1, len(nums)):
            if nums[index] != nums[i]:
                index += 1
                nums[index] = nums[i]
            
        return index + 1
