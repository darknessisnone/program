#include "linkcontact.h"

void logout(contact *head)
{
    FILE *fp = fopen("./contact.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    contact *p2 = head->next;
    while (p2 != NULL)
    {
        if (1 != fwrite(&(p2->per), sizeof(p2->per), 1, fp))
        {
            perror("fwrite");
            return;
        }
        p2 = p2->next;
    }
    if (-1 == fclose(fp))
    {
        perror("fclose");
        return;
    }
    printf("保存结束，退出通讯录\n");
}