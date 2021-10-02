def emoji_convertor(message):
    words = message.split(" ")
    emojis = {
        ":)" : "😁",
        ":(" : "😞"
    }
    output = ""
    for word in words:
        output += emojis.get(word, word) + " "
        return output

# PLEASE PROVIDE INPUT AS A :) or :()           
message = input(">")
result = emoji_convertor(message)
print(result)
