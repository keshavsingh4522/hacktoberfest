def arithmetic_arranger(problems, showResult):
    
    # print(len(problems))

    arranged_problems = ''
    print('\n')
    # for element in problems:
    splitProb = ' '.join(problems).split()

    i = 0
    while i < len(splitProb):
        arranged_problems += splitProb[i] + '\t'
        i += 3
    arranged_problems += '\n'

    j = 1
    while j < len(splitProb):
        if len(str(splitProb[j - 1])) - len(str(splitProb[j + 1])) == 2:
            arranged_problems += splitProb[j] + ' ' + splitProb[j + 1] + '\t'
        elif len(str(splitProb[j - 1])) - len(str(splitProb[j + 1])) == 3:
            arranged_problems += splitProb[j] + '  ' + splitProb[j + 1] + '\t'
        else:
            arranged_problems += splitProb[j]  + splitProb[j + 1] + '\t'
        j += 3
    arranged_problems += '\n'

    k = 2
    while k < len(splitProb):
        
        arranged_problems += '-----\t'
        k += 3
    arranged_problems += '\n'

    if (showResult):
        for ele in problems:
            arranged_problems += str(eval(ele)) + '\t'
    arranged_problems += '\n'
    
    print(arranged_problems)
    # return arranged_problems

arithmetic_arranger(["20000 + 500", "1000 + 200", "2000 + 800", " 4000 - 800", "20000 + 500"], True)