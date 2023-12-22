'''

Experiment Number 14: Write a python program to store first year percentage of students in an array. Write function for sorting array of floating point numbers in ascending order using:
    a) Selection Sort
    b) Bubble Sort and display top five scores

'''

#<---------------------------------------------------------------------------------------->

#selection sort
def Selection_Sort(marks):
    for i in range(len(marks)):
        min_idx = i  # Find the minimum element in remaining unsorted array
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                print("1",marks)
                min_idx = j
        marks[i], marks[min_idx] = marks[min_idx], marks[i]  # Swap the minimum element with the first element

        print("2",marks)

    print("Marks of students after performing Selection Sort on the list : ")
    print(marks)

#<---------------------------------------------------------------------------------------->

# Main

marks=[]
n = int(input("Enter number of students : "))
print("Enter marks for",n,"students (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)  # adding the element

print("The marks of",n,"students are : ")
print(marks)

#<---------------------------------------------------------------------------------------->

flag = 1

while flag == 1:

    print("\n---------------MENU---------------")
    print("1. Selection Sort of the marks")
    print("2. Bubble Sort of the marks")
    print("3. Exit")
    
    ch=int(input("\n\nEnter your choice (from 1 to 3) : "))

    if ch == 1:
        Selection_Sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no) : ")
        if a == 'yes':
            pass
        else:
            flag = 0
            print("\nThanks for using this program!")
            

    elif ch == 2:
        a = input("\nDo you want to display top five marks from the list (yes/no) : ")
        if a == 'yes':
            pass
        else:
            flag = 0
            print("\nThanks for using this program!")
            
    elif ch == 3:
        flag = 0
        print("\nThanks for using this program!!")

    else:
        flag = 0
        print("\nEnter a valid choice!!")
        print("\nThanks for using this program!!")
        