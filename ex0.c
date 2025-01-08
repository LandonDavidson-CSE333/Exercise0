//
// Created by landond on 1/7/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Check that input is a reasonably sized integer then store in num_terms
    char* end;
    long int num_terms = strtol(argv[1], &end, 10);
    // if the scanner ended at the start then it didn't read any numbers and the input is invalid
    if (end == argv[1]) {printf("Argument isn't an integer\n"); return 1;}
    // If the input is less than 1 then it is too small and the input is invalid
    if (num_terms < 1) { printf("Input to small\n"); return 1;}
    // If the input is more than 100,000 it is too big
    if (num_terms > 100000) { printf("Input to large\n"); return 1;}
    // repeatedly calculate num_terms terms of the Nilakantha series and add to pi_approx
    double pi_approx = 3;
    for (int i = 1; i <= num_terms; i++) {
        // positive on odd terms and negative on even terms
        int sign = i % 2 == 0 ? -1 : 1;
        pi_approx += sign * 4.0 / (2 * i * (2 * i + 1) * (2 * i + 2)); // divide 4 by the product of 2i * (2i + 1) * (2i + 2)
    }
    // print pi_approx to stdout with some formatting
    printf("Our estimate of Pi is %f\n", pi_approx);
}
