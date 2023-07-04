#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of Candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Candidate candidates[], int numCandidates) {
    int choice;

    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid candidate number.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote casted successfully.\n");
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("Voting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates;

    printf("Mini Voting System\n");
    printf("------------------\n");

    printf("Enter the number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);

    if (numCandidates < 2 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates.\n");
        return 0;
    }

    initializeCandidates(candidates, numCandidates);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCandidates(candidates, numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates);
                break;
            case 3:
                displayResults(candidates, numCandidates);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
