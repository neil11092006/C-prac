import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game!")
    print("Im thinking of a number between 1 and 100.")

    secret_number = random.randint(1, 100)
    attempts = 0

    while True:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1

            if guess < 1 or guess > 100:
                print("Please enter a number between 1 and 100!")
                continue

            if guess < secret_number:
                print("Too Low! Try again.")
            elif guess > secret_number:
                print("Too High! Try again.")
            else:
                print(f"Congratulations! You guessed it in {attempts} attempts.")
                break

        except ValueError:
            print("Invalid input. Please enter a number.")

number_guessing_game()
