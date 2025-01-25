
print("Welcome to FreshAUI Grocery Store!")
name = input("Enter your name: ")
print(f"Hello {name}, let's start shopping!")


print("\nAvailable Products:")
print("1. Apples - $2 per kg")
print("2. Bananas - $1 per kg")
print("3. Carrots - $3 per kg")
print("4. Dates - $5 per kg")

product_choice = int(input("Select a product by entering its number: "))


if product_choice == 1:
    product_name = "Apples"
    price_per_kg = 2
elif product_choice == 2:
    product_name = "Bananas"
    price_per_kg = 1
elif product_choice == 3:
    product_name = "Carrots"
    price_per_kg = 3
elif product_choice == 4:
    product_name = "Dates"
    price_per_kg = 5
else:
    print("Invalid choice. Please start over.")
    exit()

quantity = float(input(f"Enter the quantity of {product_name} in kg: "))
total_cost = price_per_kg * quantity

discount = 0
if total_cost > 20:
    discount = total_cost * 0.1
    total_cost -= discount

print("\nReceipt:")
print(f"Receipt for {name}:")
print(f"Product: {product_name}")
print(f"Quantity: {quantity} kg")
print(f"Total Cost before discount: ${price_per_kg * quantity:.2f}")
print(f"Discount: ${discount:.2f}")
print(f"Final Price: ${total_cost:.2f}")
print("\nThank you for shopping at FreshAUI Grocery Store!")

