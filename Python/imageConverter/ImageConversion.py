from PIL import Image
print ('''    Enter 1 for Jpeg to Png
	Enter 2 for PNG to Jpeg
	Enter 3 for Jpeg to WEBP
	Enter 4 for WEBP to Jpeg
	Enter 5 for PNG to WEBP
	Enter 6 for WEBP to PNG''')
choice = int(input("Enter choice :"))
if (choice==1):
	source = Image.open ( r"Photo.jpg" ).convert ("RGB")
	source.save("Photo.png","png")
	print("Conversion Successful :) ")
elif (choice==2):
	source = Image.open ( r"Photo.png" ).convert ("RGB")
	source.save("Photo.jpg","Jpeg")
	print("Conversion Successful :) ")
elif (choice==3):
	source = Image.open ( r"Photo.jpg" ).convert ("RGB")
	source.save("Photo.webp","webp")
	print("Conversion Successful :) ")
elif (choice==4):
	source = Image.open ( r"Photo.webp" ).convert ("RGB")
	source.save("Photo.jpg","Jpeg")
	print("Conversion Successful :) ")
elif (choice==5):
	source = Image.open ( r"Photo.png" ).convert ("RGB")
	source.save("Photo.webp","webp")
	print("Conversion Successful :) ")
elif (choice==6):
	source = Image.open ( r"Photo.webp" ).convert ("RGB")
	source.save("Photo.png","png")
	print("Conversion Successful :) ")

else: 
	print ("Enter Valid Choice")
