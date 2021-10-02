import os
input_path="dummy_path_containing_files_which_have_scripts_for_view"
def get_tables(list):
    final_list=[]
    start=0
    for i in list:
        if i =="join":
            join_ind=list.index(i,start)
            final_list.append(list[join_ind+1])
            start=join_ind+1
        if i=="from":
            final_list.append(list[list.index(i)+1])
    return final_list
def process(path):
    f = open(path, "r")
    content=f.read().lower()
    cont_list=content.split(" ")
    main_view=cont_list[cont_list.index("view")+1]
    print(main_view)
    print(get_tables(cont_list))
    list_fnl='\n'.join([str(elem) for elem in get_tables(cont_list)])
    final_string="========"+main_view+"========\n"+list_fnl
    print(final_string)
    return 0

lst=os.listdir(input_path)
for file in lst:
    process(input_path+file)