import xlrd


f = open("C:\\Users\\MY-PC\\Desktop\\TollGateJava\\tbl_Class3.txt", "w")
wb = xlrd.open_workbook('D:\\New folder\\Book1.xlsx')
sh = wb.sheet_by_index(2) 
x=len(sh.col_values(0))-1
y = len(sh.row_values(0))-1
for i in range(x):
    lenx= len(list(filter(None,sh.row_values(i+1) )))
    for j in range(lenx-1):
        start = sh.cell(i+1,0).value
        destination = sh.cell(0,j+1).value
        value_Price = sh.row_values(i+1)
        
        f.write("hash.put("+"\""+start+"-"+destination+"\""+','+str(value_Price[j+1])+");\n")
f.close()