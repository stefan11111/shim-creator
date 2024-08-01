#include <stdio.h>

#define STR_MAX 4096
#define _STR(x) #x
#define STR(x) _STR(x)

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [input] [output]\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    for (;;) {
        char c;
        if (fscanf(f, "%c", &c) == EOF) {
            return 0;
        }

        if (c == 'T') {
            fprintf(g, "void* ");
            char str[STR_MAX + 1];
            fscanf(f, "%" STR(STR_MAX) "s", str);
            fprintf(g, "%s () { return 0; }\n", str);
        }
    }

    /* unreachable */
    return 0;
}
