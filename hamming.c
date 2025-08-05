#include <stdio.h>

int main() {
    int data[7], recv[7], p1, p2, p4, errorPos = 0;

    // Step 1: Input 4 data bits
    printf("Enter 4 data bits (d3 d5 d6 d7): ");
    scanf("%d %d %d %d", &data[2], &data[4], &data[5], &data[6]);

    // Step 2: Calculate parity bits for even parity
    data[0] = data[2] ^ data[4] ^ data[6]; // p1
    data[1] = data[2] ^ data[5] ^ data[6]; // p2
    data[3] = data[4] ^ data[5] ^ data[6]; // p4

    // Step 3: Display Hamming Code
    printf("Generated Hamming Code: ");
    for (int i = 0; i < 7; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    // Step 4: Enter received 7-bit code
    printf("Enter received 7-bit code: ");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &recv[i]);
    }

    // Step 5: Recalculate parity from received code
    p1 = recv[0] ^ recv[2] ^ recv[4] ^ recv[6];  // Checks for p1
    p2 = recv[1] ^ recv[2] ^ recv[5] ^ recv[6];  // Checks for p2
    p4 = recv[3] ^ recv[4] ^ recv[5] ^ recv[6];  // Checks for p4

    // Step 6: Find error position
    errorPos = p4 * 4 + p2 * 2 + p1 * 1;

    if (errorPos == 0) {
        printf("No error detected in received code.\n");
    } else {
        printf("Error detected at bit position: %d\n", errorPos);

        // Correct the error
        recv[errorPos - 1] ^= 1;

        printf("Corrected Hamming Code: ");
        for (int i = 0; i < 7; i++) {
            printf("%d", recv[i]);
        }
        printf("\n");
    }

    return 0;
}
