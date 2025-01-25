import math

# Given values
C = 9.99  # Farads
d = 1.89e-3  # meters
epsilon_0 = 8.85e-12  # F/m

# Calculate area
A = (C * d) / epsilon_0

print("The surface area is " + str(A) + " square meters")
print("Or approximately " + str(round(A)) + " square meters")