import pyttsx3
import PyPDF2
pdfReader = PyPDF2.PdfFileReader(open('audiobook.pdf', 'rb'))
speaker = pyttsx3.init()

for i in range(pdfReader.numPages):
    pageObj = pdfReader.getPage(i).extractText()
    speaker.say(pageObj)
    speaker.runAndWait()
speaker.stop()
speaker.save_to_file(pageObj, 'audiobook.mp3')
speaker.runAndWait()
