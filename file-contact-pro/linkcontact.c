#include "linkcontact.h"

//主菜单
void menuL()
{
    printf("\n*********************************\n");
    printf("* 1:进入通讯录\t   0:退出程序\t*\n");
    printf("*********************************\n");
}
void menuM()
{
    printf("\n*********************************\n");
    printf("* 1:添加联系人\t   2:查看通讯录\t*\n");
    printf("* 3:搜索联系人\t   4:按姓名查看\t*\n");
    printf("* 5:按id查看\t   6:删除联系人\t*\n");
    printf("* 7:修改信息\t   0:保存并返回\t*\n");
    printf("*********************************\n");
}
void menuS()
{
    printf("\n*********************************\n");
    printf("*\t1: 按id搜索\t\t*\n");
    printf("*\t2: 按姓名搜索\t\t*\n");
    printf("*\t0: 返回菜单\t\t*\n");
    printf("*********************************\n");
}

//创建通讯录
contact *contactcreate()
{
    contact *head = (contact *)malloc(sizeof(contact));
    head->next = NULL;
    return head;
}
//通讯录为空?
bool contactisnull(contact *head)
{
    return head->next == NULL ? 1 : 0;
}
//添加联系人
void personadd(contact *head)
{
    while (1)
    {
        contact *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        contact *temp = (contact *)malloc(sizeof(contact));
        temp->next = NULL;
        printf("请输入联系人序号: ");
        scanf("%d", &(temp->per.id));
        printf("请输入联系人姓名: ");
        scanf("%s", temp->per.name);
    NUM_SIZE:
        printf("请输入联系人号码: ");
        scanf("%s", temp->per.number);
        if (strlen(temp->per.number) != 11)
        {
            printf("号码不符合规范\n");
            goto NUM_SIZE;
        }
        temp->next = p->next;
        p->next = temp;
        printf("添加成功\n");
        while (1)
        {
            char a;
            printf("是否继续输入(y/n):");
            scanf("%s", &a);
            if (a == 'y')
            {
                break;
            }
            else if (a == 'n')
            {
                printf("返回主菜单\n");
                return;
            }
            else
            {
                printf("输入错误，请重新输入\n");
                continue;
            }
        }
    }
}
//有头结点的通讯录链表遍历
void contactview(contact *head)
{
    printf("通讯录为:\n");
    if (contactisnull(head))
    {
        printf("空\n");
        return;
    }
    contact *p = head;
    while (p->next != NULL)
    {
        printf("id:%d\nname:%s\nnumber:%s\n\n", p->next->per.id, p->next->per.name, p->next->per.number); //输出头结点后的结点数据
        p = p->next;                                                                                      // p->next=NULL时，表明p是最后一个结点
    }
}
//根据名字返回结点
contact *findpersonbyname(contact *head, char name[32])
{
    contact *p = head;
    while (p->next != NULL)
    {
        if (0 == strcmp(p->next->per.name, name))
        {
            return p;
        }
        p = p->next;
    }
    return NULL; //指针型变量，错误时返回值为空
}
//删除联系人
void persondelete(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    char name[32];
    printf("输入要删除的联系人姓名:");
    scanf("%s", name);
    contact *cnt = findpersonbyname(head, name);
    if (cnt == NULL) //指针型变量
    {
        printf("未查找到相关记录\n");
    }
    else
    {
        contact *temp = cnt->next;
        cnt->next = cnt->next->next;
        free(temp);
        temp = NULL;
        printf("删除成功\n");
    }
}
//修改联系人信息
void personalter(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    char name[32];
    printf("输入要修改的联系人姓名:");
    scanf("%s", name);
    contact *cnt = findpersonbyname(head, name);
    if (cnt == NULL)
    {
        printf("未查找到相关记录\n");
    }
    else
    {
        contact *p = cnt->next;
        contact *temp = (contact *)malloc(sizeof(contact));
        temp->next = NULL;
        temp->per.id = p->per.id;
        strcpy(temp->per.name, p->per.name);
    NUM_ALTER:
        printf("修改联系人号码为: ");
        scanf("%s", temp->per.number);
        if (strlen(temp->per.number) != 11)
        {
            printf("号码不符合规范\n");
            goto NUM_ALTER;
        }
        temp->next = p->next;
        cnt->next = temp;
        p->next = temp;
        free(p);
        p = NULL;
        printf("修改成功\n");
    }
}
//搜索联系人
//按id搜索
void searchID(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    int id;
    printf("请输入要查找的id:");
    scanf("%d", &id);
    contact *p = head;
    int flags = 0;
    while (p->next != NULL)
    {
        if (p->next->per.id == id)
        {
            printf("id:%d\nname:%s\nnumber:%s\n\n", p->next->per.id, p->next->per.name, p->next->per.number);
            flags++;
        }
        p = p->next;
    }
    if (flags == 0)
    {
        printf("未查找到相关记录\n");
    }
}
//按姓名搜索
void searchN(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    char name[32];
    printf("请输入要查找的姓名:");
    scanf("%s", name);
    int len = strlen(name);
    contact *p = head;
    int flags = 0;
    while (p->next != NULL)
    {
        if (0 == strncmp(p->next->per.name, name, len))
        {
            printf("id:%d\nname:%s\nnumber:%s\n\n", p->next->per.id, p->next->per.name, p->next->per.number);
            flags++;
        }
        p = p->next;
    }
    if (flags == 0)
    {
        printf("未查找到相关记录\n");
    }
}
//复制通讯录
void contactcopy(contact *p, contact *q)
{
    if (contactisnull(p))
    {
        printf("通讯录为空\n");
        return;
    }
    while (p->next != NULL)
    {
        contact *temp = (contact *)malloc(sizeof(contact));
        temp->next = NULL;
        temp->per = p->next->per;
        while (q->next != NULL)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
        p = p->next;
    }
}
//按姓名排序
void sortpersonbyname(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    contact *p = head->next;
    int flags = 0;
    if (p->next == NULL)
    {
        printf("只有1个联系人,无需排序\n");
        return;
    }
    while (1)
    {
        while (p->next != NULL)
        {
            contact *temp = (contact *)malloc(sizeof(contact));
            temp->next = NULL;
            if (strcmp(p->per.name, p->next->per.name) > 0)
            {
                temp->per.id = p->per.id;
                strcpy(temp->per.name, p->per.name);
                strcpy(temp->per.number, p->per.number);

                p->per.id = p->next->per.id;
                strcpy(p->per.name, p->next->per.name);
                strcpy(p->per.number, p->next->per.number);

                p->next->per.id = temp->per.id;
                strcpy(p->next->per.name, temp->per.name);
                strcpy(p->next->per.number, temp->per.number);

                flags++;
            }
            free(temp);
            p = p->next;
        }
        p = head->next;
        if (flags == 0)
        {
            break;
        }
        else
        {
            flags = 0;
        }
    }
    printf("完成排序\n");
}
//按id排序
void sortpersonbyid(contact *head)
{
    if (contactisnull(head))
    {
        printf("通讯录为空\n");
        return;
    }
    contact *p = head->next;
    int flags = 0;
    if (p->next == NULL)
    {
        printf("只有1个联系人，无需排序\n");
        return;
    }
    while (1)
    {
        while (p->next != NULL)
        {
            contact *temp = (contact *)malloc(sizeof(contact));
            temp->next = NULL;
            if (p->per.id > p->next->per.id)
            {
                temp->per.id = p->per.id;
                strcpy(temp->per.name, p->per.name);
                strcpy(temp->per.number, p->per.number);

                p->per.id = p->next->per.id;
                strcpy(p->per.name, p->next->per.name);
                strcpy(p->per.number, p->next->per.number);

                p->next->per.id = temp->per.id;
                strcpy(p->next->per.name, temp->per.name);
                strcpy(p->next->per.number, temp->per.number);

                flags++;
            }
            free(temp);
            p = p->next;
        }
        p = head->next;
        if (flags == 0)
        {
            break;
        }
        else
        {
            flags = 0;
        }
    }
    printf("完成排序\n");
}
//清空链表
void deleteall(contact *head)
{
    if (contactisnull(head))
    {
        printf("链表为空\n");
        return;
    }
    contact *p, *q;
    p = head->next;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    head->next = NULL;
    return;
}