# Problem 4
# Yu Zhou
# TA: Srinjita Bhaduri


# paper thickness: 1/200 cm
# input of folds
# print thickness

paper_thickness = 1.0/200
folds_input = input("How many times are you willing to torture the paper? ")
i = 0
#new_paper_thickness = 0
while i < folds_input :
	paper_thickness = float(paper_thickness) * 2
	new_paper_thickness = paper_thickness
	i += 1
print (new_paper_thickness)

#comments
# a simple while loop that increment the current value * 2 