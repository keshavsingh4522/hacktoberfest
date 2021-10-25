import sys,os,pygame,random,math

pygame.init()
pygame.display.set_caption("zmijurina")
pygame.font.init()
random.seed()

#Global constant definitions
BRZINA = 0.36
VELICINA_ZMIJE = 9
VELICINA_JABUKE = VELICINA_ZMIJE
RAZMAK = 10
VISINA_EKRANA = 600
SIRINA_EKRANA = 800
FPS = 25
KEY = {"UP":1,"DOWN":2,"LEFT":3,"RIGHT":4}

screen = pygame.display.set_mode((SIRINA_EKRANA,VISINA_EKRANA),pygame.HWSURFACE)



score_font = pygame.font.Font(None,38)
score_numb_font = pygame.font.Font(None,28)

score_poruka = score_font.render("Score:",1,pygame.Color("green"))
score_poruka_velicina = score_font.size("Score")


background_color = pygame.Color(74,74,74)



gameClock = pygame.time.Clock()


def provjeriDodir(posA,As,posB,Bs):
    if(posA.x   < posB.x+Bs and posA.x+As > posB.x and posA.y < posB.y + Bs and posA.y+As > posB.y):
        return True
    return False

def provjeriLimit(entity):
    if(entity.x > SIRINA_EKRANA):
        entity.x = VELICINA_ZMIJE
    if(entity.x < 0):
        entity.x = SIRINA_EKRANA - VELICINA_ZMIJE
    if(entity.y > VISINA_EKRANA):
        entity.y = VELICINA_ZMIJE
    if(entity.y < 0):
        entity.y = VISINA_EKRANA - VELICINA_ZMIJE
        
class Jabuka:
    def __init__(self,x,y,state):
        self.x = x
        self.y = y
        self.state = state
        self.color = pygame.color.Color("red")
    def draw(self,screen):
        pygame.draw.rect(screen,self.color,(self.x,self.y,VELICINA_JABUKE,VELICINA_JABUKE),0)
        
class Segment:
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.direction = KEY["UP"]
        self.color = "white"
        
class Zmija:
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.direction = KEY["UP"]
        self.stack = []
        
        self.stack.append(self)
        
        blackBox = Segment(self.x,self.y + RAZMAK)
        blackBox.direction = KEY["UP"]
        blackBox.color = "blue"
        self.stack.append(blackBox)

        
        
    def kretanje(self):
        zadnji_element = len(self.stack)-1
        while(zadnji_element != 0):
            self.stack[zadnji_element].direction = self.stack[zadnji_element-1].direction
            self.stack[zadnji_element].x = self.stack[zadnji_element-1].x 
            self.stack[zadnji_element].y = self.stack[zadnji_element-1].y 
            zadnji_element-=1
        if(len(self.stack)<2):
            zadnji_element = self
        else:
            zadnji_element = self.stack.pop(zadnji_element)
        zadnji_element.direction = self.stack[0].direction
        if(self.stack[0].direction ==KEY["UP"]):
            zadnji_element.y = self.stack[0].y - (BRZINA * FPS)
        elif(self.stack[0].direction == KEY["DOWN"]):
            zadnji_element.y = self.stack[0].y + (BRZINA * FPS) 
        elif(self.stack[0].direction ==KEY["LEFT"]):
            zadnji_element.x = self.stack[0].x - (BRZINA * FPS)
        elif(self.stack[0].direction == KEY["RIGHT"]):
            zadnji_element.x = self.stack[0].x + (BRZINA * FPS)
        self.stack.insert(0,zadnji_element)

    def getHead(self):
        return(self.stack[0])
    
    def narasti(self):
        zadnji_element = len(self.stack)-1
        self.stack[zadnji_element].direction = self.stack[zadnji_element].direction
        if(self.stack[zadnji_element].direction == KEY["UP"]):
            noviSegment = Segment(self.stack[zadnji_element].x,self.stack[zadnji_element].y-VELICINA_ZMIJE)
            blackBox = Segment(noviSegment.x,noviSegment.y-RAZMAK)
            
        elif(self.stack[zadnji_element].direction == KEY["DOWN"]):
            noviSegment = Segment(self.stack[zadnji_element].x,self.stack[zadnji_element].y+VELICINA_ZMIJE)
            blackBox = Segment(noviSegment.x,noviSegment.y+RAZMAK)
            
        elif(self.stack[zadnji_element].direction == KEY["LEFT"]):
            noviSegment = Segment(self.stack[zadnji_element].x-VELICINA_ZMIJE,self.stack[zadnji_element].y)
            blackBox = Segment(noviSegment.x-RAZMAK,noviSegment.y)
            
        elif(self.stack[zadnji_element].direction == KEY["RIGHT"]):
            noviSegment = Segment(self.stack[zadnji_element].x+VELICINA_ZMIJE,self.stack[zadnji_element].y)
            blackBox = Segment(noviSegment.x+RAZMAK,noviSegment.y)
            
        blackBox.color = "blue"
        self.stack.append(noviSegment)
        self.stack.append(blackBox)
        
    
    
    def postaviSmjer(self,direction):
        if(self.direction == KEY["RIGHT"] and direction == KEY["LEFT"] or self.direction == KEY["LEFT"] and direction == KEY["RIGHT"]):
            pass
        elif(self.direction == KEY["UP"] and direction == KEY["DOWN"] or self.direction == KEY["DOWN"] and direction == KEY["UP"]):
            pass
        else:
            self.direction = direction
            
    
    
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
    def setX(self,x):
        self.x = x
        
    def setY(self,y):
        self.y = y
        
    def provjeriSudar(self):
        counter = 1
        while(counter < len(self.stack)-1):
            if(provjeriDodir(self.stack[0],VELICINA_ZMIJE,self.stack[counter],VELICINA_ZMIJE)):
                return True
            counter+=1
        return False
    
    def draw(self,screen):
        pygame.draw.rect(screen,pygame.color.Color("yellow"),(self.stack[0].x,self.stack[0].y,VELICINA_ZMIJE,VELICINA_ZMIJE),0)
        counter = 1
        while(counter < len(self.stack)):
            
            pygame.draw.rect(screen,pygame.color.Color("white"),(self.stack[counter].x,self.stack[counter].y,VELICINA_ZMIJE,VELICINA_ZMIJE),0)
            counter+=1
        
                
