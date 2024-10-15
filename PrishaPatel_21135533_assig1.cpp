/*

    Prisha Patel
    Student ID: 211335533

    SYDE 121 Lab: Assignment: 1
    Filename: PrishaPatel_21135533_assig1.cpp

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts. This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others

    Project: Soccer Game
    Purpose: This program generates a game of soccer with different events and consequences, 
    it displays statistics at halftime and at the end.
    Due Date: September 27, 2024

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Calling predefined functions
void case_type(string team_name, int &scores, int &shot_on_goal, int &off_goal, int &blocked_shot, int &num_shots);
void foul_outcome(string other_name, int &scores, int &shot_on_goal, int &off_goal, int &num_shots);
void fouls(string fouling_name, int &fouls_num, int &yellow_num, int &red_num);
 

    // Initialize variables for both the teams 
    int num_shots_a, num_shots_b, shots_on_goal_a, shots_on_goal_b, off_goal_a, off_goal_b, a_shots, b_shots, blocked_shots_a, blocked_shots_b, fouls_num_a, fouls_num_b, yellow_card_a, yellow_card_b, red_card_a, red_card_b;
    // Initialize the scores for both the teams
    int score_a = 0;
    int score_b = 0;

int main(){
    srand(time(0)); // Seed the random number generator with current time


    int num_events = (rand() % 30)+1; // Generate a number between 1 and 30
    int halftime = num_events/2; // Dividing the generated event number to get it's half


    

    // Running a loop to generate the events for num_events of time
    for (int i = 0; i<num_events; i++){
        int event_gen = (rand() % 6)+1; // Generates a number between 1 and 6

        // Processing the events based on the random numbers generated
        if (event_gen == 1){
            case_type("Team A", score_a, shots_on_goal_a, off_goal_a, blocked_shots_a, num_shots_a);
        }
        else if (event_gen == 2){
            case_type("Team B", score_b, shots_on_goal_b, off_goal_b, blocked_shots_b, num_shots_b);
        }
        else if (event_gen == 3){
            fouls("Team B", fouls_num_b, yellow_card_b, red_card_b);
        }
        else if (event_gen == 4){
            fouls("Team A", fouls_num_a, yellow_card_a, red_card_a);
        }
        else if (event_gen == 5){
            
            foul_outcome("Team A", score_a, shots_on_goal_a, off_goal_a, num_shots_a);
        }
        else if(event_gen == 6) {
            
            foul_outcome("Team B", score_b, shots_on_goal_b, off_goal_b, num_shots_b);
        }

        // This is if statment runs when its halftime and gameover to present the statistics
        if (i ==halftime-1 || i == num_events-1){
            cout << "_________________________________________________________\n";
            if (i==halftime-1){
                cout << "Halftime Break! Resuming second half soon, here are the stats so far!\n";

            }
            else{
                cout << "Game Over! Here are the final stats!\n";

            }
            
            cout << "Team A" "\n";
            cout << "----------\n";
            cout << "Total number of shots taken: " << num_shots_a<< "\n";
            cout << "Total number of shots on goal: " << shots_on_goal_a << "\n";
            cout << "Total number of shots off goal: " << off_goal_a << "\n";
            cout << "Total number of blocked shots: " << blocked_shots_a << "\n";
            cout << "Total number of fouls: " << fouls_num_a << "\n";
            cout << "Total number of yellow cards given: " << yellow_card_a << "\n";
            cout << "Total number of red cards given: " << red_card_a << "\n";

            cout << "_________________________________________________________\n";

            cout << "Team B" "\n";
            cout << "----------\n";
            cout << "Total number of shots taken: " << num_shots_b << "\n";
            cout << "Total number of shots on goal: " << shots_on_goal_b << "\n";
            cout << "Total number of shots off goal: " << off_goal_b << "\n";
            cout << "Total number of blocked shots: " << blocked_shots_b << "\n";
            cout << "Total number of fouls: " << fouls_num_b << "\n";
            cout << "Total number of yellow cards given: " << yellow_card_b << "\n";
            cout << "Total number of red cards given: " << red_card_b << "\n";

            cout << "_________________________________________________________\n";
        }

    }


}

// This function determines result of taken shot
void case_type(string team_name, int &scores, int &shot_on_goal, int &off_goal, int &blocked_shot, int &num_shots){
    int score_outcome = rand() % 4; // Generates a number between 0 and 3

    // Case where goal is scored
    if (score_outcome == 0){
        cout << "- The score was goaled by: " << team_name << "\n";
        scores++;
        num_shots++;
        shot_on_goal++;           
    }
    // Case where goal is made on goal but saved by other team
    else if(score_outcome == 1){
        cout << team_name << "- Team A on goal but was saved by the other team: " << team_name << "\n";
        num_shots++;
        shot_on_goal++;
        blocked_shot++;
    }
    // Case where shot is off the target
    else if(score_outcome == 2){
        cout << "- The shot was made off goal by: " << team_name << "\n";
        off_goal++;
        num_shots++;
    }
    // Case where shot was taken and blocked by another player
    else{
        cout << "- "<< team_name << " took a shot but was blocked by another player\n";
        blocked_shot++;
        num_shots++;
        shot_on_goal++;
    }

}

// Provides outcome after foul is committed
void foul_outcome(string other_name, int &scores, int &shot_on_goal, int &off_goal, int &num_shots){

    cout << "- Team B has committed a foul close to goal, Team A is awarded a penalty: ";
    int score_outcome2 = rand() % 3; // Generates a number between 0 and 2

    // Case when pentaly shot is goaled
    if (score_outcome2 == 0){
        cout << other_name << " goaled!\n";
        scores++;
        num_shots++;
        shot_on_goal++;
    }
    // Case where shot was made but saved by the other team
    else if(score_outcome2 == 1){
        cout << "Shot was made by "<<  other_name << " on goal but was saved by the other team\n";
        num_shots++;
        shot_on_goal++;
    }
    // Case where shot was made off goal
    else if(score_outcome2 == 2){
        cout << "The shot was made off goal by "<< other_name << "\n";
        num_shots++;
        off_goal++;
    }
}

// Determines the fouls and cards received by each team
void fouls(string fouling_name, int &fouls_num, int &yellow_num, int &red_num){
    int card_draw = rand() % 3; // Generates a number between 0 and 2
    fouls_num++;

    cout << "- " << fouling_name << " fouled the other team: ";
    
    // No card is given to the team
    if(card_draw == 0){
        cout << "(No card was given)\n";          

    }
    // Yellow card given to the team
    else if(card_draw == 1){
        cout<< "(Yellow card was given for the foul)\n";
        yellow_num++;
    }
    // Red card given to the team
    else if(card_draw == 2){
        cout<< "(Red card was given for the foul)\n";
        red_num++;
     
    }

}

 
