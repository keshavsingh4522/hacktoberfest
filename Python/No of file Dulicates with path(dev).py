import os, pdb


d={'m' : ['.mp3','.m4a','.wav','.flac'],
'v' : ['.mp4','.flv','.mkv','.3gp','.mpeg'],
'p' : ['.jpg','.png','.jpeg']
}

p=input('\tPath : \n\t')
print("\n\n\t For Music : Enter 'm' \n\t For Videos : Enter 'v' \n\t For Pictures : Enter 'p' \n\t Or give the file extention with '.' like : '.py','.pdf','.xls' etc . . . . \n\n")
k=input('Give extention of the files : ').lower()
xtntn=d.get(k,k)
l=[]
m=[]

for path,folders,files in os.walk(p) :
	for file in files :
		for x in xtntn :
			if file.endswith(x) :
				l.append(file)
				m.append(path)
i=0
while i<len(l) :
	c=0
	s=l[i]
	j=i+1
	while j<len(l):
		t=l[j]
		if s == t:
			print(f'File Name : {s}')
			print(f'\tDefault Path : {m[i]}')
			print(f'found.....!!!')
			print(f'\tPath   :    {m[j]}')
			l.remove(l[j])
			c+=1
		j+=1
	i+=1
	if c != 0 :
		print(f'\n\tCopies : {c}\n\n\n')