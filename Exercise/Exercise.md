
Exercise 8.1
---------

* **Write a function that takes a string as an argument and displays the letters backward, one per line.** 

```
annie = "a league character"

index = 0
while index < len(annie):
    letter = annie[-index-1]
    print (letter)
    index = index + 1

```

or 

```
annie = "a league character"

for i in range(len(annie)):
	back = annie[-i-1]
	print(back)
```

Exercise 8.2
----------

prefixes = 'JKLMNOPQ'
suffix = 'ack'
for letter in prefixes:
	if letter == 'O':
		print (letter + 'u' + suffix)

	elif letter == 'Q':
		print (letter + 'u' + suffix)

	else:
   		 print (letter + suffix)