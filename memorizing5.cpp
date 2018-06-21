/*
���α׷� �̸�: memorizing
�ۼ���: ������
����: �ܾ� �ܿ��
���ѻ���:
���α׷� ������ ���� ���� �Ұ�.
�ѹ��� �ܿ� �� �ִ� �ܾ� ������ ram ���ɿ� ���� �޶���.
����ܾ �ܿ�� ����(�ٸ� ��� ���� �ȵ�)
�̷»���:
1. ���� �ϼ�(2018.5.4)
2. ���ϳ����� ���� ����ϴ� ���� ���Ḯ��Ʈ�� �ٲ�, ���� �������̽��� �ѱ���� �ٲ�(2018.5.14)
3. ���ϵ��� save��� ������ �����ϰ� �ҷ������� ��, Ȯ���ڸ� �ڵ����� �Է�, �ܾ��� ���� ���� �ٲ� �� ����(2018.5.16)
4. ���ϸ���Ʈ 0���ϰ�� ó������ ���ư��� ��, ������ ������ �ʴ� ���� ����, �ܾ� ������ 0�� ��� ���������� �˸�(2018.5.17)
5. ���� ��������(2018.5.25)
6.
*/
#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<direct.h>
#include<io.h>
#include<time.h>
#include"japanese.h"
#define NAME 30
#define COUNT 30
#define LENGTH 300
typedef struct vocabulary_and_meaning
{
	wchar_t vocabulary[LENGTH];
	wchar_t meaning[LENGTH];
	struct vocabulary_and_meaning *link;
}voca;

void make_file(char file_name[]);//���� �����
int write_meaning(char file_name[]);//�ǹ� �ܿ��
int write_spelling(char file_name[]);//���縵 �ܿ��
int choose(int(*option)(int));//����
int option1(int op);//������(new file, load file, close)
int load_file_list(void);//���� ��� �ҷ�����
int option2(int op);//������(���ϸ��)
int option3(int op);//������(meaning,spelling)
void make_save_diractory(void);//save ���͸� �����
voca* shuffle(voca *list);//���� ����
int find_position(int length);//��ȯ�� ��ũ ����


char list[COUNT][NAME];

