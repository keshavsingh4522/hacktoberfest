import os
import aiml

BOT_NAME = "Nicole"
USER_NAME = "Raj"
BRAIN_FILE = "bot_brain.brn"

def create_kernel():
    kernel = aiml.Kernel()
    kernel.verbose(False)
    kernel.setBotPredicate("name", BOT_NAME)
    kernel.setPredicate("name", USER_NAME)
    
    if os.path.isfile(BRAIN_FILE):
        kernel.bootstrap(brainFile=BRAIN_FILE)
    else:
        kernel.bootstrap(learnFiles="startup.xml", commands="LOAD AIML B")
        
    return kernel

def chat():
    print("Session Initiated. Type your message.")
    
    kernel = create_kernel()
    
    while True:
        message = input("")
        
        if message.upper() == "EXIT":
            break
            
        response = kernel.respond(message)
        print(f">>> {response}")
        
    kernel.saveBrain(BRAIN_FILE)
    print("Session Ended")

if __name__ == "__main__":
    chat()
