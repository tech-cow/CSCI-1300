import math

#Devner ----> Boulder to be a good professor!

# round trip 70 miles
# 1 gallon = 13 miles = $2

round_trip_miles = 70
miles_per_gallon = 13
dollar_per_gallon = 2

cost_of_round_trip = round_trip_miles / float(miles_per_gallon) * dollar_per_gallon
print "The cost of a round trip is: ", cost_of_round_trip

cost_the_month = cost_of_round_trip * 30
print "Asumming 30 days a month, the monthly cost is: " , cost_the_month

cost_the_year = cost_of_round_trip * 365
print " the cost of the year is : " , cost_the_year