# COMP2113 (Course project)
Course project
# 21-22-S2Project-Gp.180
Programming Project Gp.180


# Team Members:
Leung Ka Lok (30356 89439)

Liu Yin Wai (30359 30357)

![game目錄](https://user-images.githubusercontent.com/98901542/167258451-986b08cf-6132-4309-a029-d13c1eb4066a.png)
# Game Description:
We are going to create an adventure game where the character is imprisoned in dungeon. Player will have control a character with ‘wsad’ which represent go upward, leftward, rightward and downward respectively. The player will have 3 hearts at the beginning and lose the game if he lose all of them. The player will win the game and escape from the dungeon if he clears all enemies and win the final little game.





# Game Rules:
Player is allowed to move in the map. When the player meet an emeny, he is required to play a little game (Just like battle with the enemy). If he wins the game, that means he kills the enemy who will be cleared and player will get one more extra life. Otherwise, he will lose one life.

![map](https://user-images.githubusercontent.com/98901542/167258498-8b8beb3d-f41f-4494-b930-0fc383b253ab.png)



# Special Features:
- Random generation of enemies in random location
- 3 random little games 
- Selection for the character (you can select character with different sign !@#$%^&*)
- Save the game, continue the game
- Record the top five record which player takes the minimum steps to win the game.
- Player may be penalized for not complying with the input requirements specified in the game / trying out bugs in the game.

# Satisfying Requirements: 
1.	The enemies will be randomly generated in the map. To do so, we will use the function rand()
    under #include <cstdlib> to generate the positions of them with “%” operator. Player will play 
    random game whenever they meet an enemy. 
    
2.	Structures is used to store information about the character (e.g. Position, health, skin) and 
    enemies (Position).
    Vector with the variable of character (struct) is used to store all the enemies. 
    Vector to store the fastest record of Player
    Different primitive data type (bool, string, int, char) are used to ensure the operation of 
    game and differet featrues.
    '&' to pass an address so as to change the value of local variable.
    
3.	Use vectors to add and clear enemies to map and record fastest record.
    
4.	When game is started, player can quit the game by inputting 'x' whenever they want. They can 
    also decide if they want to save the game or not.
    
5.	To make the code clearer, we may split the game into different file. The little games that 
    player will play whenever they meet the enemies will split into different file.
    
6.	We will give every functions a descriptive name so that we can know the contents of it by
    reading its name. And we will capitalize first letter of every word.
    
7. Some code documentation will add in the code to explain what is the code doing and what it
    is used for.
    
# Compilation and execution instructions
    g++ -c 1game.cpp
    g++ -c 2game.cpp
    g++ -c 3game.cpp
    g++ -c main.cpp
    g++ -o game main.cpp 1game.o 2game.o 3game.o
    ./game

    
