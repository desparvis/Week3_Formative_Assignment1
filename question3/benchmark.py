import time
import stats       # Python version
import cstats      # C extension

arr = list(range(1, 10_000_001))

# Python version
start = time.time()
result_py = stats.sum_of_squares(arr)
end = time.time()
print("Python sum:", result_py)
print("Python time:", end - start)

# C extension version
start = time.time()
result_c = cstats.sum_of_squares(arr)
end = time.time()
print("C extension sum:", result_c)
print("C extension time:", end - start)