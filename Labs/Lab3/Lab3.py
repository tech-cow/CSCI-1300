#	Write a program to take user input and use if, else, and elif conditionals.

#For this lab exercise, you are going to write a program to prompt 
#the user for the height of a mountain in feet (ft). Name your program Lab3.py

height = input("Enter the Mountain's Height: ")

if height == 28169 :
	print height , "ft is the height of Kangchenjunga and is the third highest mountain."

elif height == 28251 :
	print height , "ft is the height of K2 and is the second highest mountain."

elif height == 29029 :
	print height , "ft is the height of Mount Everest and is the first highest mountain."

else :
	print "Height does not match that of the first three highest mountains. Please enter a correct height!!"
 
