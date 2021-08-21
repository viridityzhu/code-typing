# def largestCubeLE(k):
#     for n in range(1, k):
#         if n**3 > k:
#             print((n - 1)**3)
#             return
#     return 1

# largestCubeLE(10**5 + 1)


def threeSum(nums):
    n = len(nums)
    cnt = 0
    ans = []
    nums.sort()
    for i in range(n):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        target = 0 - nums[i]
        left, right = i + 1, n - 1
        while left < right:
            j = nums[left]
            k = nums[right]
            print(left, right, nums[i], j, k, target)
            cnt += 1
            if j + k < target:

                while left < right and nums[left] == nums[left + 1]:
                    print('left:', left)
                    left += 1
                left += 1
            elif j + k > target:
                while left < right and nums[right] == nums[right - 1]:
                    print('right', right)
                    right -= 1
                right -= 1

            else:  # j + k == target
                ans.append([nums[i], j, k])
                while left < right and nums[left] == nums[left + 1]:
                    print('left:', left)
                    left += 1
                left += 1
                while left < right and nums[right] == nums[right - 1]:
                    print('right', right)
                    right -= 1
                right -= 1
            if cnt > 1000:
                break
    return ans

s = [-2, 0, 0, 2, 2]
print(threeSum(s))
# 1 5
