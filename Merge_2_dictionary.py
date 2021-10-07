#"Merge Two Dictionaries using copy() and update()"

DictionaryOne = {"key1": "Value1", "Key2": "Value2"}
DictionaryTwo = {"key3": "Value3", "Key4": "Value4"}

DictionaryThree = DictionaryOne.copy()
DictionaryThree.update(DictionaryTwo)

print("\nThe Two Dictionary Merged Successfully!")
print("\nThe New Dictionary is:")
print(DictionaryThree)