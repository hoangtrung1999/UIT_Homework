import string

A = dict()
# a -> z
for i in range (97,123):
	A.setdefault (str(chr(i)), 0)
# A -> Z
for i in range (65, 91):
	A.setdefault(str(chr(i)), 0)
# the dot
A.setdefault (str(chr(46)),0)
# the comma
A.setdefault (str(chr(44)),0)
# work with file
f = open("Test_Case.txt")
data = f.read()
f.close()
#loop through all words
numSpace = -1
if (f.mode == 'r'):
	words = str.split(data)
	for word in words:
		for i in range (len(word)):
			if word[i] in A:
				A[word[i]] = A[word[i]] + 1
		numSpace += 1
# the space
A.setdefault (str(chr(32)),0)
# the line feed
A.setdefault (str(chr(10)),0)
A[" "] = numSpace
A['\n'] = data.count('\n')

#remove those words that not in the input file
for key in list(A):
	if (A[key] == 0):
		del A[key]

o = open ("Freq.txt","w+")
o.write(str(len(A)) + "\n")
for key,val in A.items():
	string = str(key) + ' ' + str(val)
	o.write (string + "\n")
o.close()
