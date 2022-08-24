#ifndef _LINKCONTACT_H
#define _LINKCONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef int datatype;
typedef struct person
{
    int id;
    char name[32];
    char number[32];
} person;

typedef struct contact
{
    struct person per;
    struct contact *next;
} contact;

//主菜单
void menuL();
void menuM();
void menuS();
//创建通讯录
contact *contactcreate();
//通讯录为空?
bool contactisnull(contact *head);
//添加联系人
void personadd(contact *head);
//有头结点的通讯录链表遍历
void contactview(contact *head);
//删除联系人
void persondelete(contact *head);
//修改联系人信息
void personalter(contact *head);
//搜索联系人
//按id搜索
void searchID(contact *head);
//按姓名搜索
void searchN(contact *head);
//复制通讯录
void contactcopy(contact *p, contact *q);
//按姓名排序
void sortpersonbyname(contact *head);
//按id排序
void sortpersonbyid(contact *head);
//清空链表
void deleteall(contact *head);

// LOGIN
void login(contact *head);
// LOGOUT
void logout(contact *head);

#endif
