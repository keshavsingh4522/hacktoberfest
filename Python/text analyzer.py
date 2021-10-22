from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer  
  
# import all methods and classes from the tkinter  
from tkinter import *
  

def clearAll() :  
    
    # deleting the content from the entry box  
    negativeField.delete(0, END)  
    neutralField.delete(0, END)  
    positiveField.delete(0, END)  
    overallField.delete(0, END)  
  
    # whole content of text area  is deleted  
    textArea.delete(1.0, END) 
      

def detect_sentiment(): 
  
    # get a whole input content from text box 
    sentence = textArea.get("1.0", "end") 
  
    # Create a SentimentIntensityAnalyzer object.  
    sid_obj = SentimentIntensityAnalyzer()  
  
    
    sentiment_dict = sid_obj.polarity_scores(sentence)  
  
    string = str(sentiment_dict['neg']*100) + "% Negative"
    negativeField.insert(10, string) 
      
  
    string = str(sentiment_dict['neu']*100) + "% Neutral"
    neutralField.insert(10, string) 
  
    string = str(sentiment_dict['pos']*100) +"% Positive"
    positiveField.insert(10, string) 
      
    # decide sentiment as positive, negative and neutral  
    if sentiment_dict['compound'] >= 0.05 : 
        string = "Positive"
  
    elif sentiment_dict['compound'] <= - 0.05 : 
        string = "Negative"
       
  
    else : 
        string = "Neutral"
  
    overallField.insert(10, string) 
          
  
  
# Driver Code  
if __name__ == "__main__" : 
      
  
    # Create a GUI window  
    gui = Tk()  
      
    # Set the background colour of GUI window  
    gui.config(background =  "light green")  
  
    # set the name of tkinter GUI window  
    gui.title("Sentiment Detector")  
  
    # Set the configuration of GUI window  
    gui.geometry("250x400")  
  
    # create a label : Enter Your Task  
    enterText = Label(gui, text = "Enter Your Sentence", 
                                     bg = "light green") 
  
   
    textArea = Text(gui, height = 5, width = 25, font = "lucida 13") 
  
    
    check = Button(gui, text = "Check Sentiment", fg = "Black",  
                         bg = "red", command = detect_sentiment) 
  
    # Create a negative : label  
    negative = Label(gui, text = "sentence was rated as: ", 
                                        bg = "light green")  
    
    # Create a neutral : label  
    neutral = Label(gui, text = "sentence was rated as: ",  
                                       bg = "light green")  
    
    # Create a positive : label  
    positive = Label(gui, text = "sentence was rated as: ", 
                                        bg = "light green") 
  
    # Create a overall : label  
    overall = Label(gui, text = "Sentence Overall Rated As: ", 
                                           bg = "light green") 
  
    # create a text entry box   
    negativeField = Entry(gui) 
  
    # create a text entry box   
    neutralField = Entry(gui) 
  
    # create a text entry box   
    positiveField = Entry(gui) 
  
    # create a text entry box   
    overallField = Entry(gui)  
  

    clear = Button(gui, text = "Clear", fg = "white",  
                      bg = "grey", command = clearAll) 
      

    Exit = Button(gui, text = "Exit", fg = "white",  
                        bg = "blue", command = exit) 
  

    enterText.grid(row = 0, column = 2) 
      
    textArea.grid(row = 1, column = 2, padx = 10, sticky = W) 
      
    check.grid(row = 2, column = 2) 
      
    negative.grid(row = 3, column = 2) 
      
    neutral.grid(row = 5, column = 2) 
      
    positive.grid(row = 7, column = 2) 
      
    overall.grid(row = 9, column = 2) 
      
    negativeField.grid(row = 4, column = 2) 
  
    neutralField.grid(row = 6, column = 2) 
                        
    positiveField.grid(row = 8, column = 2) 
      
    overallField.grid(row = 10, column = 2) 
      
    clear.grid(row = 11, column = 2) 
      
    Exit.grid(row = 12, column = 2) 
   
    gui.mainloop()  
     
