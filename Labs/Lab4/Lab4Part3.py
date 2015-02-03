my_strings = []

i = 0

while (i < 5):
	my_strings.append(input("String" + str(i+1) + ": "))
	i += 1
	#print(my_strings)

for i in my_strings:
	print(i.upper())