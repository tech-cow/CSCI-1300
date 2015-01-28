#!/usr/bin/env python
# -*- coding: utf-8 -*- 
# Problem 1
# Yu Zhou
# TA: Srinjita Bhaduri


Pass_completions = input ("Pass completions: ")
Pass_attempts = input ("Pass attempts: ")
Total_passing_yards = input ("Total passing yards: ")
Touchdowns = input ("Touchdowns!? : ")
Interceptions = input ("Interceptions: ")



C = ((Pass_completions / Pass_attempts) - 0.30) * 5
Y = (Total_passing_yards /Pass_attempts - 3) * 0.25
T = Touchdowns / Pass_attempts * 20
I = 2.375 - (Interceptions / Pass_attempts * 25)
PasserRating = (C+Y+T+I)/6*100

print PasserRating

#Comment:
# utf-8 from the top comment solves the issue of Non-ASCII character calculation
# 5 arguments were grab from user
# C Y T I calculate for necessary entry
# Then PasserRating calculate the rate