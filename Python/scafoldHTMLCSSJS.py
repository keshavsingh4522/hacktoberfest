
import sys
import os

print("Creating {} folder".format(sys.argv[1]))

path = os.path.join(os.getcwd(), sys.argv[1])
os.mkdir(path)

print("Created {} folder".format(sys.argv[1]))

print("Creating index.html, style.css, script.js")

indexHtml= open(sys.argv[1] +"/index.html","w+")

styleCSS= open(sys.argv[1] + "/style.css","w+")

scriptJS= open(sys.argv[1] + "/script.js","w+")

indexHtml.write('''
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Home Page</title>
    <link rel="stylesheet" href="./style">
  </head>
  <body>
  <div style="text-align: center;top: 50%;
left: 50%; position: absolute;
transform: translate(-50%, -50%);">
<h1>Welcome</h1>
</div>
<script src="./script.js" charset="utf-8"></script>
  </body>
  </html>
''')


styleCSS.write('''
*{
font-size: 15px;
font-weight: bold;
}
''')

scriptJS.write('''
function fancyFunction() {
colsole.log("Hello World");
}
''')

indexHtml.close()
styleCSS.close()
scriptJS.close()
