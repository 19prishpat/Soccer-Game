# Soccer Game Simulation

## Overview
This C++ program simulates a soccer game by generating a variety of random in-game events such as goals, shots, fouls, and penalties. The game provides statistics for each team at halftime and at the end of the game, showing the number of goals, shots, fouls, yellow cards, and red cards.

## Project Details
- **Course**: SYDE 121
- **Assignment**: Lab Assignment 1
- **Author**: Prisha Patel
- **Student ID**: 211335533
- **Filename**: `PrishaPatel_21135533_assig1.cpp`
- **Due Date**: September 27, 2024
- **Purpose**: This project demonstrates the use of random number generation, conditional statements, loops, and functions in C++ to simulate various soccer game events.

## Features
- **Random Events**: The program generates a random number of events (between 1 and 30) for the game.
- **Event Types**: Events can be:
  - Goals
  - Shots (on goal, off goal, blocked shots)
  - Fouls
  - Yellow and red cards
  - Penalties
- **Halftime Statistics**: After half of the events, the program outputs the statistics for both teams.
- **Final Statistics**: At the end of the game, the program displays final stats for both teams.

## Game Flow
1. **Random Event Generation**: Each event is randomly generated and can be one of six types:
   - Shot by Team A
   - Shot by Team B
   - Foul by Team A
   - Foul by Team B
   - Foul near goal (penalty shot) by Team A
   - Foul near goal (penalty shot) by Team B

2. **Event Processing**: Depending on the type of event, the program:
   - Updates the score and relevant statistics (shots, fouls, yellow/red cards) for the teams.
   - Displays the result of the event (e.g., a goal scored, shot saved, foul committed).

3. **Halftime and Game Over**: At halftime and at the end of the game, the program displays a summary of the key statistics:
   - Total shots taken, shots on goal, shots off goal, blocked shots, fouls, yellow cards, and red cards for each team.

## Code Structure
The program is divided into several functions:
- `main()`: Controls the game flow and event generation.
- `case_type()`: Processes shot events and updates statistics accordingly.
- `foul_outcome()`: Processes foul outcomes near the goal, updating statistics based on penalty shots.
- `fouls()`: Handles foul events, determining whether a yellow or red card is given.

## Running the Program
To run the program:
1. Compile the source code using a C++ compiler:
   ```bash
   g++ -o soccer_game PrishaPatel_21135533_assig1.cpp
