#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> // atoi is stored here
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    // open index by 1, cause 0 is program`s own name / atoi = actual int
    int key = atoi(argv[1]);

    string p;
    do
    {
        //p = Plaintext
        p = get_string("plaintext: ");
    }
    while (p == NULL);

    //loop over the plaintext to generate the ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {

            printf("%c", ((p[i] - 'A' + key) % 26 + 'A'));
        }
        else if (islower(p[i]))
        {

            printf("%c", ((p[i] - 'a' + key) % 26 + 'a'));
        }
        else
        {

            printf("%c", p[i]);
        }

    }

    printf("\n");
}
