import hashlib

# Input string
input_string = "Hello"

# Create a SHA-256 hash object
hash_object = hashlib.sha256()

# Update the hash object with the bytes of the input string
hash_object.update(input_string.encode())

# Get the hexadecimal representation of the hash
hashed_string = hash_object.hexdigest()

# Print the result
print(f"The SHA-256 hash of '{input_string}' is: {hashed_string}")
