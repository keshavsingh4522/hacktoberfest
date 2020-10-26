import optparse, zipfile
from threading import Thread

def extrackFile(zFile, password):
    try:
        zFile.extractall(pwd=password)
        print("[+] Found password" + password + '\n')
    except:
        pass

def main():
    usage = ''' Zip Passeord cracker v0.1
    created by c0d3r
    email: F0c3 u
    ################################
    usage:
    python2 unzip.py -f zipfilename.zip -d dictionary name
    or
    python unzip.py -f zipfilename.zip -d dictionary name
    or
    ./unzip.py -f zipfilename.zip -d dictionary name'''
    parser = optparse.OptionParser(usage)
    parser.add_option('-f', dest='zname', type='string', help='Enter the full zip filename')
    parser.add_option('-d', dest='dname', type='string', help='Enter the full dictionary filename')
    (options, args) = parser.parse_args()
    if (options.zname == None) | (options.dname == None):
        print(parser.usage)
        exit(5)
    else:
        zname = options.zname
        dname = options.dname
    zFile = zipfile.ZipFile(zname)
    passFile = open(dname)
    for line in passFile.readlines():
        password = line.strip('\n')
        t = Thread(target=extrackFile, args=(zFile, password))

if __name__ == '__main__':
    main()