def getKey():
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    return KEY["UP"]
                elif event.key == pygame.K_DOWN:
                    return KEY["DOWN"]
                elif event.key == pygame.K_LEFT:
                    return KEY["LEFT"]
                elif event.key == pygame.K_RIGHT:
                    return KEY["RIGHT"]
                elif event.key == pygame.K_ESCAPE:
                    return "exit"
                
            if event.type == pygame.QUIT:
                sys.exit()

def stvoriJabuku(jabuke,index,sx,sy):
    radius = math.sqrt((SIRINA_EKRANA/2*SIRINA_EKRANA/2  + VISINA_EKRANA/2*VISINA_EKRANA/2))/2
    angle = 999
    while(angle > radius):
        angle = random.uniform(0,800)*math.pi*2
        x = SIRINA_EKRANA/2 + radius * math.cos(angle)
        y = VISINA_EKRANA/2 + radius * math.sin(angle)
        if(x == sx and y == sy):
            continue
    novaJabuka = Jabuka(x,y,1)
    jabuke[index] = novaJabuka
        
def stvoriJabuke(jabuke,quantity,sx,sy):
    counter = 0
    del jabuke[:]
    radius = math.sqrt((SIRINA_EKRANA/2*SIRINA_EKRANA/2  + VISINA_EKRANA/2*VISINA_EKRANA/2))/2
    angle = 999
    while(counter < quantity):
        while(angle > radius):
            angle = random.uniform(0,800)*math.pi*2
            x = SIRINA_EKRANA/2 + radius * math.cos(angle)
            y = VISINA_EKRANA/2 + radius * math.sin(angle)
            if( (x-VELICINA_JABUKE == sx or x+VELICINA_JABUKE == sx) and (y-VELICINA_JABUKE == sy or y+VELICINA_JABUKE == sy) or radius - angle <= 10):
                continue
        jabuke.append(Jabuka(x,y,1))
        angle = 999
        counter+=1
        


def nacrtajScore(score):
    score_numb = score_numb_font.render(str(score),1,pygame.Color("red"))
    screen.blit(score_poruka, (SIRINA_EKRANA-score_poruka_velicina[0]-60,10) )
    screen.blit(score_numb,(SIRINA_EKRANA - 45,14))
    

def exitScreen():
    pass

def main():
    score = 0

    #Zmija
    mojaZmija = Zmija(SIRINA_EKRANA/2,VISINA_EKRANA/2)
    mojaZmija.postaviSmjer(KEY["UP"])
    mojaZmija.kretanje()
    start_segmenti=3
    while(start_segmenti>0):
        mojaZmija.narasti()
        mojaZmija.kretanje() 
        start_segmenti-=1

    #Jabuke
    max_jabuka = 1
    pojedena_jabuka = False
    jabuke = [Jabuka(random.randint(60,SIRINA_EKRANA),random.randint(60,VISINA_EKRANA),1)]
    stvoriJabuke(jabuke,max_jabuka,mojaZmija.x,mojaZmija.y)
    
    
    zavrsiIgru = 0
    
    while(zavrsiIgru!=1):
        gameClock.tick(FPS)

        
        keyPress = getKey()
        if keyPress == "exit":
            zavrsiIgru = 1
       
        #Provjeravanje dodira
        provjeriLimit(mojaZmija)
        if(mojaZmija.provjeriSudar()== True):
            sys.exit()
            
            
            
        for mojaJabuka in jabuke:
            if(mojaJabuka.state == 1):
                if(provjeriDodir(mojaZmija.getHead(),VELICINA_ZMIJE,mojaJabuka,VELICINA_JABUKE)==True):
                    mojaZmija.narasti()
                    mojaJabuka.state = 0
                    score+=5
                    pojedena_jabuka=True
            

        #Osvjezavanje Pozicije
        if(keyPress):
            mojaZmija.postaviSmjer(keyPress)    
        mojaZmija.kretanje()
        
        
        
        #Stvaranje Jabuka
        if(pojedena_jabuka == True):
            pojedena_jabuka = False
            stvoriJabuku(jabuke,0,mojaZmija.getHead().x,mojaZmija.getHead().y)

        #Crtanje
        screen.fill(background_color)
        for mojaJabuka in jabuke:
            if(mojaJabuka.state == 1):
                mojaJabuka.draw(screen)
                
                
        mojaZmija.draw(screen)
        nacrtajScore(score)
       
        
        pygame.display.flip()
        pygame.display.update()
        
       
        
        
        
main()
