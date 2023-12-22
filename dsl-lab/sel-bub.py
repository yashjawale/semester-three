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

percentages2 = percentages.copy();

# SELECTION SORT
def selectionSort(array, size):
    for step in range(size):
        min_idx = step
        for i in range(step + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i
        (array[step], array[min_idx]) = (array[min_idx], array[step])

# BUBBLE SORT
def bubbleSort(array):
  for i in range(len(array)):
    for j in range(0, len(array) - i - 1):
      if array[j] > array[j + 1]:
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp

size = len(percentages)
selectionSort(percentages, size)
print('Sorted Array using Selection Sort:')
print(percentages)
bubbleSort(percentages2)
print('Sorted Array using Bubble Sort:')
print(percentages2)
print("Top five percentages: ")
print(percentages2[size:size-5:-1])


    