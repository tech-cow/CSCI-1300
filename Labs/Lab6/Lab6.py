#Lab6: Files & functions
#Yu Zhou

def rating(completions, attempts, yards, touchdowns, interceptions):
    C = (completions / attempts - 0.30) * 5
    Y = (yards / attempts - 3) * 0.25
    T = touchdowns / attempts * 20
    I = 2.375 - (interceptions / attempts * 25)
    rating = (C + Y + T + I) / 6 * 100
    return rating
 
def clean(values):
    cleaned = []
    for field in values:
        cleaned.append(field.strip()) 
    return cleaned


def read_File(name):
	qbrc=0
	for record in open(name, "r"):
		fields = record.split(",")
		cleaned = clean(fields)
		name = cleaned[0]
		completions = int(cleaned[1])
		attempts = int(cleaned[2])
		yards = int(cleaned[3])
		touchdowns = int(cleaned[4])
		interceptions = int(cleaned[5])
		qbr = rating(completions, attempts, yards, touchdowns, interceptions)
		print("%s: %.2f" % (name, qbr))
		qbrc=qbrc+qbr
		write_File(qbrc)

def write_File(qbrc):
	myFileOut = open("my_output.txt", "w")
	myFileOut.write("Total Quarterback value is: \n")
	myFileOut.write("%.2f"%qbrc)
	myFileOut.close()
	
read_File("Ratings.csv")
