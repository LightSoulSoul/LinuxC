sum = 0

for x in xrange(1,1000001):
	numstr = str(x)
	for i in numstr:
		if i == '2':
			sum += 1
	x += 1

print sum