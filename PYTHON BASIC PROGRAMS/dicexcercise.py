phone = input("Phone: ")
digits_mapping = {
      "1": "one",
      "2": "two",
      "3": "Three",
      "4":"four"
}
output = ""
for ch in phone:
    output += digits_mapping.get(ch,"!") + " "
print(output)