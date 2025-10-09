import random,pygame,sys
from pygame.locals import *

fps=30
wnwidth=640
wnheight=480
revelspeed=8
boxsize=40
gapsize=10
boardwidth=10
boardheight=7
assert (boardwidth*boardheight)%2==0,'Board need to have even number of boxes for pair of matches.'
xmargin=int((wnwidth-(boardwidth*(boxsize+gapsize)))/2)
ymargin=int((wnheight-(boardheight*(boxsize+gapsize)))/2)

gray=(100,100,100)
navyblue=(60,60,100)
white=(255,255,255)
red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)
yellow=(255,255,0)
orange=(255,128,0)
purple=(255,0,255)
cyan=(0,255,255)

bgcolor=navyblue
lightbgcolor=gray
boxcolor=white
highlightcolor=blue

Donut='donut'
Square='square'
Diamond='diamond'
Lines='lines'
Oval='oval'

allcolor=(red,green,blue,yellow,orange,purple,cyan)
allshape=(Donut,Square,Diamond,Lines,Oval)
assert len(allcolor)*len(allshape)*2>=boardwidth*boardheight,"Board is too big for the number of shapes/colors defined"

def main():
    global fpsclock,Display
    pygame.init()
    fpsclock=pygame.time.Clock()
    Display=pygame.display.set_mode((wnwidth,wnheight))

    mousex=0
    mousey=0
    pygame.display.set_caption(("Memory Puzzle"))
    mainboard=getRandomizedBoard()
    revealedboxes=generateRevealedBoxesData(False)

    firstselection=None

    Display.fill(bgcolor)
    startGameAnimation(mainboard)

    while True:
        mouseclicked=False
        Display.fill(bgcolor)
        drawBoard(mainboard,revealedboxes)

        for event in pygame.event.get():
            if event.type==QUIT or (event.type==KEYUP and event.key==K_ESCAPE):
                pygame.quit()
                sys.exit()
            
            elif event.type==MOUSEBUTTONUP:
                mousex,mousey=event.pos
                mouseclicked=True

        boxx,boxy=getBoxAtPixel(mousex,mousey)

        if boxx!=None and boxy!=None:
            if not revealedboxes[boxx][boxy]:
                drawHighlightBox(boxx,boxy)
            if not revealedboxes[boxx][boxy] and mouseclicked:
                revealBoxesAnimation(mainboard,[(boxx,boxy)])
                revealedboxes[boxx][boxy]=True

                if firstselection==None:
                    firstselection=(boxx,boxy)
                else:
                    icon1shape,icon1color=getShapeAndColor(mainboard,firstselection[0],firstselection[1])
                    icon2shape,icon2color=getShapeAndColor(mainboard,boxx,boxy)
                    if icon1shape!=icon2shape or icon1color!=icon2color:
                        pygame.time.wait(1000)
                        coverBoxesAnimation(mainboard,[(firstselection[0],firstselection[1]),(boxx,boxy)])
                        revealedboxes[firstselection[0]][firstselection[1]]=False
                        revealedboxes[boxx][boxy]=False
                    elif hasWon(revealedboxes):
                        gameWonAnimation(mainboard)
                        pygame.time.wait(1000)

                        mainboard=getRandomizedBoard()
                        revealedboxes=generateRevealedBoxesData(False)

                        drawBoard(mainboard,revealedboxes)
                        pygame.display.update()
                        pygame.time.wait(1000)

                        startGameAnimation(mainboard)
                    firstselection=None
        pygame.display.update()
        fpsclock.tick(fps)

def generateRevealedBoxesData(val):
    revealedboxes=[]
    for i in range(boardwidth):
        revealedboxes.append([val]*boardheight)
    return revealedboxes

def getRandomizedBoard():
    icons=[]
    for color in allcolor:
        for shape in allshape:
            icons.append( (shape,color) )

    random.shuffle(icons)
    numIconsUsed= int(boardwidth*boardheight/2)
    icons=icons[:numIconsUsed]*2
    random.shuffle(icons)

    board=[]
    for x in range(boardwidth):
        column=[]
        for y in range(boardheight):
            column.append(icons[0])
            del icons[0]
        board.append(column)
    return board

def splitIntoGroupOf(groupsize,thelist):

    result=[]
    for i in range(0,len(thelist),groupsize):
        result.append(thelist[i:i+groupsize])
    return result

