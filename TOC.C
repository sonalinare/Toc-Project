#include <stdio.h>
#include <string.h>

int dfa = 0;
int count=0;

void start(char c)
{
    if (c == 'a') {
	dfa = 1;
	count++;
    }
    else if (c == 'b') {
	dfa = 3;
    }


    else {
	dfa = -1;
    }
}

void state1(char c)
{
    if (c == 'a') {
    printf("q1->");
	dfa = 2;
	count++;
    }
    else if (c == 'b') {
    printf("q4->");
	dfa = 4;
    }
    else {
	dfa = -1;
    }
}

void state2(char c)
{
    if (c == 'b') {
    printf("q3->");
	dfa = 3;
    }
    else if (c == 'a') {
    printf("q1->");
	dfa = 1;
    }
    else {
	dfa = -1;
    }
}

void state3(char c)
{
    if (c == 'b') {
    printf("q3->");
	dfa = 3;
    }
    else if (c == 'a') {
    printf("q4");
	dfa = 4;
    }
    else {
	dfa = -1;
    }
}

void state4(char c)
{
    dfa = -1;
}


int isAccepted(char str[])
{
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
	if (dfa == 0)
	    start(str[i]);

	else if (dfa == 1)
	    state1(str[i]);

	else if (dfa == 2)
	    state2(str[i]);

	else if (dfa == 3)
	    state3(str[i]);

	else if (dfa == 4)
	    state4(str[i]);
	else
	    return 0;
    }
    if (count==2)
	return 1;
    else
	return 0;
}
void main()
{
    char str[10];
    clrscr();
    printf("enter string");
    gets(str);
    if (isAccepted(str))
	printf("ACCEPTED");
    else
	printf("NOT ACCEPTED");
    getch();
}

