#defined function
def bubble_sort(list):
  #get list length
  count = len(list)

  #Loop through an array
  for i in range(count):
    for j in range(0, count - i - 1):
      #Switch if greater value is found
      if list[j] > list[j + 1]:
        list[j], list[j + 1] = list[j + 1], list[j]

#Test simple
example_list = [71, 77, 9, 11, 88]

#call function
bubble_sort(example_list)
print(example_list)
#OUTPUT: [9, 11, 71, 77, 88]
