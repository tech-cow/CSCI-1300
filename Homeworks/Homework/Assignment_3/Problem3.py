# Problem 3
# Yu Zhou
# TA: Srinjita Bhaduri

seconds = input("Enter the seconds: ")

#remain_minutes
#hours = seconds / 60 / 60
#minute = 
#remain_minutes = ((hours - int(hours) * hours ) / 60
#remain_minutes = (seconds % 60) - (hours * 60)
#remain_minutes = 
#remain_minutes = (seconds / 60) 
#print int(hours)
minute = seconds / 60;
hours = minute / 60
minute_reminder = minute - hours * 60
seconds_reminder = seconds % 60

print "The time is ",hours, " hours,",minute_reminder," minutes,",seconds_reminder," seconds"

