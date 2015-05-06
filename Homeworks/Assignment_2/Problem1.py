import math

PV = float(input("Enter PV (Initial Investment in cash): "))
n =  int(input("Enter n (Number of years): "))
i =  float(input("Enter i (Annual interest rate in decimal): "))

#FV = PV * ((1+i)**n)
FV = PV * pow(1+i,n)
print "The future value of your investment will be" , int(FV) , "in cash" 