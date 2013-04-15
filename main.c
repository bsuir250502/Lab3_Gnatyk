/*Реализовать программу учета занятых и свободных мест в 
общежитии, а также лиц, нуждающихся в общежитии. Одним из элементов 
созданной очереди является номер этажа, другим – общее количество мест 
на этаже, количество свободных мест, список лиц, проживающих на этаже. 
Если свободных мест нет, то студент ставится в очередь на вселение на 
соответствующий этаж.*/
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
struct turn{
	char inf[50];
char floor[10];
struct turn *ykazatel_na_struct;};




char *gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1] = '\0';
    return result;
}
//функция создания очереди//
void add(turn **h)
{
	turn*n;//указатель на создаваемую структуру//
	int inf_size=SIZE(n->inf);
	int floor_size=SIZE(n->floor);
	printf("the creation of the queue \n");
	do {
	if(!(n=(turn*)calloc(1,sizeof(turn)))){
		printf("is no free memory\n");
	return;}
	printf("Please,enter your last name");
	gets_s(n->inf,inf_size);
	printf("Enter the number the floor where you want to live");
	gets_s(n->floor,floor_size);
	if(!*h){
		*h=n;}//хвост очереди
	else{
		n->ykazatel_na_struct=*h;
		*h=n;}
	printf(" To continue, press: y:");
	fflush(stdin);}
	while(getch()=='y');
}





void main(void)
{
 struct turn *h, *t;
 char l,*st;
 st=(char*)malloc(10);
 h=NULL;
 while(1){
	 puts("If you want to live in a hostel- please press 1");
	 puts("to exit- please press 0");
	 fflush(stdin);
	 switch(getch()){
	 case'1':add(&h);break;
	 case'0':return;
	 default:printf("error, continue\n");}
 }
}
