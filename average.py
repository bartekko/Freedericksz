from sys import argv

avg=0.0
count=0
with open(argv[1]) as data:
	count+=1
	avg+=float(data.readline())
	
avg/=count
print(avg);
	
