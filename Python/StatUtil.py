def calculate_mean(nums):
    N = len(nums)
    
    if not len(nums):
        return
    total = 0.0
    for num in nums:
        total = total + num
    
    mean = float(total) / N
    return mean

def calculate_median(nums):
    N = len(nums)

    if not N:
        return

    nums.sort()
    
    median = None
    if N % 2 == 0:
        a = int(N / 2 - 1)
        b = int(N / 2)
        median = (nums[a] + nums[b]) / 2.0
    else:
        median = float(nums[int(N/2)])
    return median


if __name__ == "__main__":
    elems = input("Enter numbers: ").strip()
    nums = [ int(elem) for elem in elems.split() ]
    
    mean = calculate_mean(nums)
    median = calculate_median(nums)
    
    if mean:
        print("Mean is:   %.1f" % mean)
    
    if median:
        print("Median is: %.1f" % median)
        
    print("Done")
    