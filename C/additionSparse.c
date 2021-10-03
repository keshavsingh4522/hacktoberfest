//program to add two sparse matric created by array
#include <stdio.h>
#include <stdlib.h>
struct element
{
    int row;
    int col;
    int el;
};
struct sparse
{
    int m, n;
    int num;
    struct element *e;
};
void create(struct sparse *s)
{
    printf("enter the dimensions of the matrix\n");
    scanf("%d %d", &s->m, &s->n);
    printf("enter the number of non zero elements\n");
    scanf("%d", &s->num);
    s->e = (struct element *)malloc(s->num * sizeof(struct element));
    printf("enter the row, column and the element\n");
    for (int k = 0; k < s->num; k++)
    {
        scanf("%d %d %d", &s->e[k].row, &s->e[k].col, &s->e[k].el);
    }
}
struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    //base condition

    if (s1->m != s2->m || s1->n != s2->n)
    {
        return 0;
    }
    struct sparse *sum;

    sum->num;
    sum->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));
    int i = 0, j = 0, k = 0;

    //i->sparse matrix 1
    //j->sparse matrix 2
    //k->sparse matrix 3

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].row < s2->e[j].row)
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].row > s2->e[j].row)
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            if (s1->e[i].col < s2->e[j].col)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].col > s2->e[j].col)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].el = s1->e[i++].el + s2->e[j++].el;
            }
        }
    }
    if (i == s1->num)
    {
        for (; j < s2->num; j++)
        {
            sum->e[k++] = s2->e[j++];
        }
    }
    else
    {
        for (; i < s1->num; i++)
        {
            sum->e[k++] = s1->e[i++];
        }
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}
void display(struct sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.e[k].row && j == s.e[k].col)
            {
                printf("%d ", s.e[k++].el);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct sparse s1;
    struct sparse s2;
    struct sparse *s3;
    printf("creating first matrix\n");
    create(&s1);
    printf("creating second matrix\n");
    create(&s2);
    s3 = add(&s1, &s2);
    //printf("%d,%d,%d\n", s3->m, s3->n, s3->num);
    display(*s3);
    return 0;
}
