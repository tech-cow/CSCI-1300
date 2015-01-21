import math

# birth every 7 seconds
# death every 13 seconds
# immigrant every 35 seconds
#CONST_

current_pop = 330357870
year_to_secs = 365 * 24 * 60 * 60
birth = int(year_to_secs / 7)
death = int(year_to_secs / 13)
immigrant = int(year_to_secs / 35)

future_pop = int(current_pop + birth + immigrant - death)

print "The population will be", future_pop