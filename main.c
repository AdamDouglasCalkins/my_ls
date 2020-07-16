#include "my_ls.h"

int month_to_int(char a, char b, char c)
{
    int i;
    if ('J' == a && b == 'a' && c == 'n')
        i = 48;
    else if (a == 'F' && b == 'e' && c == 'b')
        i = 49;
    else if (a == 'M' && b == 'a' && c == 'r')
        i = 50;
    else if (a == 'A' && b == 'p' && c == 'r')
        i = 51;
    else if (a == 'M' && b == 'a' && c == 'y')
        i = 52;
    else if (a == 'J' && b == 'u' && c == 'n')
        i = 53;
    else if (a == 'J' && b == 'u' && c == 'l')
        i = 54;
    else if (a == 'A' && b == 'u' && c == 'g')
        i = 55;
    else if (a == 'S' && b == 'e' && c == 'p')
        i = 56;
    else if (a == 'O' && b == 'c' && c == 't')
        i = 57;
    else if (a == 'N' && b == 'o' && c == 'v')
        i = 58;
    else
        i = 59;
    return (i);
}

int setaflag(char *str)
{
        if (str[0] == '-' && str[1] == 'a')
                return (1);
        else if (str[0] == '-' && str[1] == 'a' && str[2] == 't' )
                return (1);
        else if (str[0] == '-' && str[1] == 't' && str[2] == 'a' )
                return (1);
        else
                return (0);
}

int settflag(char *str)
{
        if (str[0] == '-' && str[1] == 't')
                return (1);
        else if (str[0] == '-' && str[1] == 'a' && str[2] == 't' )
                return (1);
        else if (str[0] == '-' && str[1] == 't' && str[2] == 'a' )
                return (1);
        else
                return (0);
}

void startList(char *str, int aflag, int tflag)
{
    struct dirent *de;
    t_list* start = NULL;
    struct stat attr;
    int opend = 1;
    DIR *dr = opendir(str);
    if (dr == NULL)
    {
        printf("No such Directory found\n");
        opend = 0;
    }
    if (opend == 1)
    {
        while ((de = readdir(dr)) != NULL)
        {
                    stat(de->d_name, &attr);
                    ft_list_push_back(&start, de->d_name,
				    attr.st_mtime, attr.st_mtim.tv_nsec);
        }
        if (tflag == 1)
        {
                while (isDateSort(start) == 0)
                {
                    nodeSwap(&start, findNodePlace(start));
                }
                printList(start, aflag);
        }
        else
        {
                while (isFnameSort(start) == 0)
                {
                        nodeSwap(&start, findNodeNamePlace(start));
                }
                printList(start, aflag);
        }
        deleteList(start);
        closedir(dr);
    }
}

int main(int argc, char** argv)
{
    int aflag = 0;
    int tflag = 0;
    int mflag = 0;
    int i = 1;
    //if
    while (argc > 1 && i < argc && (ft_strcmp(argv[i], "-a") == 0 || ft_strcmp(argv[i], "-t") == 0 || ft_strcmp(argv[i], "-at") == 0 || ft_strcmp(argv[i], "-ta") == 0))
    {
            if (aflag == 0)
                    aflag = setaflag(argv[i]);
            if (tflag == 0)
                    tflag = settflag(argv[i]);
            i++;
    }
    if (i < argc)
    {
            if (argc - i > 1)
                    mflag = 1;
            while (i < argc)
            {
                    if (mflag == 1)
                            printf("%s:\n", argv[i]);
                    startList(argv[i], aflag, tflag);
                    i++;
                    if (i < argc)
                            printf("\n");
            }
    }
    else
            startList(".", aflag, tflag);
    return 0;
}
