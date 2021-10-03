import tkinter as tk
from tkinter import *
from datetime import datetime, date


current_date = datetime.now().strftime("%d-%m-%Y %H:%M:%S")
current_day = str(date.today())
current_time = datetime.now().strftime("%H-%M-%S")
current_day += '_'
current_day += str(current_time)
file_path = 'D:/output/'

def generatepdf(invoice_data, company):
    import pdfkit
    from pdfkit.api import configuration

    options = {
        'page-height': '200',
        'page-width': '150',
    }
    wkhtml_path = pdfkit.configuration(wkhtmltopdf = "C:/Program Files/wkhtmltopdf/bin/wkhtmltopdf.exe")  #by using configuration you can add path value.

    image_urls = {
        "EXAMROADMAP": "data:image/png;base64,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",
        "EXACTPREP": "data:image/png;base64,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"
    }

    img_url = image_urls[company]
    dynamic_data = ""
    for row in invoice_data[2:]:
        dynamic_data += "<tr> <td>{}</td> <td>{}</td> </tr>".format(row[0], row[1])
    data = "<html><head><style>body { border: 2px solid; margin: 0; padding: 5px;}table { font-family: arial, sans-serif; border-collapse: collapse; width: 100%; font-size: 18px;} td:first-child {font-weight: bold}td, th { border: 1px solid #1e195f; padding: 5px;} tr:nth-child(odd) { background-color: #dddddd;}tr:nth-child(1) { background-color: #dddddd; text-align: center;}tr:nth-child(2) { background-color: #1e195f; color: #fff; text-align: center;}p { text-align: center; color: #1e195f; font-size: 22px;}img { width:100px; height: 100px;}</style></head><body><table> <tr> <th><img src="+img_url+"></th> <th>Date : "+ invoice_data[0][1] +"</th> </tr> <tr> <td colspan='2'>Payment Receipt</td> </tr>"+ dynamic_data +"</table><p>Thank you for using "+company+".</p></body></html>"
    file_name = str(str(invoice_data[1][1])+company+'_'+str(current_day)+'_'+invoice_data[3][1])
    print(file_name)
    pdfkit.from_string(data, file_name +'.pdf', configuration = wkhtml_path, options = options)


fields = 'Order ID', 'Name', 'Amount', 'Taxation ID', 'Payment Gateway', 'Subjects' , 'Validity', 'Buyer Details'
def fetch(entries):
    data = []
    company = clicked.get()
    for entry in entries:
        field = entry[0]
        text  = entry[1].get()
        data.append([str(field),str(text)])
    print(data)
    generatepdf(data, company)
    
        

def makeform(root, fields):
    entries = []
  
    row = tk.Frame(root)
    dent = tk.Entry(row)
    dent.insert(END, file_path)
    row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=5)
    dent.pack(side=tk.RIGHT, expand=tk.YES, fill=tk.X, ipady=7)

    row = tk.Frame(root)
    lab = tk.Label(row, width=15, text="Date", anchor='w')
    ent = tk.Entry(row)
    ent.insert(END, current_date)
    row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=5)
    lab.pack(side=tk.LEFT)
    ent.pack(side=tk.RIGHT, expand=tk.YES, fill=tk.X, ipady=7)
    entries.append(('Date', ent))
    entries.append(('Path', dent))


    for field in fields:
        row = tk.Frame(root)
        lab = tk.Label(row, width=15, text=field, anchor='w')
        ent = tk.Entry(row)
        row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=5)
        lab.pack(side=tk.LEFT)
        ent.pack(side=tk.RIGHT, expand=tk.YES, fill=tk.X, ipady=7)
        entries.append((field, ent))
    return entries

if __name__ == '__main__':
    root = tk.Tk()
    root.title("INVOICE GENERATER")
    root.configure(bg="teal")
    root.geometry("500x550")
    root.resizable(0, 0)

    options = ["EXAMROADMAP", "EXACTPREP"]

    clicked = StringVar()
    clicked.set( "EXAMROADMAP" )
    drop = OptionMenu( root , clicked , *options )
    drop.pack(fill=tk.X)

    

    ents = makeform(root, fields)
    b1 = tk.Button(root, text='Generate Invoice',command=(lambda e=ents: fetch(e)))
    b1.pack(side=tk.LEFT, padx=5, pady=5)
    b2 = tk.Button(root, text='Quit', command=root.quit)
    b2.pack(side=tk.LEFT, padx=5, pady=5)
    root.mainloop()


