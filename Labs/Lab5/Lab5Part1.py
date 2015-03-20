DNA = "ACTZATZCTAZZZACCAZ"
DNA1 = ""

for i in range(len(DNA)):
	if DNA[i] != "Z":
		DNA1 = DNA[i] + DNA1
	else:
		continue
print(DNA1)
