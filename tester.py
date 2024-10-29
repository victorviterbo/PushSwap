import random
import os
import matplotlib.pyplot as plt
import math as m
from scipy.stats import linregress
import json
import numpy as np
import subprocess

RERUN = True
x = input("enter number of elements to be sorted")
try:
    x = [int(x)]
except (ValueError, TypeError):
    x = [pow(3, i) for i in range(4, 8, 1)]

if (RERUN):
	results = dict()
	for size in x:
		results[size] = []
		print("Running for size "+str(size))
		for j in range(5):
			a = ""
			for i in range(size):
				tmp = random.randint(-2*size, 2*size)
				while (str(tmp) in a):
					tmp = random.randint(-2*size, 2*size)
				a += str(tmp) + " "
			a = a[0:len(a)-1]
			ret = os.system('ARG="'+str(a)+'"')
			print('ARG="'+str(a)+'"')
			assert not ret
			result = subprocess.run(["push_swap", "$ARG", "|", "./checker_Mac", "$ARG"], capture_output=True, text=True)
			print(result.stdout)
			os.system("./push_swap $ARG | ./checker_Mac $ARG > aa")
			print("./push_swap $ARG | ./checker_Mac $ARG > aa")
			print(ret)
			with open("tmp.out", "r") as f:
				n = len(f.readlines())
			results[size].append(n)
	with open("test.json", "w") as json_file:
		json.dump(results, json_file, indent=4)

with open("test.json", "r") as json_file:
	results = json.load(json_file)

x = [int(i) for i in results.keys()]
xstr = results.keys()
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
	best_fit = 0
	best_R = 0
	for exponent in np.arange(0.5, 1.5, 0.1):
		exp = round(exponent, 1)
		x_n = [pow(i, exp) for i in x]
		slope, intercept, r_value, p_value, std_err = linregress(x_n, y1)
		if best_R < r_value:
			best_fit = exp
			best_R = r_value
	print("Your program time complexity is O(n) = n^"+str(exponent)+" with an R^2 of "+str(r_values[3]))
elif  r_values[1] == max(r_values):
	print("Your program time complexity is O(n) = log(n) with an R^2 of "+str(r_values[1]))
elif  r_values[2] == max(r_values):
	print("Your program time complexity is O(n) = nlog(n) with an R^2 of "+str(r_values[2]))
elif  r_values[3] == max(r_values):
	best_fit = 0
	best_R = 0
	for exponent in np.arange(1.5, 2.5, 0.1):
		exp = round(exponent, 1)
		x_n = [pow(i, exp) for i in x]
		slope, intercept, r_value, p_value, std_err = linregress(x_n, y1)
		if best_R < r_value:
			best_fit = exp
			best_R = r_value
	print("Your program time complexity is O(n) = n^"+str(exponent)+" with an R^2 of "+str(r_values[3]))