# mini_adventure_game.py
import random

def mini_adventure_game():
    print("🗺️ Welcome to the Mini Adventure Game!")
    print("You are on a quest to find the hidden treasure.\n")

    paths = ["forest", "cave", "river"]
    treasures = ["gold coins", "a magic sword", "an ancient scroll"]
    obstacles = ["a wild beast", "a sneaky trap", "a dark fog"]

    while True:
        print(f"Paths available: {', '.join(paths)}")
        choice = input("Which path will you take? ").lower()

        if choice not in paths:
            print("⚠️ Invalid path. Choose wisely!")
            continue

        encounter = random.choice(obstacles + treasures)
        if encounter in treasures:
            print(f"🎉 You found {encounter}! You win!")
        else:
            print(f"💀 Oh no! You encountered {encounter}. You lose!")
        
        replay = input("Do you want to play again? (yes/no): ").lower()
        if replay != "yes":
            print("Thanks for playing! 🏆")
            break

if __name__ == "__main__":
    mini_adventure_game()
