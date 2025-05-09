/*
 * Scoreboard - A retro-style scoreboard management program
 * Copyright (c) 2025 PHForge
 *
 * This program allows users to manage player scores, display rankings with tie handling,
 * and save/load data to/from a file, with a 1980s arcade-inspired interface.
 *
 * Licensed under the MIT License. See the LICENSE file in the repository for details.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Added for isspace
#define MAX_PLAYERS 10

struct Player {
    char name[50];
    int score;
};

void add_player(struct Player players[], int *players_number) {
    // Check if the maximum number of players has been reached
    if (*players_number >= MAX_PLAYERS) {
        printf("\nLimit of players reached!\n");
        return;
    }

    /* Player's name */
    printf("Player's name: ");
    // Read the entire line, including empty input (max 48 characters + newline)
    if (fgets(players[*players_number].name, 50, stdin) == NULL) {
        printf("\nError reading name\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    // Check if input is too long (no newline and buffer full)
    size_t len = strlen(players[*players_number].name);
    if (len >= 49 && players[*players_number].name[48] != '\n') {
        printf("\nName too long (max 48 characters)\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear remaining input
        return;
    }
    // Remove trailing newline added by fgets and replace with \0
    players[*players_number].name[strcspn(players[*players_number].name, "\n")] = '\0';
    // Check if the name is empty or contains only whitespace
    char *checkEmptyWhitespace = players[*players_number].name;
    while (*checkEmptyWhitespace && isspace(*checkEmptyWhitespace)) checkEmptyWhitespace++; // Skip leading whitespace
    if (*checkEmptyWhitespace == '\0') {
        printf("\nEmpty or whitespace-only name not allowed\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    // Move non-whitespace part to the beginning to remove leading spaces
    if (checkEmptyWhitespace != players[*players_number].name) {
        memmove(players[*players_number].name, checkEmptyWhitespace, strlen(checkEmptyWhitespace) + 1);
    }
    // Check if name contains commas (invalid for file format)
    if (strchr(players[*players_number].name, ',')) {
        printf("\nNames containing commas are not allowed\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    /* Player's score */
    printf("Player's score: ");
    // Read and validate score input
    int result = scanf("%d", &players[*players_number].score);
    if (result != 1) {
        printf("\nError: Please enter a valid number\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    // Check if there are non-whitespace characters after the number
    int next_char = getchar();
    if (next_char != '\n' && !isspace(next_char)) {
        printf("\nError: Invalid characters after number\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    // Check if score is negative
    if (players[*players_number].score < 0) {
        printf("\nNegative score not allowed\n");
        printf("Addition cancelled.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Increment player count (*players_number is dereferenced first, ++ has higher precedence)
    (*players_number)++;
}
/*
void display_players(struct Player players[], int players_number) {
    printf("\nScoreboard:\n\n");
    for (int i = 0; i < players_number; i++) {
        printf("%d. %s : %d\n", i + 1, players[i].name, players[i].score);
    }
}
*/
void display_players(struct Player players[], int players_number) {
    printf("\nScoreboard:\n\n");
    if (players_number == 0) {
        printf("No players in the scoreboard.\n");
        return;
    }

    int rank = 1; // Current rank
    for (int i = 0; i < players_number; i++) {
        // If not the first player and score equals previous, use same rank
        if (i > 0 && players[i].score == players[i - 1].score) {
            printf("%d. %s : %d (ex-aequo)\n", rank, players[i].name, players[i].score);
        } else {
            // Update rank to current position (i + 1)
            rank = i + 1;
            // Check if next player has same score to decide if (ex-aequo) is needed
            if (i < players_number - 1 && players[i].score == players[i + 1].score) {
                printf("%d. %s : %d (ex-aequo)\n", rank, players[i].name, players[i].score);
            } else {
                printf("%d. %s : %d\n", rank, players[i].name, players[i].score);
            }
        }
    }
}

void sort_players(struct Player players[], int players_number) {
    // Bubble sort
    // players_number - 1: Only n-1 passes are needed for n elements, as the last element will be in place
    for (int i = 0; i < players_number - 1; i++) {
        // players_number - i - 1: Skip the i largest scores already sorted
        for (int j = 0; j < players_number - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                struct Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

void save_players(struct Player players[], int players_number) {
    // Open file in write mode
    FILE *save_file = fopen("scores.txt", "w");
    // Check if fopen failed (e.g., due to permissions or disk issues)
    if (save_file == NULL) {
        printf("Error opening save file.\n");
        return;
    }
    // Write each player's name and score, separated by a comma
    for (int i = 0; i < players_number; i++) {
        fprintf(save_file, "%s,%d\n", players[i].name, players[i].score);
    }
    // Close the file
    fclose(save_file);
}

void loading_saveFile(struct Player players[], int *players_number) {
    // Open file in read mode
    FILE *save_file = fopen("scores.txt", "r");
    // Check if fopen failed (e.g., due to permissions or disk issues)
    if (save_file == NULL) {
        printf("Error opening save file.\n");
        return;
    }
    // Reset player count
    *players_number = 0;
    // Read each line (name,score) until max players or invalid input
    while (*players_number < MAX_PLAYERS &&
           fscanf(save_file, "%49[^,],%d\n", players[*players_number].name, &players[*players_number].score) == 2) {
        (*players_number)++;
    }
    // Close the file
    fclose(save_file);
}

int main() {
    struct Player players[MAX_PLAYERS];
    int players_number = 0;
    int choice;
    loading_saveFile(players, &players_number);

    // Display ASCII art banner once at startup
    printf("\n");
    printf("  _____                    _                         _ \n");
    printf(" / ____|                  | |                       | |\n");
    printf("| (___   ___ ___  _ __ ___| |__   ___   __ _ _ __ __| |\n");
    printf(" \\___ \\ / __/ _ \\| '__/ _ \\ '_ \\ / _ \\ / _` | '__/ _` |\n");
    printf(" ____) | (_| (_) | | |  __/ |_) | (_) | (_| | | | (_| |\n");
    printf("|_____/ \\___\\___/|_|  \\___|_.__/ \\___/ \\__,_|_|  \\__,_|\n");
    printf("\n");
    printf("       by PHForge\n");
    printf("\n");

    do {
        printf("\nMenu:\n1. Add a player\n2. Display Scoreboard\n3. Credit\n4. Quit\n\nSelect menu: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nnInvalid choice. Please select 1, 2, 3 or 4\n");
            while (getchar() != '\n'); // Clear input buffer
            choice = 0; // Avoid infinite loop
        } else {
            while (getchar() != '\n'); // Clear trailing newline
        }
        switch (choice) {
            case 1: {
                char add_another_one;
                do {
                    int previous_number = players_number; // Track number before adding
                    add_player(players, &players_number);
                    if (players_number >= MAX_PLAYERS) {
                        printf("\nLimit of players reached!\n");
                        break;
                    }
                    // Only ask to add another if a player was successfully added
                    if (players_number > previous_number) {
                        printf("Add another one? (y  n): ");
                        scanf(" %c", &add_another_one);
                        while (getchar() != '\n'); // Clear remaining input
                        // Convert to lowercase for case-insensitive comparison
                        add_another_one = tolower(add_another_one);
                        // Validate input (only 'y' or 'n' allowed)
                        while (add_another_one != 'y' && add_another_one != 'n') {
                            printf("Invalid input. Please enter 'y' or 'n': ");
                            scanf(" %c", &add_another_one);
                            while (getchar() != '\n'); // Clear remaining input
                            add_another_one = tolower(add_another_one);
                        }
                        // Sort and save after each successful addition
                        sort_players(players, players_number);
                        save_players(players, players_number);
                    } else {
                        // If addition was cancelled, exit the loop
                        break;
                    }
                } while (add_another_one == 'y' && players_number < MAX_PLAYERS);
                break;
            }
            case 2:
                display_players(players, players_number);
                break;
            case 3:
                printf("\nI would like to thank my wife and son for their patience and love. Thank you for everything, I love you.\n");
                printf("\nPress Enter to continue...");
                while (getchar() != '\n'); // Wait for Enter
                break;
            case 4:
                printf("\nOkay Bye!\n");
                break;
            default:
                if (choice != 0) { // Only display for valid numbers not handled
                    printf("\nInvalid choice. Please select 1, 2, 3 or 4\n");
                }
                break;
        }
    } while (choice != 4);
    return 0;
}
