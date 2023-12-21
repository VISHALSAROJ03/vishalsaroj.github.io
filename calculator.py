# calculate.py
from math_operations import add, subtract, multiply, divide

# Example calculations
num1 = 10
num2 = 5

# Perform calculations using the functions from the math_operations module
result_addition = add(num1, num2)
result_subtraction = subtract(num1, num2)
result_multiplication = multiply(num1, num2)
result_division = divide(num1, num2)

# Display results
print(f"Addition: {num1} + {num2} = {result_addition}")
print(f"Subtraction: {num1} - {num2} = {result_subtraction}")
print(f"Multiplication: {num1} * {num2} = {result_multiplication}")
print(f"Division: {num1} / {num2} = {result_division}")

