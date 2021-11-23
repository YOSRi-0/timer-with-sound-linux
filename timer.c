#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("Usage : timer <time>");
        return 1;
    }

    int h,m,s;
    h = m = s = 0;

    char *input;
    input = argv[2];
    char c = argv[1][1];

    int timer = atoi(input);

    system("clear");

    int seconds = 0;
    if (c == 'm') {
        seconds = timer * 60;
    } else if (c == 'h') {
        seconds = timer * 60 * 60;
    } else {
        seconds = timer;
    }

    while (seconds > 0) {
        seconds--;
        h = seconds / 60 / 60;
        m = seconds / 60 % 60;
        s = seconds % 60;

        printf("Clock :\n");
        printf("\n%dh:%dm:%ds\n",h,m,s);
        sleep(1);
        system("clear");
    }
    system("aplay sound.wav");
}
