import random
import math
total = 10000
count = 0
for t in range(total):
    x = random.random() * math.pi
    y = random.random()
    if math.sin(x) >= y:
        count += 1
print(math.pi * count / total)
