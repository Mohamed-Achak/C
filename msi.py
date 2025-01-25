# Given values from the circuit
Vemf = 23.7  # Voltage of the battery in volts
R1 = 6.89    # Resistance R1 in ohms
R2 = 6.89    # Resistance R2 in ohms
L = 7.91     # Inductance in henries

# Equivalent resistance (parallel combination of R1 and R2)
Req = (R1 * R2) / (R1 + R2)
Rtotal = Req

# a) Current flowing out of the battery
I_total = Vemf / Rtotal

# b & c) Current through each resistor (voltage divider in parallel)
I_R1 = I_total / 2
I_R2 = I_total / 2

# d) Voltage across R1
V_R1 = I_R1 * R1

# e) Voltage across R2
V_R2 = I_R2 * R2

# f) Voltage across L (initially, assuming steady state)
V_L = Vemf - V_R1

# g) Rate of current change across R1 (V_L = L * di/dt)
di_dt = V_L / L

# Print results
print("a) Current flowing out of the battery:", I_total, "A")
print("b) Current through R1:", I_R1, "A")
print("c) Current through R2:", I_R2, "A")
print("d) Voltage across R1:", V_R1, "V")
print("e) Voltage across R2:", V_R2, "V")
print("f) Voltage across L:", V_L, "V")
print("g) Rate of current change across R1:", di_dt, "A/s")