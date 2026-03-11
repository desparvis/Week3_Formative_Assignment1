# stats.py
import time

def sum_of_squares(arr):
    total = 0
    for x in arr:
        total += x * x
    return total

# Generate large array
arr = list(range(1, 10_000_001))

# Measure performance
start = time.time()
result = sum_of_squares(arr)
end = time.time()

print("Sum of squares:", result)
print("Python version time:", end - start, "seconds")