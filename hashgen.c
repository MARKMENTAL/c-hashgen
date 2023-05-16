#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <openssl/sha.h>

// Function to get the current time and store it in a buffer
void get_current_time(char *buffer) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 20, "%Y-%m-%d - %H:%M:%S", timeinfo);
}

int main() {
    int hash_type;
    char user_input[100], hash_output[SHA512_DIGEST_LENGTH * 2 + 1], code[7];
    unsigned char hash[SHA512_DIGEST_LENGTH];
    srand(time(NULL));

    // Get the hash type from the user (256 or 512)
    while (1) {
        printf("Enter the hash type (256 or 512): ");
        scanf("%d", &hash_type);
        if (hash_type == 256 || hash_type == 512) {
            break;
        }
    }

    // Get the seed string from the user
    printf("Enter a string to use as a seed: ");
    scanf("%s", user_input);

    // Generate the hash based on the selected hash type
    if (hash_type == 256) {
        SHA256((unsigned char *)user_input, strlen(user_input), hash);
    } else {
        SHA512((unsigned char *)user_input, strlen(user_input), hash);
    }

    // Convert the hash to a hexadecimal string
    int j = 0;
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        sprintf(hash_output + j, "%02x", hash[i]);
        j += 2;
    }

    // Loop indefinitely to generate a new code every 30 seconds
    int counter = rand() % strlen(hash_output);
    while (1) {
        // Extract the 6 digits from the hash output based on the counter
        j = 0;
        for (int i = counter; i < strlen(hash_output) && j < 6; i++) {
            if (hash_output[i] >= '0' && hash_output[i] <= '9') {
                code[j++] = hash_output[i];
            }
        }
        code[j] = '\0';

        // Get the current time and print the result
        char now[20];
        get_current_time(now);
        printf("%s | Hash value: %s | Code: %s\n", now, hash_output, code);

        // Write the result to a file
        FILE *f = fopen("output.txt", "a");
        if (f != NULL) {
            fprintf(f, "%s | Hash value: %s | Code: %s\n", now, hash_output, code);
            fclose(f);
        }

        // Sleep for 30 seconds before generating a new code
        sleep(30);

        // Increment the counter by a random value
        counter += rand() % 5 + 1;
    }

    return 0;
}