int main(void)
{
	char file_name[NAME];
	int wrong_count = 0;
	int select_num1 = 0, select_num2 = 0;
	int file_num;
	setlocale(LC_ALL, "");

	make_save_diractory();

	while (1)
	{
		select_num1 = choose(option1);
		if (select_num1 == 0)//������
			make_file(file_name);
		else if (select_num1 == 1)//��������� �ε�
		{
			if ((file_num = choose(option2)) == -1)
			{
				system("pause");
				continue;//���ϰ��� 0���� ��� ó������ 
			}
			strcpy_s(file_name, "save\\");
			strcat_s(file_name, list[file_num]);//list �迭���� �ش� ��ġ �̸� file_name���� ����
			select_num2 = choose(option3);
			if (select_num2 == 0)
			{
				while (1)// �ܾ� �ǹ� �׽�Ʈ
				{
					if ((wrong_count = write_meaning(file_name)) == 1)
					{
						system("cls");
						printf("�����մϴ�!! ��� �ܾ��� ���� �Ϻ��ϰ� �ܿ�̽��ϴ�.\n");
						system("pause");
						break;
					}
					else if (wrong_count == 0)
					{
						system("cls");
						printf("�� �����Դϴ�.\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("�� �ܿ�µ� %d�� �ɸ��̱���.\n", wrong_count);
						printf("�ѹ��� �� �ܿ� ������ �ݺ��н� �Ͻ� ���� ��õ�帳�ϴ�.\n");
						system("pause");
						break;
					}
				}
			}
			else
			{
				while (1)// ���縵 �׽�Ʈ
				{
					if ((wrong_count = write_spelling(file_name)) == 1)
					{
						system("cls");
						printf("�����մϴ�!! ��� �ܾ��� ���縵�� �Ϻ��ϰ� �ܿ�̽��ϴ�.\n");
						system("pause");
						break;
					}
					else if (wrong_count == 0)
					{
						system("cls");
						printf("�� �����Դϴ�.\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("�� �ܿ�µ� %d�� �ɸ��̱���.\n", wrong_count);
						printf("�ѹ��� �� �ܿ� ������ �ݺ��н� �Ͻ� ���� ��õ�帳�ϴ�.\n");
						system("pause");
						break;
					}
				}
			}
		}
		else//������
			exit(0);
	}
	return 0;
}
void make_file(char file_name[])
{
	int num = 1;
	voca input;
	FILE *file_pointer;
	char f_name[NAME];
	strcpy_s(file_name, NAME, "save\\");
	system("cls");
	printf("���� �̸��� ���ϼ���\n");
	scanf_s("%s", f_name, NAME);
	getchar();//���� ���ֱ�
	strcat_s(file_name, NAME, f_name);
	strcat_s(file_name, NAME, ".txt");
	fopen_s(&file_pointer, file_name, "w");
	while (1)
	{
		input = { NULL, NULL, NULL };
		system("cls");
		printf("�ܿ� �ܾ �Է��ϼ���. ���� �� ������ 0�� �Է��ϼ���.\n");
		printf("%d��° ���縵: \n", num);
		Japanese_input(input.vocabulary);
		printf("%d��° �ܾ��� �ǹ�: \n", num);
		_getws_s(input.meaning, LENGTH);

		if (input.vocabulary[0] == '0')
			break;

		fwprintf(file_pointer, L"%s%c", input.vocabulary, '\n');
		fwprintf(file_pointer, L"%s%c", input.meaning, '\n');

		num++;
	}
	fclose(file_pointer);
}

int write_meaning(char file_name[])
{
	FILE *file_pointer;
	voca *p, *prev = NULL, *next;
	voca *list = NULL;
	voca compare;
	int wrong_count = 0;
	fopen_s(&file_pointer, file_name, "r");
	while (1)//�ܾ����� ���� ����Ʈ�� ����
	{
		p = (voca*)malloc(sizeof(voca));
		if (fgetws(p->vocabulary, LENGTH, file_pointer) == NULL)
		{
			free(p);
			break;
		}
		fgetws(p->meaning, LENGTH, file_pointer);
		for (int i = 0; i < LENGTH; i++)//fgetws�������� ���Ͱ� ���� �ǹǷ� �����̽��� �ٲ�
		{
			if (p->vocabulary[i] == '\n')
				p->vocabulary[i] = NULL;
			if (p->meaning[i] == '\n')
				p->meaning[i] = NULL;
		}
		if (list == NULL)
			list = p;
		else
			prev->link = p;
		p->link = NULL;
		prev = p;
	}
	fclose(file_pointer);
	while (prev != NULL)
	{
		p = list;
		prev = NULL;
		wrong_count++;
		while (p != NULL)//�񱳽���
		{
			system("cls");
			printf("%d ȸ��\n", wrong_count);
			wprintf(L"%s: ", p->vocabulary);
			_getws_s(compare.meaning, LENGTH);
			if (wcscmp(compare.meaning, p->meaning) == 0)
			{
				printf("�����Դϴ�!!\n");
				next = p->link;
				free(p);
				if (prev == NULL)
					list = next;
				else
					prev->link = next;
				p = next;
				system("pause");
			}
			else
			{
				wprintf(L"Ʋ�Ƚ��ϴ�!! ���� %s �Դϴ�.\n", p->meaning);
				prev = p;
				p = p->link;
				system("pause");
			}
		}
	}

	return wrong_count;
}

int write_spelling(char file_name[])
{
	FILE *file_pointer;
	voca compare;
	voca *prev = NULL, *p, *next;
	voca *list = NULL;
	int wrong_count = 0;
	fopen_s(&file_pointer, file_name, "r");
	while (1)
	{
		p = (voca*)malloc(sizeof(voca));
		if (fgetws(p->vocabulary, LENGTH, file_pointer) == NULL)
		{
			free(p);
			break;
		}
		fgetws(p->meaning, LENGTH, file_pointer);
		for (int i = 0; i < LENGTH; i++)//fgetws�������� ���Ͱ� ���� �ǹǷ� �����̽��� �ٲ�
		{
			if (p->vocabulary[i] == '\n')
				p->vocabulary[i] = NULL;
			if (p->meaning[i] == '\n')
				p->meaning[i] = NULL;
		}
		if (list == NULL)
			list = p;
		else
			prev->link = p;
		p->link = NULL;
		prev = p;
	}
	fclose(file_pointer);
	while (prev != NULL)
	{
		p = list;
		prev = NULL;
		wrong_count++;
		while (p != NULL)
		{
			system("cls");
			printf("%d ȸ��\n", wrong_count);
			wprintf(L"%s: ", p->meaning);
			compare = { NULL };
			Japanese_input(compare.vocabulary);
			if (wcscmp(compare.vocabulary, p->vocabulary) == 0)
			{
				printf("�����Դϴ�!!\n");
				next = p->link;
				free(p);
				if (prev == NULL)
					list = next;
				else
					prev->link = next;
				p = next;
				system("pause");
			}
			else
			{
				wprintf(L"Ʋ�Ƚ��ϴ�!! ���� %s �Դϴ�.\n", p->vocabulary);
				prev = p;
				p = p->link;
				system("pause");
			}
		}
	}
	return wrong_count;
}

int choose(int(*option)(int))//list_count�� -1�� ��� -1 ��ȯ �� ������
{
	int i, op = 0, list_count;
	while (1)
	{
		system("cls");
		if ((list_count = option(op)) == -1)
			return -1;
		else
		{
			list_count--;
			while (1)
			{
				if (_kbhit())
				{
					i = _getch();
					if (i == 224)
					{
						i = _getch();
						if (i == 72)
						{
							op--;
							if (op < 0)
								op = list_count;
							break;
						}
						else if (i == 80)
						{
							op++;
							if (op > list_count)
								op = 0;
							break;
						}
					}
					else if (i == 13)
						break;
				}
			}
		}
		if (i == 13)
			break;
	}
	return op;
}

int option1(int op)
{
	int list_count = 3;

	if (op == 0)
	{
		printf("�� ���� �����\n\n");
		printf("   �ҷ�����\n\n");
		printf("   ������\n\n");
	}
	else if (op == 1)
	{
		printf("   ���� �����\n\n");
		printf("�� �ҷ�����\n\n");
		printf("   ������\n\n");
	}
	else if (op == 2)
	{
		printf("   ���� �����\n\n");
		printf("   �ҷ�����\n\n");
		printf("�� ������\n\n");
	}
	return list_count;
}

int load_file_list(void)
{
	_finddata_t file_search;
	int i = 0, list_count = 0;
	long check;
	char path[] = "save\\*.txt";
	if ((check = _findfirst(path, &file_search)) == -1L)
		list_count = -1;
	else
	{
		do
		{
			strcpy_s(list[list_count], NAME, file_search.name);
			list_count++;
		} while (_findnext(check, &file_search) == 0);
		_findclose(check);
	}
	return list_count;
}

int option2(int op)
{
	int i;
	int list_count = load_file_list();
	if (list_count == -1)
	{
		printf("�ڷᰡ �����ϴ�.\n");
		printf("�� �ǵ��ư���\n");
	}
	else
	{
		for (i = 0; i < list_count; i++)
		{
			if (i == op)
				printf("�� ");
			else
				printf("   ");
			printf("%d��: %s\n", i + 1, list[i]);
		}
	}
	return list_count;
}

int option3(int op)
{
	int list_count = 2;

	if (op == 0)
	{
		printf("�� �� �ܿ��\n\n");
		printf("   ���縵 �ܿ��\n\n");
	}
	else
	{
		printf("   �� �ܿ��\n\n");
		printf("�� ���縵 �ܿ��\n\n");
	}

	return list_count;
}

void make_save_diractory(void)
{
	_mkdir("save");
}

voca* shuffle(voca *list)
{
	voca *prev = NULL, *p, *next;
	int i,j, length;
	p = list;
	for (i = 0; p != NULL; i++)
		p = p->link;
	length = i;
	p = list;
	for (i = 0; i < find_position(length); i++)
		p = p->link;
	next = list->link;
	prev = list;
	list = p;
	return list;
}

int find_position(int length)
{
	srand((unsigned)time(NULL));
	int position;
	position = rand() % length;
	return position;
}