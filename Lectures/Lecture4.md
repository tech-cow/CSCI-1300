Simple while loop
-------------------
* Number Guessing

```python

inport random.randint(0, 100)
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

* Modular Looping

```python
counter = 0
while counter < 20:
    if counter % 3 == 0:
      print(counter, "Fizz")
    elif counter % 5 == 0:
      print(counter, "Buzz")
    counter += 1

    
```
