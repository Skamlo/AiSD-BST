import random


def generate_file(filename, length):
    with open(filename, 'w') as file:
        random_numbers = [str(random.randint(1, 500000))
                          for _ in range(length)]
        file.write(' '.join(random_numbers))
        file.write("\nprint")
        file.write("\nrebalance")
        file.write("\nfindminmax")
        file.write("\nexit")


file_lengths = [100, 1000, 10000, 100000, 500000]
for i, length in enumerate(file_lengths):
    filename = f"random_numbers_{length}.txt"
    generate_file(filename, length)
    print(f"File {i+1} generated with {length} random numbers.")
