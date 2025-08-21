def solution(nums):
    max_num = int(len(nums) / 2)
    return min(len(set(nums)), max_num)