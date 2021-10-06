def mad_libs():
    inputs,pos=[],['a random last name','a noun','the time of day','an adjective','a verb present, that ends in ing','a body part','a number','a noun','a verb base form','a liquid','a number','a period of time- day, month, year, etc','a noun plural','an animal','a noun plural','your name']
    for part in pos: inputs.append(input(f'Give me {part}'))
    print("""Dear Dr. {0},

I cannot make it to {1} this {2}. I am very {3} and cannot stop {4} my {5}. I have a fever of {6} degrees and the doctor ordered me to stay in {7} and {8} lots of {9}. Also, can I have a {10} {11} extension on the essay about {12}? My {13} ate it and now I have to start all over!

Best {14},

{15}""".format(*inputs))
