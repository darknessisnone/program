#include "linkcontact.h"

int main()
{
	int num = 0;
	contact *con = contactcreate();
	do
	{
		menuL();
		printf("选择您的操作>>");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			int input = 0;
			login(con);
			do
			{
				menuM();
				printf("选择您的操作>>");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					personadd(con);
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 2:
					contactview(con);
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 3:
				{
					int fig;
					menuS();
				THIRD:
					printf("请您选择操作>>");
					scanf("%d", &fig);
					if (fig == 1)
					{
						searchID(con);
					}
					else if (fig == 2)
					{
						searchN(con);
					}
					else if (fig == 0)
					{
						break;
					}
					else
					{
						printf("输入有误，请重新输入\n");
						goto THIRD;
					}
				}
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 4:
				{
					contact *con1 = contactcreate();
					contactcopy(con, con1);
					sortpersonbyname(con1);
					contactview(con1);
				}
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 5:
				{
					contact *con2 = contactcreate();
					contactcopy(con, con2);
					sortpersonbyid(con2);
					contactview(con2);
				}
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 6:
					persondelete(con);
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 7:
					personalter(con);
					printf("press any key to continue");
					getchar();
					getchar();
					break;
				case 0:
					logout(con);
					deleteall(con);
					printf("返回主菜单\npress any key to continue");
					getchar();
					getchar();
					break;
				default:
					printf("输入有误，请重新输入\n");
					break;
				}
			} while (input);
		}
		break;
		case 0:
			exit(0);
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (num);
	return 0;
}
