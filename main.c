
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>
#define koll_l_na_et 10
#define kol_et 3
#define SIZE( x ) (sizeof( x )/sizeof( *x ))

struct zasel{
	char name[20];
	char floor[koll_l_na_et];}student;
struct ochered{
	char name[20];
	struct ochered*next;
    int number_flor;}student;
	
char*gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1] = '\0';
    return result;
}

int add_list(int etash[kol_et],int kol_zas, zasel* students_list)
{
	int j;
    students_list[kol_zas].floor=etash_koll(&etash[kol_et]);
    printf("Vvedite svoy famoloy");
    gets_s(students_list->name);	
    kol_zas++;
    etash[j]++;
	return kol_zas,etash[j];
}

ochered add_ocher(ochered**begin,ochered * student_list,int kol_chel_v_och)
{
	int name_size=SIZE(student_list->name);
	kol_chel_v_och ++;
    do{
	if(!(*begin=(ochered *) calloc(1,sizeof(ochered)))) {
		puts("Нет свободной памяти"); return;}
	printf("Vvedite svoe FIO");
	gets_s(student_list->name,name_size);
	if(!*begin){
		*begin=student_list;}
	else{
		student_list->next=*begin;
	    *begin=student_list;}
	}while(getch()=='y');

}

int etash_koll(int etash[kol_et])
{
	int i,j;
	for(i=0;i<kol_et;i++){
		if(etash[i]<10){
			j=i;break;}}
	return j;
}

int ydal_chel_is_ob(int kol_zas,int etash[j],zasel*students_list)
{
	int i;
	int name_size=SIZE(students_list[kol_zas].name);
	printf("Vvedite svoe FIO");
	gets_s(students_list[kol_zas].name,name_size);
	for(i=kol_zas;kol_zas!=0;i--){
	if(strcmp(students_list[i].name,students_list[i-1].name))
	{students_list[i].name=0;
    kol_zas=kol_zas-1;
	etash[j]--;
	}
}

void main(void)
{
	int j=0;
 struct ochered *begin,*end;
 int kol_chel_v_och =0;
 int cvob_mest_et = koll_l_na_et*kol_et;
 int kol_zas = 0;
 struct zasel students_list[150];
 struct ochered student_list[150];
 int etash[kol_et];
 struct ochered *head;
 char l,*st;
 st=(char*)malloc(10);
 head=NULL;
 while(1){
	 puts("If you want to live in a hostel- please press 1");
	 puts("Esli vi hotite visilitsia - please press 2");
	 puts("to exit- please press 0");
	 fflush(stdin);
	 switch(getch()){
	 case'1':if(kol_zas==koll_l_na_et*kol_et)
			 kol_chel_v_och= add_ocher(&begin, student_list, kol_chel_v_och); break;
	         if(!kol_zas==koll_l_na_et*kol_et)
			 {kol_zas,etash[j]=add_list(&etash[kol_et],kol_zas,students_list); break;}
		  
	 case'2': ydal_chel_is_ob(kol_zas,&etash[j], kol_chel_v_och,students_list); break;

	 case'0':return;
	 default:printf("error, continue\n");}
 }
}
