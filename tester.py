import random
import os
import math as m
from scipy.stats import linregress
import json
import subprocess

os.system("rm out.tmp ok.txt")
RERUN = True
x = [pow(3, i) for i in range(2, 7, 1)]
if (RERUN):
	os.system("rm test.json")
	results = dict()
	for size in x:
		results[size] = []
		print("Running for size "+str(size))
		for j in range(10):
			a = ""
			for i in range(size):
				tmp = random.randint(-2*size, 2*size)
				while (str(tmp) in a):
					tmp = random.randint(0, 2*size)
				a += str(tmp) + " "
			a = a[0:len(a)-1]
			os.system('ARG="'+str(a)+'"; ./push_swap $ARG > out.tmp; cat out.tmp | ./checker_Mac $ARG > ok.txt')
			with open("ok.txt", "r") as f:
				ok = f.readlines()
				if not ok:
					print("ERROR ! checker produced not output")
				ok = ok[-1]
				if (ok != "OK\n"):
					print(ok)
					print("Failed with input :")
					print(a)
					quit()
				else:
					print("OK !")
			with open("out.tmp", "r") as f:
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
slopes = []
slope, intercept, r_value, p_value, std_err = linregress(x1, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x2, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x3, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x4, y1)
r_values.append(r_value)
slopes.append(slope)

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
			bestslope = slope
	print("Your program time complexity is O(n) = "+str(round(bestslope))+"*n^"+str(exponent)+" with an R^2 of "+str(r_values[3]))
elif  r_values[1] == max(r_values):
	print("Your program time complexity is O(n) = "+str(round(slopes[1]))+"*log(n) with an R^2 of "+str(r_values[1]))
elif  r_values[2] == max(r_values):
	print("Your program time complexity is O(n) = "+str(round(slopes[2]))+"*nlog(n) with an R^2 of "+str(r_values[2]))
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
			bestslope = slope
	print("Your program time complexity is O(n) = "+str(round(bestslope))+"*n^"+str(exponent)+" with an R^2 of "+str(r_values[3]))