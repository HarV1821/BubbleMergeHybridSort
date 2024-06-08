import random

def generate_random_numbers(num_elements, min_value=1, max_value=100):
    """Generates a list of random numbers within the specified range."""
    return [random.randint(min_value, max_value) for _ in range(num_elements)]

def save_to_file(numbers, filename="SampleDataset_5kE.txt"):
    """Saves a list of numbers to a file with commas and spaces."""
    with open(filename, "w") as file:
        file.write(", ".join(map(str, numbers)))  # Convert to strings and join

# Get the number of elements from the user
num_elements = int(input("Enter the number of random numbers to generate: "))

# Generate the random numbers
random_numbers = generate_random_numbers(num_elements)

# Save the numbers to a file
save_to_file(random_numbers)

print(f"Generated {num_elements} random numbers and saved to random_numbers.txt")
