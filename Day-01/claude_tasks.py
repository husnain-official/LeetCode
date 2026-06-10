#   Task-01
#   Find the largest element in an array
#   GFG basic · O(n) time, O(1) space
print("Task-01")
prime = [2,3,5,7]
largest = prime[0]
for i in range (len(prime)):
    if largest < prime[i]:
        largest = prime[i]
    
print(f"The largest element is: {largest}")
print(f"The largest element is: {max(prime)}") # Python way

#   Task-02
#   Second largest element (without sorting)
#   GFG · one-pass, track two variables ; O(n) time
print("\n\n\nTask-02")
prime = [2,3,5,7]
largest = second_largest = prime[0]
for i in range(len(prime)):
    if(largest < prime[i]):
        second_largest = largest
        largest = prime[i]
print(f"2nd Largest is: {second_largest}")
#   Python way
prime.sort()
print(f"2nd Largest is: {prime[-2]}")

#   Task-03
#   Check if array is sorted
#   LeetCode #1752 variant · single pass ; O(n) time
print("\n\n\nTask-03")
prime = [1,3,5,7]
sort = True
for i in range(len(prime)):
    if(i != len(prime)-1 and (prime[i] > prime[i+1])):
        sort = False

print(f"The array is sorted ? {sort}")
# Python way
print(f"The array is sorted ? {prime == sorted(prime)}")

#  Task-04
#    Remove duplicates from sorted array
#    LeetCode #26 · in-place, two pointers; O(n^2) time, Best case O(n), O(n) space
print("\n\n\nTask-04")
prime = [1,3,3,3,3,5,5,5,5,7,7,7,7,7,7]
unique_list = []
for i in range(len(prime)):
    unique = prime[i]
    if(unique in unique_list):
        continue
    else:
        unique_list.append(unique)

print(f"The unique list is: {unique_list}")
# Python way
print(f"The unique list is: {list(set(prime))}")
#    LeetCode #26 · in-place, two pointers;  O(n^2) time, Best case O(n), O(1) space
prime = [1,3,3,3,3,5,5,5,5,7,7,7,7,7,7]
slow_ptr = 0
unique = True
for fast_ptr in range(len(prime)):
    unique = True
    if(slow_ptr == 0):
        slow_ptr = slow_ptr+1
        continue
    # if(prime[fast_ptr-1] == prime[fast_ptr]):  # THis is for Sorted_lists
    #     continue
    for i in range (slow_ptr):                   # This is for Unsorted_lists  
        if(prime[i] == prime[fast_ptr]):
            unique = False                       # Using both is reduntant and will cause random skips of unique elements 
    if(unique):
        prime[slow_ptr] = prime[fast_ptr]
        slow_ptr = slow_ptr + 1            
print(f"The unique list is: {prime}")


print("\n\n\nTask-05")
