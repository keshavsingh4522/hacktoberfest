####
# Run the following on terminal:
#   pip install streamlit
#   Install any other pacakges as required
####

import PyPDF2
import streamlit as st
from gtts import gTTS
from io import BytesIO

def speakText(text):
    sound_file = BytesIO()
    tts = gTTS(text, lang='en')
    tts.write_to_fp(sound_file)
    st.audio(sound_file)

def extractText(pdfPath):
    pdfReader = PyPDF2.PdfReader(pdfPath)

    text = ""
    for pageObj in pdfReader.pages:
        st.write("Reading PDF ..")
        text += pageObj.extract_text()

    return text

def readPDF(pdf):
    text = extractText(pdf)
    speakText(text)

pdfReader, textReader = st.columns(2)

with pdfReader:
    st.write("""
    # PDF Reader
    Helps blind people read a PDF document.
    """)

    uploaded_pdf = st.file_uploader("Upload your PDF", type = "pdf")

    if uploaded_pdf:
        readPDF(uploaded_pdf)

with textReader:
    st.write("""
    # Text Reader
    Helps blind people read a piece of text.
    """)

    text = st.text_input(label = "To read")

    if text:
        speakText(text)



