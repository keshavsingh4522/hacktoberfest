import matplotlib.pyplot as plt
import matplotlib as eoq
from hashlib import sha256
import random
import string
import time

def generate_random_string(size):
    # Generate random string with lowercase, uppercase and special characters
    options = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(options) for i in range(size))

def cut_binary(bin_, cut_size):
    # Remove the prefix 0b that python sets automatically
    bin_ = bin_[2:]

    # Cut the binary
    end = len(bin_) - cut_size
    cut_bin = bin_[end:]
    return cut_bin

def check_collision(hash1, hash2, collision_size):
    bin1 = bin(int(hash1, 16))
    bin2 = bin(int(hash2, 16))

    cut_bin1 = cut_binary(bin1, collision_size)
    cut_bin2 = cut_binary(bin2, collision_size)

    if cut_bin1 == cut_bin2:
        return True
    else:
        return False

def paradox(string_size, collision_size):
    count = 0
    checked_bins = {}

    while True:
        count += 1

        rand_string = generate_random_string(string_size)
        hash_ = sha256()
        hash_.update(bytes(rand_string, encoding='utf8'))
        hash_ = hash_.hexdigest()

        bin_ = bin(int(hash_, 16))
        cut_bin = cut_binary(bin_, collision_size)

        if cut_bin in checked_bins:
            return count

        checked_bins[cut_bin] = True

def ingenuous(string_size, collision_size):
    count = 0
    while True:
        count += 1

        rand_string1 = generate_random_string(string_size)
        rand_string2 = generate_random_string(string_size)

        hash1 = sha256()
        hash1.update(bytes(rand_string1, encoding='utf8'))
        hash1 = hash1.hexdigest()

        hash2 = sha256()
        hash2.update(bytes(rand_string2, encoding='utf8'))
        hash2 = hash2.hexdigest()

        if check_collision(hash1, hash2, collision_size):
            return count

if __name__ == '__main__':
    string_size = 10
    repetition = 20
    max_collision_size = 20
    ingenuous_result = [0] * max_collision_size
    paradox_result = [0] * max_collision_size

    for _ in range(0, repetition):
        for collision_size in range(1, max_collision_size+1):
            ingenuous_count = ingenuous(string_size, collision_size)
            ingenuous_result[collision_size-1] += (ingenuous_count / repetition)
            print(f'Collision Size: {collision_size}, Count: {ingenuous_count}')

            paradox_count = paradox(string_size, collision_size)
            paradox_result[collision_size-1] += (paradox_count / repetition)
            print(f'Collision Size: {collision_size}, Count: {paradox_count}')

    xAxis = [i for i in range(1, max_collision_size+1)]
    plt.plot(xAxis, ingenuous_result, label = "ingenuous")
    plt.plot(xAxis, paradox_result, label = "paradox")
    plt.xticks(xAxis)
    plt.xlabel('Number of equal bits')
    plt.ylabel('Average of Iterations to Collide')
    plt.legend()
    plt.show()