def leftTopCoordsOfBox(boxx,boxy):
    left=boxx*(boxsize+gapsize)+xmargin
    top=boxy*(boxsize+gapsize)+ymargin
    return (left,top)

def getBoxAtPixel(x,y):
    for boxx in range(boardwidth):
        for boxy in range(boardheight):
            left,top=leftTopCoordsOfBox(boxx,boxy)
            boxRect=pygame.Rect(left,top,boxsize,boxsize)
            if boxRect.collidepoint(x,y):
                return (boxx,boxy)
    return (None,None)

def drawIcon(shape,color,boxx,boxy):
    quarter=int(boxsize*0.25)
    half=int(boxsize*0.5)

    left,top=leftTopCoordsOfBox(boxx,boxy)
    if shape==Donut:
        pygame.draw.circle(Display,color,(left+half,top+half),half-5)
        pygame.draw.circle(Display,bgcolor,(left+half,top+half),quarter-5)
    elif shape==Square:
        pygame.draw.rect(Display,color,(left+quarter,top+quarter,boxsize-half,boxsize-half))
    elif shape==Diamond:
        pygame.draw.polygon(Display,color,((left+half,top),(left+boxsize-1,top+half),(left+half,top+boxsize-1),(left,top+half)))
    elif shape==Lines:
        for i in range(0,boxsize,4):
            pygame.draw.line(Display,color,(left,top+i),(left+i,top))
            pygame.draw.line(Display,color,(left+i,top+boxsize-1),(left+boxsize-1,top+i))
    elif shape==Oval:
        pygame.draw.ellipse(Display,color,(left,top+quarter,boxsize,half))

def getShapeAndColor(board,boxx,boxy):
        return board[boxx][boxy][0],board[boxx][boxy][1]

def drawBoxCover(board,boxes,coverage):

    for box in boxes:
        left,top=leftTopCoordsOfBox(box[0],box[1])
        pygame.draw.rect(Display,bgcolor,(left,top,boxsize,boxsize))
        shape,color=getShapeAndColor(board,box[0],box[1])
        drawIcon(shape,color,box[0],box[1])
        if coverage>0:
            pygame.draw.rect(Display,bgcolor,(left,top,coverage,boxsize))
            pygame.display.update()
            fpsclock.tick(fps)

def revealBoxesAnimation(board,boxesToReveal):
    for coverage in range(boxsize,(-revelspeed)-1,-revelspeed):
        drawBoxCover(board,boxesToReveal,coverage)

def coverBoxesAnimation(board,boxesToCover):
    for coverage in range(0,boxsize+revelspeed,revelspeed):
        drawBoxCover(board,boxesToCover,coverage)

def drawBoard(board,revealed):
    for boxx in range(boardwidth):
        for boxy in range(boardheight):
            left,top=leftTopCoordsOfBox(boxx,boxy)
            if not revealed[boxx][boxy]:
                pygame.draw.rect(Display,boxcolor,(left,top,boxsize,boxsize))
                shape,color=getShapeAndColor(board,boxx,boxy)
                drawIcon(shape,color,boxx,boxy)

def drawHighlightBox(boxx,boxy):
    left,top=leftTopCoordsOfBox(boxx,boxy)
    pygame.draw.rect(Display,highlightcolor,(left-5,top-5,boxsize+10,boxsize+10),4)

def startGameAnimation(board):
    coveredBoxes=generateRevealedBoxesData(False)
    boxes=[]
    for x in range(boardwidth):
        for y in range(boardheight):
            boxes.append((x,y))
    random.shuffle(boxes)
    boxGroups= splitIntoGroupOf(8,boxes)

    drawBoard(board,coveredBoxes)
    for boxGroup in boxGroups:
        revealBoxesAnimation(board,boxGroup)
        coverBoxesAnimation(board,boxGroup)

def gameWonAnimation(board):
    coveredBoxes=generateRevealedBoxesData(True)
    color1=lightbgcolor
    color2=bgcolor

    for i in  range(13):
        color1,color2=color2,color1
        Display.fill(color1)
        drawBoard(board,coveredBoxes)
        pygame.display.update()
        pygame.time.wait(300)

def hasWon(revealedBoxes):
    for i in revealedBoxes:
        if False in i:
            return False
        return True

if __name__=='__main__':
    main()


















































