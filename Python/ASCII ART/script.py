from PIL import Image

""""
creates ascii symbol art from the given image 
image should be in script.py folder
"""

# list the ASCII keys
ASCII_KEYS = ['@', '#', '$', '%', '?', '*', '+', ';', ':', ',', '.']

# resize image according to new width 
def resize_image(image, new_width=100):
    width, height = image.size
    ratio = height / width
    new_height = int(new_width * 0.6)
    resized_image = image.resize((new_width, new_height))
    return resized_image

# convert each pixel to grayscale
def grayscale_image(image):
    grayscaled_image = image.convert("L")
    return grayscaled_image

# convert grayscale pixels to ASCII character
def pixel_to_ascii(image):
    pixels = image.getdata()
    characters = "".join([ASCII_KEYS[pixel//25] for pixel in pixels])
    return characters

# try opening the image 
def main(new_width=100):
    image_name = str(input("Enter Image Name (image.jpg/.png):"))
    try:
        image = Image.open(image_name)
        # convert image to ascii_art
        new_image_data = pixel_to_ascii(grayscale_image(resize_image(image)))

        # format the image 
        pixel_count = len(new_image_data)
        ascii_art   = "\n".join(new_image_data[i:(i+new_width)] for i in range(0, pixel_count, new_width))

        print(ascii_art)

        # print result in ascii_image.txt
        with open(f"{image_name}.txt", 'w') as image:
            image.write(ascii_art)

    except:
        print("Unable to open image. Try Again.")
    

main()
input('')