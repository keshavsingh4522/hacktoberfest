from pathlib import Path



path = Path("ecommercse")
for file in path.glob('*'):
    print(file)
print(path.exists())
path2 = Path("emails")
#print(path2.rmdir())
#mkdir() - creates a directory

#Absolute path
# c:\prograam files\microsft
#relative path