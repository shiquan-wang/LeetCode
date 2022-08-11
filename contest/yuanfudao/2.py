from itertools import starmap


nums = list(map(int, input().strip().split()))
n, k = nums[0], nums[1]
seq = list(map(int, input().strip().split()))

stack = []
t = 0
i = 0
while i < n:
    cur_a = seq[i]
    if cur_a > 0:
        if len(stack) == 0 or stack[-1] != cur_a:
            stack.append(cur_a)
        else:
            stack = stack[:-1]
    else:
        if len(stack)==0 or stack[-1] == 0:
            stack.append(cur_a)
        else:
            if i < n//2:
                stack.append(cur_a)
            else:
                stack = stack[:-1]
    i += 1
print(stack)
if len(stack) < n:
    t += 1
t += (len(stack) // 2) * k
print(t)