# Lab 2 Calculations
# Author: Yu Zhou
# Date: 1/20/2015

sales_tax = .13
num_items = 2
total_price = 1999.915
cost_per_item = (total_price - sales_tax*num_items) / num_items
print "The cost of each 2 item is $%.2f" % cost_per_item