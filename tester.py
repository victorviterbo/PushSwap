import random
import os
import matplotlib.pyplot as plt
import math as m
from scipy.stats import linregress
import json

RERUN = False
x = [pow(3, i) for i in range(3, 8, 2)]
xstr = [str(i) for i in x]
if (RERUN):
	results = dict()
	for size in x:
		results[size] = []
		print("Running for size "+str(size))
		for j in range(10):
			a = ""
			for i in range(size):
				a += str(random.randint(0, 2*size)) + " "
			ret = os.system("./push_swap " + a + " > tmp.out")
			assert ret
			with open("tmp.out", "r") as f:
				n = len(f.readlines())
			results[size].append(n)
	with open("test.json", "w") as json_file:
		json.dump(results, json_file, indent=4)

with open("test.json", "r") as json_file:
	results = json.load(json_file)

y1 = []
for size in xstr:
	y1.append(sum(results[size]) / len(results[size]))
x1 = x
x2 = [m.log(i) for i in x]
x3 = [i * m.log(i) for i in x]
x4 = [i * i for i in x]

r_values = []

slope, intercept, r_value, p_value, std_err = linregress(x1, y1)
r_values = [r_value]
print(slope, intercept, r_value, p_value, std_err)
slope, intercept, r_value, p_value, std_err = linregress(x2, y1)
r_values.append(r_value)
print(slope, intercept, r_value, p_value, std_err)
slope, intercept, r_value, p_value, std_err = linregress(x3, y1)
r_values.append(r_value)
print(slope, intercept, r_value, p_value, std_err)
slope, intercept, r_value, p_value, std_err = linregress(x4, y1)
r_values.append(r_value)
print(slope, intercept, r_value, p_value, std_err)

if r_values[0] == max(r_values):
	print("Your program time complexity is O(n) = n with an R^2 of "+str(r_values[0]))
elif  r_values[1] == max(r_values):
	print("Your program time complexity is O(n) = log(n) with an R^2 of "+str(r_values[1]))
elif  r_values[2] == max(r_values):
	print("Your program time complexity is O(n) = nlog(n) with an R^2 of "+str(r_values[2]))
elif  r_values[3] == max(r_values):
	print("Your program time complexity is O(n) = n^2 with an R^2 of "+str(r_values[3]))