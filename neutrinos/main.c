/*  
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#include "stdio.h"
#include "sys/stat.h"
#include "unistd.h"
#include "sys/types.h"
#include "dirent.h"
#include "include/my.h"
#include "stdbool.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int print_all(s_t *s)
{
    printf("    Number of value:    %d\n", s->n);
    printf("    Standard deviation: %.2f\n", s->sd);
    printf("    Arithmetic mean:    %.2f\n", s->a);
    printf("    Root mean square:   %.2f\n", s->quadra);
    printf("    Harmonic mean:      %.2f\n\n", s->h);
    return 0;
}

double moy_har_ite(s_t *s, double x)
{
    double z = 0;

    z = s->n + 1;
    z /= s->n / s->h + 1 / x;
    return z;
}

double moy_ari_ite(s_t *s, double x)
{
    double z = 0;

    z = s->a * s->n + x;
    z /= s->n + 1;
    return z;
}

int calcul(s_t *s, char *buffer, size_t size)
{
    double x = 0;

    while (1) {
        printf("Enter next value: ");
        fgets(buffer, size, stdin);
        if (strncmp(buffer, "END", 3) == 0)
            break;
        x = atof(buffer);
        if (x == 0)
            return 84;
        s->sq_somme += x * x;
        s->a = moy_ari_ite(s, x);
        s->h = moy_har_ite(s, x);
        s->n++;
        s->quadra = sqrt(s->sq_somme / s->n);
        s->sd = sqrt(s->quadra * s->quadra - s->a * s->a);
        print_all(s);
    }
    return 0;
}

static int flag_h(void)
{
    printf("USAGE\n");
    printf("    ./104neutrinos n a h sd\n");
    printf("\nDESCRIPTION\n");
    printf("    n       number of values\n");
    printf("    a       arithmetic mean\n");
    printf("    h       harmonic mean\n");
    printf("    sd      standard deviation\n");
    return 0;
}

static int parss(char **argv, pars_t *pars)
{
    if (argv[pars->i][pars->j] >= '0' && argv[pars->i][pars->j] <= '9') {
        pars->j++;
        return 0;
    } else if (argv[pars->i][pars->j] == '\0') {
        pars->j = 0;
        pars->i++;
        return 0;
    } else
        return 84;
}

static int check_args(char **argv)
{
    pars_t pars;

    pars.i = 1;
    pars.j = 0;
    while (argv[pars.i] != NULL) {
        if (parss(argv, &pars) == 84)
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    s_t s;
    char buffer[256];

    if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'h')
        return flag_h();
    if (argc != 5)
        return 84;
    if (check_args(argv) == 84)
        return 84;
    s.n = atoi(argv[1]);
    s.a = atof(argv[2]);
    s.h = atof(argv[3]);
    s.sd = atof(argv[4]);
    s.sq_somme = s.n * ((s.sd * s.sd) + (s.a * s.a));
    s.value = 0;
    return calcul(&s, buffer, sizeof(buffer));
}
