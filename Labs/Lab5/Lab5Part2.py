myString = "Hi, my name is FirstName LastName."
print("The starting index of name is:" , myString.index('n'))
print ((myString.replace("FirstName", "Yu")).replace("LastName","Zhou"))

new_list = myString.split(" ")
for words in new_list:
	print(words.lower())

