#include "my_ls.h"

void nodeSwap(t_list **head_list, int index)
{
        int i = 0;
        if (head_list == NULL)
                return;
        t_list *prevI = NULL;
        t_list *currI = *head_list;
        t_list *prevJ = *head_list;
        t_list *currJ = currI->next;
        t_list *tmp = NULL;
        while (i < index)
        {
                prevI = currI;
                currI = currI->next;
                prevJ = currJ;
                currJ = currJ->next;
                i++;
        }
    if (currI != NULL && currJ != NULL)
    {
            if (prevI != NULL)
                    prevI->next = currJ;
            else
                    *head_list = currJ;
            if (prevJ != NULL)
                    prevJ->next = currI;
            else
                    *head_list = currI;
            tmp = currJ->next;
            currJ->next = currI->next;
            currI->next  = tmp;
    }
}

int     isDateSort(t_list *begin_list)
{
        t_list *index = begin_list;
        while (index != NULL && index->next != NULL)
            {
                    if ((index->datenum -index->next->datenum) > 0)
                            index = index->next;
                    else if ((index->datenum -index->next->datenum) == 0)
                    {
                            if ((index->datensec -index->next->datensec) > 0)
                                    index = index->next;
                            else if ((index->datensec -index->next->datensec) == 0)
                            {
                                    if (ft_strcmp(index->fname, index->next->fname) <= 0)
                                            index = index->next;
                                    else
                                            return (0);
                            }
                            else
                                    return (0);
                    }
                    else
                            return (0);
        }
        return (1);
}

int     isFnameSort(t_list *begin_list)
{
        t_list *index = begin_list;
        while (index != NULL && index->next != NULL)
            {
                    if (ft_strcmp(index->fname, index->next->fname) <= 0)
                            index = index->next;
                    else
                            return (0);
        }
        return (1);
}

int  findNodePlace(t_list *begin_list)
{
        t_list *index = begin_list;
        int result = 0;
        while (index != NULL && index->next != NULL)
            {
                    if ((index->datenum - index->next->datenum) > 0)
                    {
                            index = index->next;
                            result++;
                    }
                    else if ((index->datenum -index->next->datenum) == 0)
                    {
                            if ((index->datensec -index->next->datensec) > 0)
                            {
                                    index = index->next;
                                    result++;
                            }
                            else if ((index->datensec -index->next->datensec) == 0)
                            {
                                    if (ft_strcmp(index->fname, index->next->fname) <= 0)
                                    {
                                            index = index->next;
                                            result++;
                                    }
                                    else
                                            return (result);
                            }
                            else
                                    return (result);
                    }
                    else
                            return (result);
            }
        result = -1;
        return (result);
}

int  findNodeNamePlace(t_list *begin_list)
{
        t_list *index = begin_list;
        int result = 0;
        while (index != NULL && index->next != NULL)
            {
                    if (ft_strcmp(index->fname, index->next->fname) <= 0)
                    {
                            index = index->next;
                            result++;
                    }
                    else
                            return (result);
            }
        result = -1;
        return (result);
}

void printList(t_list *begin_list, int aflag)
{
    if (aflag == 1)
    {
            while (begin_list != NULL)
            {
                    printf("%s\n", begin_list->fname);
                    //printf("%ld\n", begin_list->datenum);
                    //printf("%ld\n\n", begin_list->datensec);
                    begin_list = begin_list->next;
            }
    }
    else
    {
            while (begin_list != NULL)
            {
                    if (begin_list->fname[0] != '.')
                    {
                            printf("%s\n", begin_list->fname);
                            //printf("%ld\n", begin_list->datenum);
                            //printf("%ld\n\n", begin_list->datensec);
                    }
                    begin_list = begin_list->next;
            }
    }
}

void deleteList(t_list* head_ref)
{
   t_list* current = head_ref;
   t_list* next;

   while (current != NULL)
   {
       next = current->next;
       free(current->fname);
       free(current);
       current = next;
   }
   head_ref = NULL;
}
