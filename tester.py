import random
import os
import matplotlib.pyplot as plt
import math as m

results = dict()
x = [10, 50, 100, 500, 1000]
for size in x:
	results[size] = []
	for j in range(5):
		a = ""
		for i in range(size):
			a += str(random.randint(0, 2*size)) + " "

		os.system("./push_swap " + a + ">tmp.txt")

		with open("tmp.txt", "r") as f:
			n = len(f.readlines())
		print("solved in "+str(n)+"operations for input of size" +str(size))
		results[size].append(n)

y1 = []
for size in x:
	y1.append(sum(results[size]) / len(results[size]))
print("HELLO?")
plt.plot(x, y1, label='O(n) = n')
plt.show()
y2 = [m.log(i) for i in y1]
plt.plot(x, y2, label='O(n) = log(n)')
plt.show()
y3 = [i * m.log(i) for i in y1]
plt.plot(x, y3, label='O(n) = nlog(n)')
plt.show()
y4 = [i * m.log(i) for i in y1]
plt.plot(x, y4, label='O(n) = n^2')
plt.show()