percentages = []

print("Enter percentages (type done when finished)")
for i in range(20):
    num = input()
    if (num != "done"):
        percentages.append(float(num))
    else:
        break

print("Entered percentages are:")
print(percentages)

def insertionSort(array):
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1     
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = key

print("Sorted percentages by Insertion sort: ");
insertionSort(percentages);
print(percentages)
print("Top five percentages:")
print(percentages[len(percentages):len(percentages)-5:-1])