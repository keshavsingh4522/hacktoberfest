from resume_parser import resumeparse

#resume_parser should be installed
#java should be running

data = resumeparse.read_file(r'C:\Users\some_\Downloads\Contain\Samarth - Resume.pdf') #pathtoresume
print(data)