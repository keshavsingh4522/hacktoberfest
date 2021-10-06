from itertools import permutations
def perms(word,size):
    print('\n'.join(sorted(''.join(p) for p in permutations(word,size))))
