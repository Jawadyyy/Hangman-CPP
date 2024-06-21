# Hangman Game

A simple console-based Hangman game developed in C++. Players guess letters to uncover a hidden word within a limited number of attempts.

## Table of Contents
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Features](#features)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. **Copy or Download the Code:**

    You can either copy the code from the repository or download it as a ZIP file.

    - **To download as a ZIP file:**
      - Go to the repository page on GitHub.
      - Click on the "Code" button.
      - Select "Download ZIP".

2. **Compile and Run the Code:**

    Ensure you have a C++ compiler installed. You can use `g++`:

    ```sh
    g++ -o hangman Hangman Game.cpp
    ```

    Then, run the game:

    ```sh
    ./hangman
    ```

## How to Play

1. **Start the Game:**

    Run the executable file. You will be prompted to enter your name.

2. **Select a Theme:**

    Choose a category for the word: Animals, Countries, Fruits, Sports, or Colors.

3. **Guess the Word:**

    You will see a series of underscores representing the letters in the word. Enter letters one by one to guess the word.

4. **Hints and Chances:**

    You have a limited number of attempts (7 chances). If you run out of chances, you lose the game. If you guess the word before running out of chances, you win!

5. **Score Record:**

    Your score will be recorded and can be viewed in the scores list.

## Features

- Multiple word categories: Animals, Countries, Fruits, Sports, and Colors.
- Random word selection from the chosen category.
- ASCII art representation of the hangman.
- Score recording to keep track of player performance.
- Option to view the scores of previous games.

## Functions

### `printHangman(int chance)`

Displays the hangman graphic based on the number of remaining chances.

### `string wordselect(string term)`

Selects a random word from a list of given words.

### `void hangman(string target, string user)`

Manages the main game logic, including guessing letters, revealing the word, and tracking remaining attempts.

### `void scorerecord(int tries, string user)`

Records the player's score to a text file.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
