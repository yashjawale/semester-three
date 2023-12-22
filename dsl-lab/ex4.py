# INPUT ROll NOS
roll_nos = []
print("Enter roll nos (type done when finished)")
for i in range(20):
    num = input()
    if (num != "done"):
        roll_nos.append(int(num))
    else:
        break

print("Entered roll nos are:")
print(roll_nos)

# SORTING
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j] :
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
 

insertion_sort(roll_nos)

print("Sorted roll nos: ")
print(roll_nos)

# SEARCH
def ternarySearch(l, r, key, ar):
    while r >= l:
        # Find mid1 and mid2
        mid1 = l + (r-l) // 3
        mid2 = r - (r-l) // 3
  
        # Check if key at any mid
        if key == ar[mid1]:
            return mid1
        if key == mid2:
            return mid2
        if key < ar[mid1]:
            r = mid1 - 1
        elif key > ar[mid2]:
            l = mid2 + 1
        else:
            l = mid1 + 1
            r = mid2 - 1
    return -1

term = int(input("Enter roll no. to be searched: "))
foundkey = ternarySearch(0, len(roll_nos), term, roll_nos)
if (foundkey != -1):
    print("Index of", term, "is", foundkey)
else: print("Term not found")