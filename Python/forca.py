import Control
import random

def tamanhoString(palavra):
    """ está função verifica o tamanho de umma string.
    :param palavra: recebe uma string
    :return: um inteiro
    """
    contador = 0
    for caracter in palavra:
        contador = contador + 1

    return contador


def compararValores(valor1, valor2):
    """ está função compara dois valores.
    :param valor1: recebe string ou inteiro
    :param valor2: recebe string ou inteiro
    :return: True, se a condição for aceita
    """
    if valor1 == valor2:
        return True
    else:
        return False


def transformarEmLista(palavra):
    """ está função transforma uma string em uma lista.
    :param palavra: uma string
    :return: uma lista
    """
    lista = []
    for caracter in palavra:
        lista.append(caracter)
    return lista


def palavrasPadrao():
    """ está função escolhe aleatoriamente uma palavra.
    :return: uma string
    """
    palavrasFrutas = random.randint(1, 6)

    if palavrasFrutas == 1:
        return "abacaxi"
    elif palavrasFrutas == 2:
        return "manga"
    elif palavrasFrutas == 3:
        return "melancia"
    elif palavrasFrutas == 4:
        return "banana"
    elif palavrasFrutas == 5:
        return "abacate"
    elif palavrasFrutas == 6:
        return "morango"


def escolherPalavra():
    """ está função pergunta ao usúario qual modo de jogo
    ele deseja.
    :return: uma string
    """
    print (organizarCodigo(1))
    print ("     MODO DE JOGAR     ")
    print (organizarCodigo(1))
    print (" - 1 - Individual")
    print (" - 2 - Multiplayer")
    print (organizarCodigo(1))

    opcao = int(input("Digite sua opção: "))
    print (organizarCodigo(1))
    if opcao == 1:
        palavraUsuarioIndividual = palavrasPadrao()
        return palavraUsuarioIndividual
    else:
        palavraUsuarioMultiplayer = input("Digite sua palavra: ")
        return palavraUsuarioMultiplayer


def escolherDica():
    """ está função pergunta ao usúario qual a dica será utilizada.
    :return: uma string
    """
    print (" - 1 - Digitar dica")
    print (" - 0 - Dica padrão(Caso tenha escolhido INDIVIDUAL)")
    opcao = int(input("Digite sua opção: "))
    if opcao == 1:
        dicaUsuario = input("Digite sua palavra: ")
        return dicaUsuario
    else:
        dicaPadrao = " F R U T A "
        return dicaPadrao


def organizarCodigo(tipo):
    """ está função organizar o jogo com asteriscos " * ".
    :param tipo: recebe um inteiro
    :return: uma string
    """
    if tipo == 1:
        return "-" * 25

    if tipo == 2:
        return "-" * 30

    if tipo == 3:
        return "-" * 35

    if tipo == 4:
        return "-" * 40


def verificarCaracter(caracter1, caracter2):
    """ está função verifica se duas strings ou duas listas
    possuem o mesmo caracter.
    :param caracter1: recebe um caracter
    :param caracter2: recebe uma string ou uma lista
    :return: True, se a condição for aceita
    """
    if caracter1 in caracter2:
        return True
    else:
        return False


def construirPalavra(tentativa, palavra, palavraVisualizada, palavraOculta):
    """ está função verifica se existe uma letra
    em uma palavra.
    :param tentativa: recebe um caracter
    :param palavra: recebe uma string
    :param palavraVisualizada: recebe uma lista com o nome da palavra escolhida
    :param palavraOculta: recebe uma lista com a palavra oculta
    :return: letras que existem na palavra
    """
    if tentativa == palavra:
        return palavraVisualizada

    for controle in range(0, tamanhoString(palavra)):
        if tentativa in palavraVisualizada:
            if palavraVisualizada[controle] == tentativa:
                palavraOculta[controle] = palavraVisualizada[controle]

    return palavraOculta

ask_again = True
start_game = True

while start_game:

    palavra_escolhida = Control.escolherPalavra()

    palavra_dica = Control.escolherDica()

    palavra_lista = Control.transformarEmLista(palavra_escolhida)

    palavra_oculta = []
    for letras_ocultas in palavra_escolhida:
        palavra_oculta.append("_")

    print(Control.organizarCodigo(1))

    tentativas = []

    chances = 6

    erros = 0

    print ("\n")
    print ("VOCE TEM 6 CHANCES PARA ACERTAR A PALAVRA.")
    print ("\n")
    print ("A PALAVRA TEM", Control.tamanhoString(palavra_lista), "LETRAS")
    print ("\n")
    print ("A DICA É: ", palavra_dica)
    print ("\n")

    while ask_again:

        letra_palavra = input("DIGITE UMA LETRA (OU A PALAVRA): ")

        contruir_palavra = Control.construirPalavra(    letra_palavra,
                                                        palavra_escolhida,
                                                        palavra_lista,
                                                        palavra_oculta)

        print (Control.organizarCodigo(4))
        print ("PALAVRA: ", contruir_palavra)

        if Control.compararValores(contruir_palavra, palavra_lista):
            print ("\n")
            print ("YOU WIN")
            print (Control.organizarCodigo(4))
            break

        else:
            print (Control.organizarCodigo(4))

        if Control.compararValores(letra_palavra, palavra_escolhida):
            print ("\n")
            print ("YOU WIN")
            print (Control.organizarCodigo(3))
            break

        elif letra_palavra not in palavra_lista:

            if Control.verificarCaracter(letra_palavra, tentativas):
                print ("\n")
                print ("Você já tentou essa letra(ou palavra)")
                print ("\n")
                print ("LETRAS USADAS: ", tentativas)
                print ("\n")
                continue

            else:
                print ("\n")
                print ("Não há essa letra(ou palavra)")
                print ("\n")
                tentativas.append(letra_palavra)
                erros = erros + 1

                if Control.compararValores(erros, chances):
                    print ("VOCÊ ERROU", erros, "VEZES")
                    print ("\n")
                    ultimaTentativa = input("Ultima tentativa, digite uma Palavra: ")

                    if Control.compararValores(ultimaTentativa, palavra_escolhida):
                        print ("\n")
                        print ("YOU WIN")
                        print (Control.organizarCodigo(3))
                        break

                    else:
                        print ("\n")
                        print ("YOU LOSE")
                        print ("\n")
                        print ("A PALAVRA CORRETA ERA:", palavra_escolhida)
                        print (Control.organizarCodigo(3))
                        break

                else:
                    print ("LETRAS USADAS: ", tentativas)
                    print ("\n")
                    print ("ERROS: ", erros)
                    print ("\n")
                    continue

        else:

            if Control.verificarCaracter(letra_palavra, tentativas):
                print ("\n")
                print ("Você já tentou essa letra(ou palavra)")
                print ("\n")
                print ("LETRAS USADAS: ", tentativas)
                print ("\n")
                continue

            else:
                print ("\n")
                print ("Você acertou uma letra")
                tentativas.append(letra_palavra)
                print ("\n")
                print ("LETRAS USADAS: ", tentativas)
                print ("\n")
                continue

    break
