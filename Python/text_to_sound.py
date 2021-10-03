from gtts import gTTS
import os

text = input("Enter your text to convert: ")
language = "en"
gttsObject = gTTS(text=text, lang=language, slow=False)
gttsObject.save("text_to_sound.mp3")
os.system("text_to_sound.mp3")
