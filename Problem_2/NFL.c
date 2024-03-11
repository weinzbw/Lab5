#include <stdio.h>

void scoring(int num)
{
    int td, fg, pat, p2t, safety = 0;
    
    for (p2t = 0; p2t * 8 <= num; p2t++) {
        for (pat = 0; pat * 7 <= num - p2t * 8; pat++) {
            for (td = 0; td * 6 <= num - pat * 7 - p2t - 8; td++) {
                for (fg = 0; fg * 3 <= num - p2t * 8 - pat * 7 - td * 6; fg++) {
                    for (safety = 0; safety * 2 <= num - p2t * 8 - pat * 7 - td * 6 - fg * 3; safety++) {
                        int remaining = num - p2t * 8 - pat * 7 - td * 6 - fg * 3 - safety * 2;
                        if (remaining == 0) {
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety\n", p2t, pat, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

void main(void)
{
    int num = 2;

    while (num > 1)
    {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%i", &num);
        if (num < 2)
        {
            printf("\nExiting...");
        } else {
            scoring(num);
        }
    }
}