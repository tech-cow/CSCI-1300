
collection = "The quick brown fox jumped over the lazy dog."
for item in collection:
	print(item)



Mapping
----------

animals = ['panda','fox','dog','kangaroo']
destination = []
for animals in animals:
	destination.append(animals + ' is cute')

	print('original',animals)
	print('mapped',destination)
	print(len(animals), len(destination))

Accumulator
-------------
number = [1,2,3,4]
accumulator = 0
for number in number:
	accumulator += number

print('original',number)
print('sum',accumulator)