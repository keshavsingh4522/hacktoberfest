#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv) {
    printf("hello world\n");

    if (argc < 3) {
        printf("Usage: %s <count> <sensor_count> [-o filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int use_file = 0;
    FILE *fp;

    if (argc >= 5) {
        if (strcmp("-o", argv[3]) == 0) {
            use_file = 1;
            fp = fopen(argv[4], "a+"); // append and create if not exist
        }
    }

    int count = atoi(argv[1]);
    int sensor_count = atoi(argv[2]);

    if (sensor_count < 1 || sensor_count > 26) {
        printf("Number of sensors mst be between 1 and 26\n");
        exit(EXIT_FAILURE);
    }

    srand(time(0));

    float temp = (float)(rand() % 200 + 150) / 10;

    for (int i = 0; i < count; i++) {
        int sensor = (rand() % sensor_count) + 1;

        if (rand() % 2 == 0) {
            temp += (float)(rand() % 25) / 10;
        } else {
            temp -= (float)(rand() % 25) / 10;
        }

        float humidity = (float)(rand() % 600 + 300) / 10;

        struct timeval tp;
        gettimeofday(&tp, NULL);
        long int ts_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

        if (use_file) {
            fprintf(fp, "%lu,S%02d,%.1f,%.1f\n", ts_ms, sensor, temp, humidity);
            fflush(fp);
        } else {
            printf("%lu,S%02d,%.1f,%.1f\n", ts_ms, sensor, temp, humidity);
        }
        usleep(4000000 + rand() % 1000000);
    }

	fclose(fp);

    return 0;
}
