from barcode import EAN13
from barcode.writer import ImageWriter
number = input("Enter the barcode number: ")
my_code = EAN13(number, writer=ImageWriter())
my_code.save('barcode.png')
