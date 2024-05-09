#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_teams(char** teams, const int TEAMS_LENGTH) {
    for(int i = 0; i < TEAMS_LENGTH; i++) {
        int j = rand() % TEAMS_LENGTH;
        char* temp = teams[i];
        teams[i] = teams[j];
        teams[j] = temp;
    }
}

void generate_schedule(char** teams, const int TEAMS_LENGTH) {
    for(int week = 1; week <= 17; week++) {
        printf("Week %d:\n", week);
        shuffle_teams(teams, TEAMS_LENGTH);
        int teams_scheduled[TEAMS_LENGTH];

        for(int i = 0; i < TEAMS_LENGTH; i++) {
            teams_scheduled[i] = 0;
        }

        for(int i = 0; i < TEAMS_LENGTH; i++) {
            int j = rand() % TEAMS_LENGTH;

            if(teams_scheduled[i]) {
                continue;
            }

            while(i == j || teams_scheduled[j]) {
                j = rand() % TEAMS_LENGTH;
            }

            printf("%s vs. %s\n", teams[i], teams[j]);
            
            teams_scheduled[i] = 1;
            teams_scheduled[j] = 1;
        }

        printf("\n");
    }
}

int main() {
    char* teams[] = {
        "San Francisco 49ers",
        "Chicago Bears",
        "Cincinnati Bengals",
        "Buffalo Bills",
        "Denver Broncos",
        "Cleveland Browns",
        "Tampa Bay Buccaneers",
        "Arizona Cardinals",
        "Los Angeles Chargers",
        "Kansas City Chiefs",
        "Indianapolis Colts",
        "Washington Commanders",
        "Dallas Cowboys",
        "Miami Dolphins",
        "Philadelphia Eagles",
        "Atlanta Falcons",
        "New York Giants",
        "Jacksonville Jaguars",
        "New York Jets",
        "Detroit Lions",
        "Green Bay Packers",
        "Carolina Panthers",
        "New England Patriots",
        "Las Vegas Raiders",
        "Los Angeles Rams",
        "Baltimore Ravens",
        "New Orleans Saints",
        "Seattle Seahawks",
        "Pittsburgh Steelers",
        "Houston Texans",
        "Tennessee Titans",
        "Minnesota Vikings"
    };

    srand(time(NULL));
    const int TEAMS_LENGTH = sizeof(teams) / sizeof(teams[0]);
    generate_schedule(teams, TEAMS_LENGTH);

    return 0;
}
