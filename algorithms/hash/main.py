import time
import os
import random

def crc_hash(key: str) -> int:
    h = 0
    for ki in key:
        high_order = h & 0xf8000000
        h = h << 5
        h = h ^ (high_order >> 27)
        h = h ^ ord(ki)
    return h

def pjw_hash(key: str) -> int:
    h = 0
    for ki in key:
        h = (h << 4) + ord(ki)
        g = h & 0xf0000000
        if g != 0:
            h = h ^ (g >> 24)
            h = h ^ g
    return h

def buz_hash(key: str) -> int:
    h = 0
    R = dict()
    for ki in key:
        high_order = h & 0x80000000
        h = h << 1
        h = h ^ (high_order >> 31)
        if not (ki in R):
            R[ki] = random.randint(0, 0xFFFFFFFF)
        h = h ^ R[ki]
    return h

def find_duplicates(files: list[str], hash_function: callable) -> list[str]:
    duplicates = []
    processed_hashes = []
    for file in files:
        with open(file, 'r') as f:
            content = f.read()
            hashed_content = hash_function(content)
            if hashed_content in processed_hashes:
                duplicates.append(file)
            else:
                processed_hashes.append(hashed_content)
    return duplicates

if __name__ == '__main__':
    folder_path = "out/"
    files = [folder_path + file for file in os.listdir(folder_path) if file.endswith(".txt")]

    hash_functions = [crc_hash, pjw_hash, buz_hash, hash]

    for hash_function in hash_functions:
        start_time = time.time()
        duplicates = find_duplicates(files, hash_function)
        end_time = time.time()
        print(f"Function: {hash_function.__name__}")
        print(f"Number of dudlicates: {len(duplicates)}")
        print(f"Time: {end_time - start_time} sec")
