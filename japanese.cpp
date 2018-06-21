#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include<stdlib.h>
#include "japanese.h"
wchar_t *Japanese_alphabet_list();
void Japanese_input(wchar_t japanese_string[]);
int keyboard();
void Japanese_input(wchar_t japanese_string[])
{
	wchar_t *alphabet;
	while (1)
	{
		alphabet = Japanese_alphabet_list();
		if (alphabet[0] == 8)
		{
			if (japanese_string[0] == NULL)
				continue;
			else
			{
				japanese_string[wcslen(japanese_string) - 1] = NULL;
				wprintf(L"\b\b  \b\b");
			}
		}
		else if (alphabet[0] == 13)
		{
			printf("\n");
			break;
		}
		else if (alphabet[0] == NULL)
			continue;
		else
		{
			wcscat_s(japanese_string,100, alphabet);
			wprintf(L"%s", alphabet);
		}
	}
}
wchar_t *Japanese_alphabet_list()
{
	static wchar_t alphabet[3] = { NULL };
	int number1=keyboard(), number2, number3;
	switch (number1)
	{
	case 97://a
		alphabet[0] = L'ª¢';
		break;
	case 105://i
		alphabet[0] = L'ª¤';
		break;
	case 117://u
		alphabet[0] = L'ª¦';
		break;
	case 101://e
		alphabet[0] = L'ª¨';
		break;
	case 111://o
		alphabet[0] = L'ªª';
		break;
	case 107://k
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ª«';
			break;
		case 105:
			alphabet[0] = L'ª­';
			break;
		case 117:
			alphabet[0] = L'ª¯';
			break;
		case 101:
			alphabet[0] = L'ª±';
			break;
		case 111:
			alphabet[0] = L'ª³';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ª­';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ª­';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ª­';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 115://s
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªµ';
			break;
		case 105:
			alphabet[0] = L'ª·';
			break;
		case 117:
			alphabet[0] = L'ª¹';
			break;
		case 101:
			alphabet[0] = L'ª»';
			break;
		case 111:
			alphabet[0] = L'ª½';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ª·';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ª·';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ª·';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 116://t
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ª¿';
			break;
		case 105:
			alphabet[0] = L'ªÁ';
			break;
		case 117:
			alphabet[0] = L'ªÄ';
			break;
		case 101:
			alphabet[0] = L'ªÆ';
			break;
		case 111:
			alphabet[0] = L'ªÈ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªÁ';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªÁ';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªÁ';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 110://n
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÊ';
			break;
		case 105:
			alphabet[0] = L'ªË';
			break;
		case 117:
			alphabet[0] = L'ªÌ';
			break;
		case 101:
			alphabet[0] = L'ªÍ';
			break;
		case 111:
			alphabet[0] = L'ªÎ';
			break;
		case 110:
			alphabet[0] = L'ªó';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªË';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªË';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªË';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 104://h
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÏ';
			break;
		case 105:
			alphabet[0] = L'ªÒ';
			break;
		case 117:
			alphabet[0] = L'ªÕ';
			break;
		case 101:
			alphabet[0] = L'ªØ';
			break;
		case 111:
			alphabet[0] = L'ªÛ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªÒ';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªÒ';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªÒ';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 109://m
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÞ';
			break;
		case 105:
			alphabet[0] = L'ªß';
			break;
		case 117:
			alphabet[0] = L'ªà';
			break;
		case 101:
			alphabet[0] = L'ªá';
			break;
		case 111:
			alphabet[0] = L'ªâ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªß';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªß';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªß';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 121://y
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªä';
			break;
		case 117:
			alphabet[0] = L'ªæ';
			break;
		case 111:
			alphabet[0] = L'ªè';
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 114://r
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªé';
			break;
		case 105:
			alphabet[0] = L'ªê';
			break;
		case 117:
			alphabet[0] = L'ªë';
			break;
		case 101:
			alphabet[0] = L'ªì';
			break;
		case 111:
			alphabet[0] = L'ªí';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªê';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªê';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªê';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 119://w
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªï';
			break;
		case 111:
			alphabet[0] = L'ªò';
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 103://g
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ª¬';
			break;
		case 105:
			alphabet[0] = L'ª®';
			break;
		case 117:
			alphabet[0] = L'ª°';
			break;
		case 101:
			alphabet[0] = L'ª²';
			break;
		case 111:
			alphabet[0] = L'ª´';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ª®';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ª®';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ª®';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 122://z
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ª¶';
			break;
		case 105:
			alphabet[0] = L'ª¸';
			break;
		case 117:
			alphabet[0] = L'ªº';
			break;
		case 101:
			alphabet[0] = L'ª¼';
			break;
		case 111:
			alphabet[0] = L'ª¾';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ª¸';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ª¸';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ª¸';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 100://d
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÀ';
			break;
		case 105:
			alphabet[0] = L'ªÂ';
			break;
		case 117:
			alphabet[0] = L'ªÅ';
			break;
		case 101:
			alphabet[0] = L'ªÇ';
			break;
		case 111:
			alphabet[0] = L'ªÉ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªÂ';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªÂ';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªÂ';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 98://b
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÐ';
			break;
		case 105:
			alphabet[0] = L'ªÓ';
			break;
		case 117:
			alphabet[0] = L'ªÖ';
			break;
		case 101:
			alphabet[0] = L'ªÙ';
			break;
		case 111:
			alphabet[0] = L'ªÜ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªÓ';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªÓ';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªÓ';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 112://p
		number2 = keyboard();
		switch (number2)
		{
		case 97:
			alphabet[0] = L'ªÑ';
			break;
		case 105:
			alphabet[0] = L'ªÔ';
			break;
		case 117:
			alphabet[0] = L'ª×';
			break;
		case 101:
			alphabet[0] = L'ªÚ';
			break;
		case 111:
			alphabet[0] = L'ªÝ';
			break;
		case 121://y
			number3 = keyboard();
			switch (number3)
			{
			case 97:
				alphabet[0] = L'ªÔ';
				alphabet[1] = L'ªã';
				break;
			case 117:
				alphabet[0] = L'ªÔ';
				alphabet[1] = L'ªå';
				break;
			case 111:
				alphabet[0] = L'ªÔ';
				alphabet[1] = L'ªç';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 120://x
		number2 = keyboard();
		switch (number2)
		{
		case 116://t
			number3 = keyboard();
			switch (number3)
			{
			case 117://u
				alphabet[0] = L'ªÃ';
				break;
			default:
				alphabet[0] = NULL;
				break;
			}
			break;
		default:
			alphabet[0] = NULL;
			break;
		}
		break;
	case 8:
		alphabet[0] = 8;
		break;
	case 13:
		alphabet[0] = 13;
		break;
	case 48:
		alphabet[0] = '0';
		break;
	default:
		alphabet[0] = NULL;
		break;
	}
	return alphabet;
}

int keyboard()
{
	int char_num;
	while (1)
	{
		if (_kbhit())
		{
			char_num = _getch();
			break;
		}
	}
	return char_num;
}