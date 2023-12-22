marksheet_length=int(input("Enter no. of students: "))
marksheet=[]

for i in range(0, marksheet_length):
    el = input("Enter marks or ab for absent: ")
    if (el != 'ab'):
        el = int(el)
    marksheet.append(el)

print("The entries are: ", marksheet)

# MAIN FUNCTION

flag = 1

def askcontinue():
    cont = input("Do you want to continue using the program? (yes/no): ")
    if (cont == "yes"):
        return True
    else:
        return False
        
# LIST WITHOUT STRING
filteredlist = []
for i in marksheet:
    if(i != 'ab'):
        filteredlist.append(i)
    
def Average():
    total = 0
    length = 0
    for i in filteredlist:
        total += i
        length += 1
    return total/length
    
def MaxMarks():
    ref = filteredlist[0]
    for i in filteredlist:
        if ref < i:
            ref = i
    return ref
    
def MinMarks():
    ref = filteredlist[0]
    for i in filteredlist:
        if ref > i:
            ref = i
    return ref

def AbsentCount():
    count = 0
    for i in marksheet:
        if(i == "ab"):
            count += 1
    return count

def MarksFrequency():
    freq = [None]*len(filteredlist)
    for i in range(0, len(filteredlist)):
        currentfreq = 0
        for j in filteredlist:
            if filteredlist[i] == j:
                currentfreq+=1
        freq[i] = (currentfreq)
    print("The marks frequencies are", freq)

    max_freq = 0
    max_freq_index = 0
    for i in range(0, len(filteredlist)):
        if max_freq <= freq[i]:
            max_freq = freq[i]
            max_freq_index = i
    print("Maximum frequency is", max_freq, "for the score of", filteredlist[max_freq_index])
        


while(flag == 1):
    print("Available optons; \n1: Average score \n2: Highest and Lowest score \n3: Count of absent students \n4: Display marks with highest frequency \n")
    choice = int(input("Enter your choice: "))
    
    if (choice == 1):
        print("Average mark is", Average())
        flag = 1 if askcontinue() else 0
    elif (choice == 2):
        print("Max is", MaxMarks(), "and Min is", MinMarks())
        flag = 1 if askcontinue() else 0
    elif (choice == 3):
        print("There is/are", AbsentCount(), "absent students")
        flag = 1 if askcontinue() else 0
    elif (choice == 4):
        print("freq")
        MarksFrequency()
        flag = 1 if askcontinue() else 0
    else:
        print("INVALID CHOICE")
        flag = 1 if askcontinue() else 0
        
       