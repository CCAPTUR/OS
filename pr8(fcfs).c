#include <stdio.h>
#include <stdlib.h>

#define MIN_FRAMES 3

void getInput(int *pageRefs, int *numPages, int *frameSize) {
    printf("Enter the number of pages in the reference sequence: ");
    scanf("%d", numPages);

    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < *numPages; i++) {
        scanf("%d", &pageRefs[i]);
    }

    do {
        printf("Enter the number of frames (minimum %d): ", MIN_FRAMES);
        scanf("%d", frameSize);
        if (*frameSize < MIN_FRAMES) {
            printf("Frame size must be at least %d.\n", MIN_FRAMES);
        }
    } while (*frameSize < MIN_FRAMES);
}

int isPageInFrames(int *frames, int frameSize, int page) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found in frames
}

void displayFrames(int *frames, int frameSize) {
    printf("Frames: ");
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

void fcfsPageReplacement(int *pageRefs, int numPages, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;
    int currentIndex = 0;

    // Initialize frames to -1 to indicate they are empty
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    printf("\nExecuting FCFS Page Replacement:\n");
    for (int i = 0; i < numPages; i++) {
        int currentPage = pageRefs[i];

        printf("\nProcessing page: %d\n", currentPage);

        // Check if page is already in one of the frames
        if (!isPageInFrames(frames, frameSize, currentPage)) {
            // Page fault occurs, replace the oldest page (FCFS logic)
            frames[currentIndex] = currentPage;
            currentIndex = (currentIndex + 1) % frameSize;
            pageFaults++;

            printf("Page fault occurred! ");
        } else {
            printf("Page hit. ");
        }

        displayFrames(frames, frameSize);
    }

    printf("\nTotal number of page faults: %d\n", pageFaults);
}

int main() {
    int numPages;
    int frameSize;
    int pageRefs[100];

    getInput(pageRefs, &numPages, &frameSize);
    fcfsPageReplacement(pageRefs, numPages, frameSize);

    return 0;
}

