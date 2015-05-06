
names_list = [
    "Romo",
    "McNabb",
    "Brady",
    "Manning",
    "Rodgers",
    "Brees",
    "Kaepernick",
    "Flacco"
]


def main():
	name_length(names_list)

def name_length(lists):
	print ("*".ljust(30,"*"))
	print ("Name                   Length")
	print ("*".ljust(30,"*"))
	
	for name in lists:
		lenth = len(name)
		print(name.ljust(10), (str(lenth)).rjust(17))
		#print((name.ljust(5)).ljust(len(name)))
		#print(len(name))
		#print(lists[name])

main()

