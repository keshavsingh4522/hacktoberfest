# HTML COMMENTS PARSER

from html.parser import HTMLParser

class CustomHTMLParser(HTMLParser):
    def handle_comment(self, data):
        number_of_line = len(data.split('\n'))
        if number_of_line > 1:
            print('>>> Multi-line Comment:')
        else:
            print('>>> Single-line Comment:')
        if data.strip():
            print(data)

    def handle_data(self, data):
        if data.strip():
            print(">>> Data:")
            print(data)

parser = CustomHTMLParser()

n = int(input())

html_string = ''
for i in range(n):
    html_string += input().rstrip()+'\n'
    
parser.feed(html_string)
parser.close()