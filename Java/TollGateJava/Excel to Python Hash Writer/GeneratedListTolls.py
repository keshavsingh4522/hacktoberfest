x= "Angeles,Balagtas,Bocaue,Clark North,Clark South,Concepcion,Dau,Dinalupihan,Dolores,Floridablanca,Mabalacat (Mabiga),Marilao,Mexico,Meycauayan,Mindanao Avenue,Porac,Pulilan,San Fernando,San Miguel,San Simon,Sta. Ines,Sta. Rita,Tabang,Tarlac,Tipo/SFEX,Valenzuela"
'''
x=x.split(",")
for i in x:
    print("jComboBox1.addItem(\"{}\");".format(i))

'''

'''
y="BAL	MIN	KAR	VAL	MEY	MAR	BOC	STR	PUL	SNM	SNF	MXC	ANG	DAU"
y=y.split()

for i in y:
    print("jComboBox2.addItem(\"{}\");".format(i))
    
'''
import xlrd
d = {}
f = open("C:\\Users\\MY-PC\\Desktop\\TollGateJava\\NEWFILE0045.txt", "w")
wb = xlrd.open_workbook('D:\\New folder\\Book1.xlsx')
sh = wb.sheet_by_index(3)

y =sh.col_values(5) 
for i in y:
    f.write("jComboBox2.addItem(\"{}\");\n".format(i))
f.close()