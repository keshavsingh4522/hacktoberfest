import random

# Define rooms and their descriptions
rooms = {
    "start": {
        "description": "You find yourself at the entrance of a mysterious castle.",
        "options": ["Enter the castle", "Turn back"]
    },
    "castle_entrance": {
        "description": "You enter the castle and discover two doors. One is labeled 'Library,' and the other is 'Dungeon.'",
        "options": ["Go to the Library", "Explore the Dungeon", "Return to the entrance"]
    },
    "library": {
        "description": "You're in a dusty library filled with ancient books. You see a book with a strange symbol on the cover. What will you do?",
        "options": ["Read the book", "Leave the library"]
    },
    "dungeon": {
        "description": "The dungeon is dark and damp. You hear mysterious noises coming from deeper inside. What's your choice?",
        "options": ["Venture deeper into the dungeon", "Return to the entrance"]
    },
    "book": {
        "description": "As you open the book, a burst of light surrounds you, and you gain magical powers. You win!",
        "options": []
    },
    "deeper_dungeon": {
        "description": "You encounter a fearsome dragon. What will you do?",
        "options": ["Fight the dragon", "Flee back to the entrance"]
    },
    "fight_dragon": {
        "description": "You engage in an epic battle with the dragon. You emerge victorious and find a hidden treasure. You win!",
        "options": []
    },
    "flee_dragon": {
        "description": "You run away from the dragon, narrowly escaping. You return to the entrance.",
        "options": ["Go to the Library", "Return to the entrance"]
    }
}

# Game function
def play_game():
    current_room = "start"
    
    while True:
        print("\n" + rooms[current_room]["description"])
        options = rooms[current_room]["options"]
        
        if not options:
            print("Thanks for playing the Insane Game!")
            break
        
        valid_choices = [str(i) for i in range(1, len(options) + 1)]
        choice = input("Enter the number of your choice: ")
        
        if choice in valid_choices:
            chosen_option = options[int(choice) - 1]
            if chosen_option == "Enter the castle":
                current_room = "castle_entrance"
            elif chosen_option == "Go to the Library":
                current_room = "library"
            elif chosen_option == "Explore the Dungeon":
                current_room = "dungeon"
            elif chosen_option == "Read the book":
                current_room = "book"
            elif chosen_option == "Venture deeper into the dungeon":
                current_room = "deeper_dungeon"
            elif chosen_option == "Fight the dragon":
                current_room = "fight_dragon"
            elif chosen_option == "Flee back to the entrance":
                current_room = "flee_dragon" if current_room == "deeper_dungeon" else "castle_entrance"
            elif chosen_option == "Leave the library":
                current_room = "castle_entrance"
            elif chosen_option == "Return to the entrance":
                current_room = "start"
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    play_game()
