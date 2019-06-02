#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* utilities */
#define TEXT_LEN 256
#define OPT_MAX 8

typedef struct Options {
	char description[TEXT_LEN];
	struct Rooms *nextRoom;
	char roomDescription[TEXT_LEN];
} Option;

typedef struct Rooms {
	char description[TEXT_LEN];
	int optionCount;
	Option options[OPT_MAX];
} Room;

Room newRoom();
void addOption(Room *r, Option o);

int choose(int max);
int chooseOption(Room r);

/* globals */
char *name = "employee 17420-3";

int main() {
	/* set up the world */
	Room start = newRoom("");
	sprintf(
		start.description,
		"Good morning %s.\nLet's go ahead and get started.\n\
		You've been assigned to associate button presser.\nJust down the hall on the right.",
		name
	);
	Room endOfHall = newRoom("The end of the hall");
	Option goHall = {
		description: "You went down the hall",
		nextRoom: &endOfHall,
		roomDescription: "And reached the end of the hall",
	};
	addOption(&start, goHall);

	{
		/* variables to actually run the game */
		Room currentRoom = start;
		int choice = -1;
		while (currentRoom.optionCount > 0) {
			/* as long as the player still has options, we can keep going */
			printf(currentRoom.description);
			choice = chooseOption(currentRoom);
			currentRoom = *(currentRoom.options[choice].nextRoom);
		}
		printf("Thanks for playing");
	}

	printf("%s\n", start.description);
	printf("Good morning %s.\nLet's go ahead and get started.\n", name);
	printf("You've been assigned to associate button presser. Just down the hall on the right.\n");
	chooseOption(start);
	return 0;
}

Room newRoom(char desc[TEXT_LEN]) {
	Room r = {
		description: desc,
		optionCount: 0,
	};
	return r;
}

void addOption(Room *r, Option o) {
	(*r).options[(*r).optionCount] = o;
	(*r).optionCount++;
}

int choose(int max) {
	int choice;
	scanf("%d", &choice);
	while (choice < 1 || choice > max) {
		printf("can't do that.\n");
		scanf("%d", &choice);
	}
	return choice;
}

int chooseOption(Room r) {
	int i;
	for (i = 0; i < r.optionCount; i++) {
		printf("%d) %s\n", i + 1, r.options[i].description);
	}
	return choose(r.optionCount);
}
