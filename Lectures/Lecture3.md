Lecture 3: Variables, Operators, Data Types
----------------------------------------------

Sum of Numbers
-----------------
* binary operator : +, *, / etc
* unary operator : -(negative) , not(! in python) , ++ etc.

```python

x = 12   // "=" is an assignment operater (binary operater with left hand side and right)

x = x + 23 || x += 23 // Python perform the right hand side first, then assign it to x on the left

print (x) 

//35

```
String Concatenation
---------------------

```python

a = "hello"
b = "world"

c = a + b

print(c) 

// hello world

```



Mixture
----------
* Python is a strongly typed language (when adding 2 different data types, it throws error)
In weakly typed language, one type of coorprate with another (ex: Javascript)
Reasons there are different rules in language is because languages are design to suit different purpose. Python
is often used in server, and it's need to be ruled carefully.
* In python, to make types coorprate, we use **casting**

```python

x = 12
a = "hello"
b = "world"

print(str(x) + a)

// "12hello"

```

Division of Numbers
--------------------

```python

x = 1
y = 3
print(x/y)

//0


```

Static Type vs Dynamic Type
-------------------------------
Static type: **C** -always have to initiate a type
Dynamic type: **Python** , you don't need to initiate a type, the language will figure the type system at runtime.

Dynamic in use
----------------
*Assignment are also tested at runtime

```python
myString = "lalala"
myNumber = 1

myNumber = myString
print(myNumber)

// lalala
```

Array
-------
```python
items = [1 , 2 , 3, 4]
names = ["ralphie", "chauncey"]

print(items[0]) // prints the index 0 from the array

// 1
```

Practice : Area
-----------------
```python
import math

radius = 10
pi = math.pi //

area = radius **2 * pi
circ = 2 * pi * radius

print 'the area is :' , area
print 'the circumference is' , circ
```


