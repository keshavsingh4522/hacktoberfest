#defined function
def bubble_sort(input_list):
  #get list length
  count = len(input_list)

  #Loop through an array
  for i in range(count):
    for j in range(0, count - i - 1):
      #Switch if greater value is found
      if input_list[j] > input_list[j + 1]:
        input_list[j], input_list[j + 1] = input_list[j + 1], input_list[j]

#Test simple
example_list = [71, 77, 9, 11, 88]

#call function
bubble_sort(example_list)
print(example_list)
