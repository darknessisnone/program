#include "linkcontact.h"

void filepersonadd(contact *head, contact *temp)
{
    contact *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    contact *cont = (contact *)malloc(sizeof(contact));
    cont->next = NULL;

    cont->per.id = temp->per.id;
    strcpy(cont->per.name, temp->per.name);
    strcpy(cont->per.number, temp->per.number);

    cont->next = p->next;
    p->next = cont;
    return;
}
//登陆，将文件中的信息取出到contact中
void login(contact *head)
{
    FILE *fp = fopen("./contact.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    int flags = 0;
    while (1)
    {
        contact *p1 = (contact *)malloc(sizeof(contact));
        p1->next = NULL;
        if (0 == fread(&(p1->per), sizeof(p1->per), 1, fp))
        {
            free(p1); //
            if (feof(fp))
            {
                printf("文件已读取完毕\n");
                break;
            }
            else
            {
                perror("fread");
                break;
            }
        }
        filepersonadd(head, p1);
        flags++;
    }
    if (flags == 0)
    {
        printf("文件为空\n");
    }
    if (-1 == fclose(fp))
    {
        perror("fclose");
        return;
    }
    return;
}
