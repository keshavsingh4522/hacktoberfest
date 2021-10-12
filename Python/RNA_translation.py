rna = "AUGCUUGAUUCCCCUCAAAGGUUAAUGGGACGGGCGGGACGCGAUAGGUGCGCCGGGGAGCACUUCACGGCGGAAAGCCGGUUGAAGGCUCGGCGCCGCUGCCCCGAACGAACGGCAUCAGUGAUACCUAUAGCACACCCACGCAUGCCAUGUCAUCAUCUAAGUUACCAAAUGAGGGUAGGAGCCUAUGUUACGGCAAAUCCCGGACAGAAAGCAUCCGUGUCGUCCGCGCUAUUGAUUUCAAUACUAGUCAAUGUCCUAAACUACCAGCCCGCUAGGAGAAUCGAAUGGUUUGCGUGUUUGUUGUGA"
start = ["AUG"]
stop = ["UAA","UAG","UGA"]

geneticCode = {
'UUU':'F', 'UUC':'F', 'UUA':'L', 'UUG':'L', 
'UCU':'S', 'UCC':'S', 'UCA':'S', 'UCG':'S', 
'UAU':'Y', 'UAC':'Y', 'UAA':'ST', 'UAG':'ST', 
'UGU':'C', 'UGC':'C', 'UGA':'ST', 'UGG':'W', 
'CUU':'L', 'CUC':'L', 'CUA':'L', 'CUG':'L',
'CCU':'P', 'CCC':'P', 'CCA':'P', 'CCG':'P',
'CAU':'H', 'CAC':'H', 'CAA':'Q', 'CAG':'Q',
'CGU':'R', 'CGC':'R', 'CGA':'R', 'CGG':'R',
'AUU':'I', 'AUC':'I', 'AUA':'I', 'AUG':'M',
'ACU':'T', 'ACC':'T', 'ACA':'T', 'ACG':'T',
'AAU':'N', 'AAC':'N', 'AAA':'K', 'AAG':'K',
'AGU':'S', 'AGC':'S', 'AGA':'R', 'AGG':'R',
'GUU':'V', 'GUC':'V', 'GUA':'V', 'GUG':'V',
'GCU':'A', 'GCC':'A', 'GCA':'A', 'GCG':'A',
'GAU':'D', 'GAC':'D', 'GAA':'E', 'GAG':'E',
'GGU':'G', 'GGC':'G', 'GGA':'G', 'GGG':'G'
}

def converteEntrada(rna):
    contador = 0
    codons = ""
    for base in rna:
        codons += base
        contador += 1
        if contador == len(rna): continue
        if contador % 3 == 0: codons += ";"
    listaDeCodons = codons.split(";")
    return listaDeCodons

def formaCadeiaDeAminoacidos(codons):
    cadeiaDeAminoacidos = ""
    for codon in codons:
        if codon not in stop: cadeiaDeAminoacidos += geneticCode[codon]
        else: cadeiaDeAminoacidos += "*"
    return cadeiaDeAminoacidos

def salvaEmArquivo(cadeiaDeAminoacidos):
    arquivo = open("Cadeia de Aminoacidos.txt", 'w', encoding="utf8")
    arquivo.write(cadeiaDeAminoacidos)
    arquivo.close()

def main(rna):
    codons = converteEntrada(rna)
    cadeiaDeAminoacidos = formaCadeiaDeAminoacidos(codons)
    salvaEmArquivo(cadeiaDeAminoacidos)

if __name__ == "__main__":
    main(rna)