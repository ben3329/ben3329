/*
프로그램 이름: memorizing
작성자: 지원혁
목적: 단어 외우기
제한사항:
프로그램 내에서 파일 수정 불가.
한번에 외울 수 있는 단어 개수는 ram 성능에 따라 달라짐.
영어단어만 외울수 있음(다른 언어 지원 안됨)
이력사항:
1. 파일 완성(2018.5.4)
2. 파일내용을 직접 출력하는 것을 연결리스트로 바꿈, 영어 인터페이스를 한국어로 바꿈(2018.5.14)
3. 파일들을 save라는 폴더에 저장하고 불러오도록 함, 확장자명 자동으로 입력, 단어장 개수 제한 바꿀 수 있음(2018.5.16)
4. 파일리스트 0개일경우 처음으로 돌아가게 함, 파일이 열리지 않는 오류 수정, 단어 개수가 0일 경우 빈파일임을 알림(2018.5.17)
5. 띄어쓰기 가능해짐(2018.5.25)
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

void make_file(char file_name[]);//파일 만들기
int write_meaning(char file_name[]);//의미 외우기
int write_spelling(char file_name[]);//스펠링 외우기
int choose(int(*option)(int));//선택
int option1(int op);//선택지(new file, load file, close)
int load_file_list(void);//파일 목록 불러오기
int option2(int op);//선택지(파일목록)
int option3(int op);//선택지(meaning,spelling)
void make_save_diractory(void);//save 디렉터리 만들기
voca* shuffle(voca *list);//순서 섞기
int find_position(int length);//교환할 링크 선정


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
		if (select_num1 == 0)//새파일
			make_file(file_name);
		else if (select_num1 == 1)//저장된파일 로드
		{
			if ((file_num = choose(option2)) == -1)
			{
				system("pause");
				continue;//파일개수 0개일 경우 처음으로 
			}
			strcpy_s(file_name, "save\\");
			strcat_s(file_name, list[file_num]);//list 배열에서 해당 위치 이름 file_name으로 복사
			select_num2 = choose(option3);
			if (select_num2 == 0)
			{
				while (1)// 단어 의미 테스트
				{
					if ((wrong_count = write_meaning(file_name)) == 1)
					{
						system("cls");
						printf("축하합니다!! 모든 단어의 뜻을 완벽하게 외우셨습니다.\n");
						system("pause");
						break;
					}
					else if (wrong_count == 0)
					{
						system("cls");
						printf("빈 파일입니다.\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("다 외우는데 %d번 걸리셨군요.\n", wrong_count);
						printf("한번에 다 외울 때까지 반복학습 하실 것을 추천드립니다.\n");
						system("pause");
						break;
					}
				}
			}
			else
			{
				while (1)// 스펠링 테스트
				{
					if ((wrong_count = write_spelling(file_name)) == 1)
					{
						system("cls");
						printf("축하합니다!! 모든 단어의 스펠링을 완벽하게 외우셨습니다.\n");
						system("pause");
						break;
					}
					else if (wrong_count == 0)
					{
						system("cls");
						printf("빈 파일입니다.\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("다 외우는데 %d번 걸리셨군요.\n", wrong_count);
						printf("한번에 다 외울 때까지 반복학습 하실 것을 추천드립니다.\n");
						system("pause");
						break;
					}
				}
			}
		}
		else//끝내기
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
	printf("파일 이름을 정하세요\n");
	scanf_s("%s", f_name, NAME);
	getchar();//엔터 없애기
	strcat_s(file_name, NAME, f_name);
	strcat_s(file_name, NAME, ".txt");
	fopen_s(&file_pointer, file_name, "w");
	while (1)
	{
		input = { NULL, NULL, NULL };
		system("cls");
		printf("외울 단어를 입력하세요. 만약 다 했으면 0을 입력하세요.\n");
		printf("%d번째 스펠링: \n", num);
		Japanese_input(input.vocabulary);
		printf("%d번째 단어의 의미: \n", num);
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
	while (1)//단어목록을 연결 리스트로 만듦
	{
		p = (voca*)malloc(sizeof(voca));
		if (fgetws(p->vocabulary, LENGTH, file_pointer) == NULL)
		{
			free(p);
			break;
		}
		fgetws(p->meaning, LENGTH, file_pointer);
		for (int i = 0; i < LENGTH; i++)//fgetws마지막에 엔터가 저장 되므로 스페이스로 바꿈
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
		while (p != NULL)//비교시작
		{
			system("cls");
			printf("%d 회차\n", wrong_count);
			wprintf(L"%s: ", p->vocabulary);
			_getws_s(compare.meaning, LENGTH);
			if (wcscmp(compare.meaning, p->meaning) == 0)
			{
				printf("정답입니다!!\n");
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
				wprintf(L"틀렸습니다!! 답은 %s 입니다.\n", p->meaning);
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
		for (int i = 0; i < LENGTH; i++)//fgetws마지막에 엔터가 저장 되므로 스페이스로 바꿈
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
			printf("%d 회차\n", wrong_count);
			wprintf(L"%s: ", p->meaning);
			compare = { NULL };
			Japanese_input(compare.vocabulary);
			if (wcscmp(compare.vocabulary, p->vocabulary) == 0)
			{
				printf("정답입니다!!\n");
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
				wprintf(L"틀렸습니다!! 답은 %s 입니다.\n", p->vocabulary);
				prev = p;
				p = p->link;
				system("pause");
			}
		}
	}
	return wrong_count;
}

int choose(int(*option)(int))//list_count가 -1일 경우 -1 반환 후 나가기
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
		printf("▶ 새로 만들기\n\n");
		printf("   불러오기\n\n");
		printf("   끝내기\n\n");
	}
	else if (op == 1)
	{
		printf("   새로 만들기\n\n");
		printf("▶ 불러오기\n\n");
		printf("   끝내기\n\n");
	}
	else if (op == 2)
	{
		printf("   새로 만들기\n\n");
		printf("   불러오기\n\n");
		printf("▶ 끝내기\n\n");
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
		printf("자료가 없습니다.\n");
		printf("▶ 되돌아가기\n");
	}
	else
	{
		for (i = 0; i < list_count; i++)
		{
			if (i == op)
				printf("▶ ");
			else
				printf("   ");
			printf("%d번: %s\n", i + 1, list[i]);
		}
	}
	return list_count;
}

int option3(int op)
{
	int list_count = 2;

	if (op == 0)
	{
		printf("▶ 뜻 외우기\n\n");
		printf("   스펠링 외우기\n\n");
	}
	else
	{
		printf("   뜻 외우기\n\n");
		printf("▶ 스펠링 외우기\n\n");
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