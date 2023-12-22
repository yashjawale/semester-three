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

def partition(array, low, high):
  pivot = array[high]
  i = low - 1
  for j in range(low, high):
    if array[j] <= pivot:
      i = i + 1
      (array[i], array[j]) = (array[j], array[i])
  (array[i + 1], array[high]) = (array[high], array[i + 1])
  return i + 1

def quickSort(array, low, high):
  if low < high:
    pi = partition(array, low, high)
    quickSort(array, low, pi - 1)
    quickSort(array, pi + 1, high)

size = len(percentages)

quickSort(percentages, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(percentages)
print("Top five percentages:")
print(percentages[size:size-5:-1])