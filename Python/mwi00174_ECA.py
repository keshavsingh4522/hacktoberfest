import random

#
# NAME:Oarabile Mwiya
# ID  :201700174.
#   ECA

# VectorAdd() returns a vector obtained by adding two vectors,
#which are parameters of the function
# result is a vector
def VectorAdd(a,b):

	#Check equality of the vectors
    assert len(a)==len(b)
	
	#Initialise an empty vector list
    newVector = []
	
	#Iterate with respect to the vector length and add corresponding values
    for i in range(len(a)):
	
            v = a[i] + b[i]
			
            newVector.append(v)
    
    
    return newVector
#  performs vector subtraction on two vectors and returns a 
# vector
def VectorSub(a,b):
	#check if length of vectors are equal
    assert len(a)==len(b)
	
	#Initialize an empty vector list
    newVector = []
	
	#Iterate the  indices wrt to vector length and subtract corresponding values
    for i in range(len(a)):
	
            v = a[i] - b[i]
			
            newVector.append(v)
			
    return newVector


# Implement this: VectorMult() performs vector multiplication and returns a scalar 
# (number)
def VectorMult(a,b):
	#compare length equality of vector a and b
    assert len(a)==len(b)
	
    total =  0
	
	#Iterate the vector indices wrt to the vector length and multiply corresponding values
    for i in range(len(a)):
            v = a[i] * b[i]
            total = total + v
    return total


# DO NOT MODIFY THIS FUNCTION
def argMax(scores):
        """
        Returns the key with the highest value.
        """
        if len(scores) == 0: return None
        all = scores.items()
        values = [x[1] for x in all]
        maxIndex = values.index(max(values))
        return all[maxIndex][0]


#MulticlassPerceptronLearning Function

def MulticlassPerceptronLearning(trainingvectors):

        #Initalize weight
        weights={'A':[0,0,0],'B':[0,0,0],'C':[0,0,0]}
		
        #Set threshold to zero
        threshold = 0  
		
       #Initialize scores of class(A,B,C respectively  )
        scoreA = 0
		
        scoreB = 0
		
        scoreC = 0

        #Check if selected apple is bad
        Badapple = True

        #Feature Vector for apples
        VectorApples = ""
		
        #Declare and initialize variable iteration
        iteration = 0

        #Run the loop for a thousand iterations and check if a Bad apple is found
        while(Badapple == True and iteration < 1000):

                #Initialize empty list for classification
                classification = []
				
                #Increment variable iteration by 1 and ouput each iteration at each interval
                iteration += 1
                print "\nIteration Number:",iteration
				
                #Iterate apples in the trainingvectors using for loop
                for AppleVector in trainingvectors:
                        
                        #Distiguish apart classless features
                        appleFeatures = [AppleVector[0], AppleVector[1]]

                        #Instance of the current feature vector
                        VectorApples = AppleVector[2]
                        
                        #Threshold is appended to the feature vector
                        appleFeatures.append(1)

                        # Feature vectors mutplied with correspong weight vectors
						
                        scoreA = VectorMult(appleFeatures, weights['A'])
						
                        scoreB = VectorMult(appleFeatures, weights['B'])
						
                        scoreC = VectorMult(appleFeatures, weights['C'])

                        #Scores stored in a dictionary
                        scores = {'A': scoreA, 'B': scoreB, 'C': scoreC}

                        #Using percept identify class with highest score
                        MaximumClass = argMax(scores)
						
						#Check if The highest score correspond with the Current class
                        if(MaximumClass != VectorApples):

                                 #Subtract Apple Feature Vector From Incorrect Class Vector and output desired results
                                print "Bad Apple Detectad : ",AppleVector                                
                               
                                bad = VectorSub(weights[MaximumClass],appleFeatures)
                              
                                weights[MaximumClass] = bad
                                
                                #Add Apple Feature Vector To Correct Class Vector
								
                                Good = VectorAdd(weights[VectorApples],appleFeatures)
                               
                                weights[VectorApples] = Good

                                #append bad apples to classification list
                                classification.append("Bad")

                        #If its highest score classify it a good apple in list then transcend to next iteration
                        else:
                                classification.append("Good")

                print "\AFTER ITERATION NUMBER:",iteration
                print weights

                # Check If Bad Apple Was Found 
                if "Bad" in classification:
                        Badapple = True
                else:
                        Badapple = False

        print "\n\nFinal W:",weights
        return weights





 #LoadFile function to load file                                

def LoadFile(fileName):

        dataFile=open(fileName,"r")

        #Initalize empty apples list
        Apples = []
		
		#Intialize empty firstlist variable
        firstlist = []
		
		#Initialize empty secondlist variable
        secondlist = []

        #start from the first value in tha data file
        next(dataFile)

        #Iterate line by line the data txt file
        for line in dataFile:
		
				#Our data file cointains list of apples in terms of(color ,size and class) thus use them to split data
                #Use split to convert each corresponding line into an array
                lineSplit = line.split()

                #Split color from the data text and store in array..
                color = float(lineSplit[0])
				
                #split size from the data text and store in array..
                size = float(lineSplit[1])

                #Append the split features into apples empty list ..
                Apples.append([color,size,lineSplit[2]])

        #Random number seed generator
        random.seed(2)

        #Randomise apples
        random.shuffle(Apples)
		
		# system must read in the data file, split such that 70% of apples are used for training and 30% for testing
        #Extract first 84apples which is 70% for training
        firstlist = Apples[:84]
        
         #Extract last  84apples which is 70% for training
        secondlist = Apples[84:]
        
        #Return list
        return firstlist,secondlist

#Evaluate Function(Interpretation of classified apples)..
def Evaluate(weights,appleVectors):

        numapples=len(appleVectors)
        numcorrect=0
		
       #Initialize scores of class(A,B,C respectively  )
        scoreA = 0
		
        scoreB = 0
		
        scoreC = 0

        print "\n\nAPPLES CLASSIFICATION"
		
        #Iterate apples in apple set
        for SetApples in appleVectors:
                
                # Extract cost and  size
                appleFeatures = [SetApples[0], SetApples[1]]

                # Set vector to apples class
                VectorApples = SetApples[2]
                
                #Threshold appended to vector
                appleFeatures.append(1)
                print "\n\n Apple Being Classified:",SetApples

                # Feature vectors mutplied with correspong weight vectors
                scoreA = VectorMult(appleFeatures, weights['A'])
				
                scoreB = VectorMult(appleFeatures, weights['B'])
				
                scoreC = VectorMult(appleFeatures, weights['C'])

                #Scores stored in a dictionary
                scores = {'A': scoreA, 'B': scoreB, 'C': scoreC}

                # Determine Class With Max Score
                MaximumClass = argMax(scores)

                print "Maximum Class Score : ",MaximumClass

				#Check if max class equals the current apple class and iterate if condition met
                if(MaximumClass == VectorApples):
                        numcorrect+=1
                

        return round(float(numcorrect)/numapples*100,2)



# DO NOT MODIFY THIS FUNCTION    
def RunExperiment():
    training,testing=LoadFile("data.txt")
    w=MulticlassPerceptronLearning(training)
    score=Evaluate(w,testing)
    
    print "Evaluation Score:",score

RunExperiment()


#Performance of Machine Learning model****
# The model has an evaluation score of 97.22 which is much closer to a perfect score (100) which derives
#that the model can clearly classify apples as bad or good apples based on the color , size and class.
