#Set of Questions and Answers
mydatabase = [
    {
        "question": "hello",
        "answer": ["Hi!","Hello","Whassup"]
    },
    {
        "question": "how are you",
        "answer": ["I'm fine..!! How are you doing", "I'm doing good..How are you doing","I'm doing good.. Thanks for asking !..How are you doing"]
    },
    {
        "question": "im good too",
        "answer": ["Thats Nice","Thats Awesome","Thats Cool"]
    }
]

import random

def main():
    while True:
        question = input("You: ")
        got_answer = False
        for response in mydatabase:
            match = True
            for word in response["question"].split():
                if word not in question.lower():
                    match = False
    

            if match:
                print("Bot:", response["answer"][random.randint(0,2)])
                got_answer = True
                break

        if not got_answer:
            print("Bot:", "Sorry, I didn't get it.")
            
            restart = input("Do you wish to ask new question  :")
            if restart == "yes":
                main()

            else :
                print("Bye Byee , Have a nice day!!")  
                
 #Run Main
main()
