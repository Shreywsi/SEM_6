a = input("Enter elements of Set A (space separated): ")
A = set(map(int, a.split()))
b = input("Enter elements of Set B (space separated): ")
B = set(map(int, b.split()))

print("\nSet A:", A)
print("Set B:", B)

# Union
print("\nUnion:", A | B)

# Intersection
print("Intersection:", A & B)

# Subtraction
print("Subtraction:", A - B)
