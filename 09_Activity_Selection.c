// C program for activity selection problem.

// The following implementation assumes that the activities
// are already sorted according to their finish time
#include <stdio.h>

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	printf("Following activities are selected\n");

	// The first activity always gets selected
	i = 0;
	printf("%d ", i);

	// Consider rest of the activities
	for (j = 1; j < n; j++) {
		// If this activity has start time greater than or
		// equal to the finish time of previously selected
		// activity, then select it
		if (s[j] >= f[i]) {
			printf("%d ", j);
			i = j;
		}
	}
}

// Driver code
int main()
{
	int s[] = { 1, 3, 0, 5, 8, 5 };
	int f[] = { 2, 4, 6, 7, 9, 9 };
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	printMaxActivities(s, f, n);
	return 0;
}

/*
Following activities are selected
0 1 3 4 
*/


#include <stdio.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on finish time
int compareActivities(const void* a, const void* b) {
    return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(struct Activity arr[], int n) {
    // Sort activities based on finish time
    qsort(arr, n, sizeof(struct Activity), compareActivities);

    printf("Following activities are selected:\n");

    // The first activity always gets selected
    int i = 0;
    printf("Activity %d: Start time = %d, Finish time = %d\n", i, arr[i].start, arr[i].finish);

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[i].finish) {
            printf("Activity %d: Start time = %d, Finish time = %d\n", j, arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

// Driver code
int main() {
    struct Activity activities[] = {
        {0, 6}, {3, 4}, {1, 2}, {5, 7}, {8, 9}, {5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    // Function call
    printMaxActivities(activities, n);
    return 0;
}


/*
Following activities are selected:
Activity 0: Start time = 1, Finish time = 2
Activity 1: Start time = 3, Finish time = 4
Activity 3: Start time = 5, Finish time = 7
Activity 4: Start time = 8, Finish time = 9
*/
