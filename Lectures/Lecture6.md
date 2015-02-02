Google Search Algorithm
-----------------------

```python
#!/usr/local/bin/python3

import urllib.request

urls = [
"http://en.wikipedia.org/wiki/Batman",
"http://en.wikipedia.org/wiki/Superman",
"http://en.wikipedia.org/wiki/The_Joker_(The_Dark_Knight)"
]

keyword = "hero"

indexes = []

for url in urls: 
	print("url is",url)
	occurrences =[]
	indexes.append(occurrences)

	response = urllib.request.urlopen(url)
	print(response.getcode())

	body = str(response.read())

	#first search
	index = body.find(keyword)
	occurrences.append(index)

	# subsequent searches
	while index != -1 :
		index = body.find(keyword , index + 1)
		occurrences.append(index)

	print("indexes", indexes)
```

Improvement
------------

```python
#!/usr/local/bin/python3

import urllib.request

urls = [
"http://en.wikipedia.org/wiki/Batman",
"http://en.wikipedia.org/wiki/Superman",
"http://en.wikipedia.org/wiki/The_Joker_(The_Dark_Knight)"
]

keyword = "hero"
pages = []

for url in urls: 
	
	response = urllib.request.urlopen(url)
	#print(response.getcode())
	
	if response.getcode() !=200:
		print("FAILED")
		exit()

	body = str(response.read())
	pages.append(body)

#keyword search
	
indexes = []	
for page in pages:
	occurrences = []
	indexes.append(occurrences)


	index = body.find(keyword)
	occurrences.append(index)

	while index != -1 :
		index = body.find(keyword , index + 1)
		occurrences.append(index)

for found in indexes:
	print("what is found" , found)
	print("indexes",indexes)
	exit()


```
