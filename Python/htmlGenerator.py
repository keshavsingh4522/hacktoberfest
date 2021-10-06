import os
import sys

FILE_PATH = os.path.abspath(__file__)
BASE_DIR = os.path.dirname(FILE_PATH)
HTML_DIR = os.path.join(BASE_DIR,'HTML CODE')
os.makedirs(HTML_DIR,exist_ok=True)

class FileManger:
    def __init__(self,file,method):
        self.file = file
        self.method = method
        #self.f = open (self.file,'{}'.format(self.method))

        if method == 'w':
            with open (self.file,self.method) as f:
                f.write('<HTML>\n<HEAD>\n')
                f.write('</HEAD>\n')
                f.write('<BODY>\n')

    def end_tags(self):
        with open (self.file,'r') as f:
            lines = f.readlines()

        if '</BODY>\n' not in lines:
            with open (self.file,'a') as f:
                f.write('</BODY>\n')
        if '</HTML>\n' not in lines:
            with open (self.file,'a') as f:
                f.write('</HTML>\n')

    def read_file(self,tag):
        line_count = 0
        with open (self.file,'r') as f:
            lines = f.readlines()

        for line in lines:
            if tag not in line:
                line_count += 1
            else:
                break
        return lines,(line_count)

class Tags(FileManger):
    def __init__(self,file,method):
        FileManger.__init__(self,file,method)

    def html_tag(self,file,method):
        self.f.write('<HTML>\n<HEAD>\n')
        
    
    def title_tag(self,title):
        lines,line_no = self.read_file('</HEAD>')
        lines.insert(line_no,'<TITLE>{}</TITLE>\n'.format(title))

        with open(self.file,'w') as f:
            f.writelines(lines)

    def header_tag(self,size,text):
        lines,line_no = self.read_file('</BODY>')
        lines.insert(line_no,'<h{0}>{1}</h{0}>\n'.format(size,text))

        with open(self.file,'w') as f:
            f.writelines(lines)
        
    def paragraph_tag(self,text_lines):
        lines,line_no = self.read_file('</BODY>')
        lines.insert(line_no,'<p>\n{}\n</p>\n'.format('<br>'.join(text_lines)))

        with open(self.file,'w') as f:
            f.writelines(lines)

    def image_tag(self,image_src,width,height):
        lines,line_no = self.read_file('</BODY>')
        lines.insert(line_no,'<img src="{}" width={} height={}>\n'.format(image_src,width,height))

        with open(self.file,'w') as f:
            f.writelines(lines)

name = input('Enter Name of file : ')

name_exists = os.path.isfile('{}/{}.html'.format(HTML_DIR,name))
file_name = '{}/{}.html'.format(HTML_DIR,name)

if name_exists:
    method = 'a'

else:
    method = 'w'

t = Tags(file_name,method)

while True:
    print()
    option = int(input('1.Add title\n2.Add paragraph\n3.Add Header\n4.Add Image\n5.Exit\n'))
    print()
    if option==1:
        t.title_tag(input('Enter title :'))
    elif option==2:
        lines = []
        print('Enter text\nHit enter if a break wherever a break is needed, Hit enter twice to stop typing:')
        while True:
            line = input()

            if line:
                lines.append(line)
            else:
                break

        t.paragraph_tag(lines)

    elif option==3:
        print('Header options - \n')
        header_option = int(input('1.h1\n2.h2\n3.h3\n4.h4\n5.h5\n6.h6\n'))
        text = input('Enter header :')
        t.header_tag(option,text)    

    elif option==4:
        image_src = input('Enter the location of image :\n(if image is in the same directory as application,enter image name\n)')
        width = int(input('Enter width of image in pixels :'))
        height = int(input('Enter height of image in pixels :'))
        t.image_tag(image_src,width,height)

    elif option == 5:
        t.end_tags()
        sys.exit()


