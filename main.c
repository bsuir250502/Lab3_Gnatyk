#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define input_buf_size 80
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
#define max_num_host 15
#define number_of_floors 2
#define max_num_floor 5


typedef struct settled{
	char name[20];
	char floor[max_num_floor];}student;

typedef struct turn{
	char name[20];
	struct turn*next;};
	
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char*gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1] = '\0';
    return result;
}

int  moving_hostel(int floor[number_of_floors], int num_set_hostel,int current_floor,settled*students_list)
{
	int name_size = SIZE(students_list[num_set_hostel].name);
	int i;
    for(i=0;i<number_of_floors;i++){floor[i]=0;}
	for(current_floor = 0;current_floor < number_of_floors;current_floor ++){
		if(floor[current_floor] < max_num_floor){
			floor[current_floor] = floor[current_floor] + 1;
            printf("Enter last name of students");
	        gets_s(students_list[num_set_hostel].name,name_size);
	        students_list[num_set_hostel].floor,&current_floor;}
		break;}
	return floor[current_floor];
}

int choice_of_floor( int num_set_hostel)
{
	num_set_hostel ++ ;
    return num_set_hostel;
}

void add_to_queue(turn**p,turn* student_list,int current_person_queue)
{
	int name_size= SIZE(student_list[current_person_queue].name);
	turn * begin;
	if(!(begin = (turn*)calloc(1,sizeof(turn)))){
		puts("There is no free memory");return;}
    puts("I'm sorry to the hostel not available, we will put you in a place to settle\n");
	puts("please, repeat your last name\n");
	gets_s(student_list[current_person_queue].name,name_size);
	if(!*p){
		*p = begin;}
	else{
		begin->next = *p;
		*p = begin;}
}

int removed_from_the_queue(turn **p)
{
	turn*pr;
	if(!*p){
		return 0;}
	if(!(*p)->next){
		free(*p);
		*p = NULL;
		return 0;}
	pr=*p;
	while(pr->next->next)
		pr= pr->next;
	free(pr->next);
	pr->next = NULL;
	return 0;
}

int remove_from_the_living(int floor[number_of_floors],int num_set_hostel,settled* students_list,turn **p )
{
	int i;
	char*s=(char*)malloc(sizeof(int));
	int s_size = SIZE(s);
	printf("Enter last name of the student");
	gets_s(s, s_size);
	for(i = 0;i < num_set_hostel;i++){
		if(students_list[i].name == s){
			break;
			students_list[i].name == 0;
			floor[number_of_floors] = floor[number_of_floors]-1;
			num_set_hostel --;}}
	if(*p){
		printf("Enter last name of students");
		students_list[i].name,s;
		num_set_hostel++;
		floor[number_of_floors] = floor[number_of_floors]+1;}
	return num_set_hostel;
}

void list_of_living(settled* students_list,int num_set_hostel)
{
	int i;
	for(i=0;i<num_set_hostel;i++){
		printf("List of living:\n  ");
	    printf("\n",students_list[i].name );}
}

int menu_select()
{
	char s[input_buf_size];
    int c;
    puts("1. If you want to live in a hostel");
	puts("2. If you want to move out ");
    puts("3. If you want to view the list of living in a hostel");
    puts("4. Help"); 
	puts("5. to exit");
	do{
		printf("\nEnter the number of the desired item\n");
        gets_s(s, input_buf_size);
        c = atoi(s);}
    while (c < 0 || c > 5);
    clear_screen();
    return c;
}

void checkHelp(void)
{
     printf
        ("=============================================================================================================\n"
         "MANUAL:\n"
         "Enter information about the students: last name, \n"
         "=================================OPTIONS=====================================================================\n"
         "1. If you want to live in a hostel\n"
         "2. If you want to move out of the hostel\n"
         "3. If you want to view a list of students living in a hostel\n"
		 "4. Help\n"
		 "5. Exit\n"
         "=============================================================================================================\n");
    exit(0);
	
}

int main(int argc, char *argv[])
{ 
	int floor[number_of_floors];
	int i;
    for(i=0;i<number_of_floors;i++){
		floor[i]=0;}
	int num_set_hostel=0 ;
    int current_floor=0;
    int current_person_queue=0;
    struct turn *p;
    struct settled students_list[150];
    struct turn student_list[150];
    char choice;
    while(1){
	 choice = menu_select();
	 switch (choice){
	 case 1 :
		 if(num_set_hostel < max_num_host){
		 num_set_hostel = choice_of_floor( num_set_hostel);
		 floor[current_floor] = moving_hostel( &floor[number_of_floors],  num_set_hostel, current_floor,students_list);break;}
		 else{add_to_queue(&p,student_list, current_person_queue);}
	 case 2:
		 num_set_hostel = remove_from_the_living(&floor[number_of_floors], num_set_hostel,students_list,&p); 
         removed_from_the_queue(&p);break;
     case 3: 
		 list_of_living(students_list,num_set_hostel);break;
	 case 4:
		 checkHelp();break;
     case 5:
		 exit(0);break;
     }
   }
}

#ifdef __cplusplus
}
#endif
