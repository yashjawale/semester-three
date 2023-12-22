import numpy as np

print("Enter first matrix")
rows1 = int(input("Enter no. of rows: "))
columns1 = int(input("Enter no. of columns: "))

matrix1 = []
print("Enter the elements row wise")

# MATRIX INPUT
for i in range(rows1):
    r =[]
    for j in range(columns1):
        r.append(int(input()))
    matrix1.append(r)

# PRINTING MATRIX
print("Entered matrix is: ")
for i in range(rows1):
    for j in range(columns1):
        print(matrix1[i][j], end=" ")
    print()

print("Enter second matrix")
rows2 = int(input("Enter no. of rows: "))
columns2 = int(input("Enter no. of columns: "))

matrix2 = []
print("Enter the elements row wise")

# MATRIX INPUT
for i in range(rows2):
    r =[];
    for j in range(columns2):
        r.append(int(input()))
    matrix2.append(r)

# PRINTING MATRIX
print("Entered matrix is: ")
for i in range(rows2):
    for j in range(columns2):
        print(matrix2[i][j], end=" ")
    print()

addition = np.add(matrix1, matrix2);
subtraction = np.subtract(matrix1, matrix2)
multiplication = np.dot(matrix1, matrix2)
transpose1 = np.transpose(matrix1)
transpose2 = np.transpose(matrix2)

print("Addition is: ")
print(addition)
print("Subtraction is: ")
print(subtraction)
print("Transpose of first matrix is: ")
print(transpose1)
print("Transpose of second matrix is: ")
print(transpose2)