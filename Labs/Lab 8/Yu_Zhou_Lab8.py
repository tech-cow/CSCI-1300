class Parent_Car(object):
	#def __init__(self):
	#	pass

	def drive(self,velocity):
		distance = int(input("Distance = "))
		time = distance/velocity
		return time


class Ferrari(Parent_Car):

	def drive(self,velocity):
		distance = int(input("Distance = "))
		time = distance/velocity + 0.5
		return time


class Kia(Parent_Car):
	pass
	
    
ferrari = Ferrari()
ferrai_time = ferrari.drive(350)

kia = Kia()
kia_time = kia.drive(60)

print("Time taken by Ferrari is" , ferrai_time, "hours.")
print("Time of taken by Kia is", kia_time, "hours.")

if ferrai_time > kia_time:
	print("Ferrari is slower than Kia")
else:
	print("Ferrari is faster than Kia")