import random
import os
import matplotlib.pyplot as plt
import math as m
from scipy.stats import linregress

results = dict()
x = [pow(3, i) for i in range(4, 9)]
#for size in x:
for size in [7]:
	results[size] = []
	print("Running for size "+str(size))
	for j in range(10):
		a = ""
		for i in range(size):
			a += str(random.randint(0, 2*size)) + " "
		ret = os.system("./push_swap " + a) # + " > tmp.txt"
		assert ret
		#print("./push_swap " + a + "| ./checker_Mac " + str(a))
		#os.system("./push_swap " + a + "| ./checker_Mac " + str(a))
		#with open("COK.txt", "r") as f:
		#	assert f.readlines()[0] == "OK"
		with open("tmp.txt", "r") as f:
			n = len(f.readlines())
		results[size].append(n)

y1 = []
for size in x:
	y1.append(sum(results[size]) / len(results[size]))
y2 = [m.log(i) for i in y1]
y3 = [i * m.log(i) for i in y1]
y4 = [i * m.log(i) for i in y1]

r_values = []

slope, intercept, r_value, p_value, std_err = linregress(x, y1)
r_values = [r_value]
slope, intercept, r_value, p_value, std_err = linregress(x, y2)
r_values = [r_value]
slope, intercept, r_value, p_value, std_err = linregress(x, y3)
r_values = [r_value]
slope, intercept, r_value, p_value, std_err = linregress(x, y4)
r_values = [r_value]

if r_values[0] == min(r_values):
	print("Your program time complexity is O(n) = n with an R^2 of "+str(r_values[0]))
elif  r_values[1] == min(r_values):
	print("Your program time complexity is O(n) = log(n) with an R^2 of "+str(r_values[1]))
elif  r_values[2] == min(r_values):
	print("Your program time complexity is O(n) = nlog(n) with an R^2 of "+str(r_values[2]))
elif  r_values[3] == min(r_values):
	print("Your program time complexity is O(n) = n^2 with an R^2 of "+str(r_values[3]))