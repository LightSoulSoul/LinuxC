
s = open("shellcode6", "w")

#s.write(0xff *72 + '0804844c'.decode('hex'))

s.write('0xff'.decode('hex')*100)

s.close()
