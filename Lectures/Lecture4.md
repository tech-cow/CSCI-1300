While Loop
-------------------
* **Number Guessing**

```python

import random.randint(0, 100)
print ("answer %d" % answer)

while true:
  guess = int(input("what is the number? "))
  if guess < answer:
    print("too low")

  elif guess > answer:
    print("too high")

  else: 
    print("omg you made it")
    break

```

********************

* **FizzBuzz**

```python
counter = 0
zz = ""

while counter < 20:
	#if counter % 3 == 0 and counter % 5 == 0:
	#	print("FizzBuzz")
	#	counter += 1
	#	continue

    if counter % 3 == 0:
    	zz = "fizz"

    if counter % 5 == 0:
      	zz += "buzz"

    if len(zz) > 0 :
    	print(counter, zz)
    	zz = ""
    counter += 1

    
```
