#include <stdio.h>

int main()
{
    FILE *file;
    int array[5][5];
    int size = 0;

    if ((file = fopen("input.txt", "r")) == NULL)
    {
        printf("\noFile not found.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            fscanf(file, "%d", &array[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    fclose(file);

    FILE *out = fopen("output.dot", "w");

    fprintf(out, "graph{\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (array[i][j] >= 1)
            {
                fprintf(out, "%d -- %d;\n", i, j);
            }
        }
    }
    fprintf(out, "}");

    fclose(out);

    system("dot output.dot -Tpng -o image.png");
    return 0;
}