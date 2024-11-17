import random

size = int(input("size ?"))
a = ""
for i in range(size):
	tmp = random.randint(-2*size, 2*size)
	while (str(tmp) in a):
		tmp = random.randint(0, 2*size)
	a += str(tmp) + " "
a = a[0:len(a)-1]
print(a)