humanDNA = list(open("humanDNA.txt","r").read())
mouseDNA = list(open("mouseDNA.txt","r").read())
unknownDNA = list(open("unknownDNA.txt","r").read())


def hamming_distance(str1, str2):
	counter = 0
	
	if len(str1) != len(str2):
		print("length not equal")
	
	else:
		for i in range(len(str1)):
			if str1[i] != str2[i]:
				counter += 1
		return counter


def main():
	mouse_similarity_score = (len(mouseDNA)-hamming_distance(mouseDNA, unknownDNA)) /len(mouseDNA)
	human_similarity_score = (len(humanDNA)-hamming_distance(humanDNA, unknownDNA)) /len(humanDNA)
	print("MouseCompare = ", mouse_similarity_score)
	print("HumanCompare = ", human_similarity_score)

	if mouse_similarity_score <= 0.00001 and human_similarity_score <= 0.00001:
		print("identity cannot be determined”")
	elif human_similarity_score <= 0.00001:
		print("human")
	elif mouse_similarity_score <= 0.00001:
		print("mouse")
	else:
		print("what the hell is this")


main()