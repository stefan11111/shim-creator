#include <stdio.h>
#include <string.h>

#define STR_MAX 4096
#define STR_(x) #x
#define STR(x) STR_(x)

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [input] [output.c] [output.h]\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");
    FILE *h = fopen(argv[3], "w");

    for (;;) {
        char str[STR_MAX + 1];
        if (fscanf(f, "%" STR(STR_MAX) "s", str) == EOF) {
            return 0;
        }

        if (str[0] != 'T' || str[1] != 0) {
            continue;
        }

        if (fscanf(f, "%" STR(STR_MAX) "s", str) == EOF) {
            return 0; /* should never happen */
        }

        char *p = strchr(str, '@');
        if (p) {
            *p = 0;
        }

        fprintf(g, "void* %s () { return 0; }\n", str);
        fprintf(h, "void* %s ();\n", str);
    }

    /* unreachable */
    return 0;
}
