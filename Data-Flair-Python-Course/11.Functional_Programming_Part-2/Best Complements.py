def complement(binary):
    return ~eval(str(eval('0b'+binary if binary[:2]!='0b' else binary)+1))
