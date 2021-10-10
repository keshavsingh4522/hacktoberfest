# importing libraries 
import speech_recognition as sr 
import os 
from pydub import AudioSegment
from pydub.silence import split_on_silence

# create a speech recognition object
r = sr.Recognizer()

# a function that splits the audio file into chunks
# and applies speech recognition
def get_large_audio_transcription(path):
    # open the audio file using pydub
    sound = AudioSegment.from_wav(path)  
    # split audio sound where silence is 700 miliseconds or more and get chunks
    chunks = split_on_silence(sound,
        # experiment with this value for your target audio file
        min_silence_len = 500,
        # adjust this per requirement
        silence_thresh = sound.dBFS-14,
        # keep the silence for 1 second, adjustable as well
        keep_silence=500,
    )
    foldername = "audio-chunks"
    # create a directory to store the audio chunks
    if not os.path.isdir(foldername):
        os.mkdir(foldername)
    wholetext = ""
    # process each chunk 
    for i, audio_chunk in enumerate(chunks, start=1):
        # export audio chunk and save it in
        # the `folder_name` directory.
        chunkfilename = os.path.join(foldername, f"chunk{i}.wav")
        audiochunk.export(chunkfilename, format="wav")
        # recognize the chunk
        with sr.AudioFile(chunkfilename) as source:
            audiolistened = r.record(source)
            # try converting it to text
            try:
                text = r.recognize_google(audiolistened)
            except sr.UnknownValueError as e:
                print("Error:", str(e))
            else:
                text = f"{text.capitalize()}. "
                print(chunkfilename, ":", text)
                wholetext += text
    # return the text for all chunks detected
    return wholetext
