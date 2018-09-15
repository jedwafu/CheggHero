from __future__ import division
t=int(raw_input())
while t>0:
	eps=1e-12
	numbers=raw_input()
	numbers=numbers.split()
	n=int(numbers[0])
	m=int(numbers[1])
	p=int(numbers[2])
	k=int(numbers[3])
	if(p==0 or (n%2==0 and m%2==0)):
		print(1)
	elif(n%2==1 and m%2==1):
		print(0)
	else:
		term=1
		total=0
		while total< k and term > eps :
			term=term/2
			total=total+1
		partial=term
		for i in xrange((k)-1,(p)-1,-1):
			term=(term)*(i+1)
			term=term/(k-i)
			while total<k and term>eps :
				term=term/2
				total=total+1

			partial=(partial)+term


		ans=partial
		print(ans)

	t=t-1
