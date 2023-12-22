totalnum = int(input("Enter total no. of students: "))
secomp = []
for i in range(0, totalnum):
    el = input("Enter student name: ")
    secomp.append(el)
print("The list of all students is: ", str(secomp))
# GROUP A
group_a_num = int(input("Enter no. of students in group A (Cricket): "))
group_a = []
for i in range(0, group_a_num):
    el = input("Enter student name: ")
    group_a.append(el)
print("The list of students in group A: ", str(group_a))
# GROUP B
group_b_num = int(input("Enter no. of students in group B (Badminton): "))
group_b = []
for i in range(0, group_b_num):
    el = input("Enter student name: ")
    group_b.append(el)
print("The list of students in group B: ", str(group_b))
# GROUP C
group_c_num = int(input("Enter no. of students in group C (Football): "))
group_c = []
for i in range(0, group_c_num):
    el = input("Enter student name: ")
    group_c.append(el)
print("The list of students in group C: ", str(group_c))
flag = 1
def askcontinue():
cont = input("Do you want to continue using the program? (yes/no): ") if cont == "yes":
        return True
    else:
return False
# TASK FUNCTIONS
def cb(ls1, ls2):
    oplist = intersection(ls1, ls2)
    return oplist
def cobbnb(ls1, ls2):
    d1 = difference(ls1, ls2)
    d2 = difference(ls2, ls1)
    l3 = union(d1, d2)
    return l3
def no_ncnb(secomp, group_a, group_b):
    ls3 = difference(secomp, union(group_a, group_b))
    return len(ls3)
def no_cafbnb(group_a, group_b, group_c):
    ls3 = difference(intersection(group_a, group_c), group_b)
    return len(ls3)
# SET FUNCTIONS
def intersection(ls1, ls2):
    ls3 = []
    for val in ls1:
        if val in ls2:
            ls3.append(val)
return ls3
def difference(ls1 ,ls2):
    ls3 = []
    for val in ls1:
        if val not in ls2:
            ls3.append(val)
    return ls3
def union(ls1 ,ls2):
    ls3 = ls1.copy()
    for val in ls2:
        if val not in ls3:
            ls3.append(val)
    return ls3
while (flag == 1):
    print(
        "Available optons; \n1: Students who play both cricket and badminton\n2:
Students who play either cricket or badminton but not both \n3: No. of students who
play neither cricket nor badminton \n4: No. of students who play cricket and
football but not badminton \n")
    choice = int(input("Enter your choice: "))
    if (choice == 1):
        print("Cricket & Badminton: ", cb(group_a, group_b))
        flag = 1 if askcontinue() else 0
    elif (choice == 2):
        print("Either cricket or badminton but not both: ", cobbnb(group_a,
group_b))
        flag = 1 if askcontinue() else 0

elif (choice == 3):
print("No. of neither cricket nor badminton: ", no_ncnb(secomp, group_a,
group_b))
        flag = 1 if askcontinue() else 0
    elif (choice == 4):
        print("No. of cricket and football but not badminton: ", no_cafbnb(group_a,
group_b, group_c))
        flag = 1 if askcontinue() else 0
    else:
        print("INVALID CHOICE")
        flag = 1 if askcontinue() else 0