answer = 0

def dfs(idx, now_cal, nums, key):
    global answer
    
    if idx < len(nums):
        dfs(idx + 1, now_cal + nums[idx], nums, key)
        dfs(idx + 1, now_cal - nums[idx], nums, key)
    else:
        if now_cal == key:
            answer += 1
    
def solution(numbers, target):
    global answer
    dfs(0, 0, numbers, target)
    return answer