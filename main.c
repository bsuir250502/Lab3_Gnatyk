#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#define input_buf_size 80
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
#define num_max_host 3
#define maxber_of_floors 2
#define max_max_floor 3
#define max 20

    struct settled {
        char name[max];
        char floor[max_max_floor];
    };
    struct queue{
        char name[max];
        struct queue*next;
    };

    struct departure {
        char name[max];
    };

    char*gets_s(char *s, size_t buf_size)
    {
        char *result;
        result = fgets(s, buf_size, stdin);
        result[strlen(s) - 1] = '\0';
        return result;
    }

    int hostel_is_empty(int num_set_hostel)
    {
        if(num_set_hostel == 0) {
            return 1;
        }
        return 0;
    }

    int removed_from_the_queue(struct queue **tail)
    {
        struct queue*pr;
        if(!*tail) {
            return 0;
        }
        if(!((*tail)-> next)) {
            free(*tail);
            tail = NULL;
            return 0;
        }
        pr = *tail;
        while(pr->next->next)
            pr= pr->next;
        free(pr->next);
        pr->next = NULL;
        return 0;
    }

    int name_check(int* floor, int num_set_hostel, struct departure* stud_list, int kol_departure, struct settled* students_list)
    {
        int i;
        if(hostel_is_empty(num_set_hostel) == 1)
            return 2;
        for(i = 1; i < num_set_hostel + 1; i++) {
            if(strcmp(students_list[i].name,stud_list[kol_departure].name) == 0)
                return 0;
        }
        return 1;
    }

    int remove_from_the_list(int num_set_hostel,int* floor,struct settled* students_list)
    {
        floor[maxber_of_floors] = floor[maxber_of_floors]-1;
        students_list[num_set_hostel].name,0;
        num_set_hostel --;
        return num_set_hostel;

    }

    int result_of_eviction(int* floor, int num_set_hostel, struct settled* students_list, struct queue **tail, struct departure* stud_list, int kol_departure)
    {
        int name_size = SIZE(stud_list[kol_departure].name);
        if(name_check(floor, num_set_hostel, stud_list, kol_departure,students_list) == 2) {
            printf("Hostel is empty\n\n");
            return 0;
        }
        printf("Enter surname of the student ");
        gets_s(stud_list[kol_departure].name,name_size);
        if(name_check(floor, num_set_hostel, stud_list, kol_departure,students_list) == 1) {
            printf(" Student with that name does not live here\n");
            return 0;
        }
        if(name_check(floor, num_set_hostel, stud_list, kol_departure,students_list) == 0) {
            num_set_hostel = remove_from_the_list(num_set_hostel,floor, students_list);
            puts(" The man was successfully evicted by out of the hostel\n");
        }
        return num_set_hostel;
    }

    void list_of_living(struct settled* students_list, int num_set_hostel)

    {
        int i;
        if(hostel_is_empty(num_set_hostel) == 1) {
            printf("Hostel is empty\n\n");
            return ;
        }
        else{
            printf("List of living:\n ");
            for(i = 1; i < num_set_hostel + 1; i++) {
                printf("%s\n",students_list[i].name );
            }
        }
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
            printf("\nEnter the maxber of the desired item\n");
            gets_s(s, input_buf_size);
            c = atoi(s);
        }
        while (c < 0 || c > 5);
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

    void add_to_queue(struct queue**tail,struct queue* student_list,int current_person_queue)
    {
        struct queue * n;
        int name_size= SIZE(n->name);
        if(!(n = (queue*)calloc(1,sizeof(queue)))) {
            puts("There is no free memory");return;
        }
        puts("I'm sorry to the hostel not available, we will put you in a place to settle\n");
        puts("Enter surname of student\n");
        gets_s(n->name,name_size);
        if(!*tail) {
            *tail = n ;
        }
        else{
            n->next = *tail;
            *tail =n;
        }
    }

    int current_flor(int current_floor)
    {
        return current_floor;
    }

    int check_maxbers_hostel(int current_floor,int* floor)
    {
        if(floor[current_floor] < max_max_floor)
            return 0;
    }


    int moving_hostel(int* floor, int num_set_hostel,int current_floor,struct settled* students_list)
    {
        int name_size = SIZE(students_list[num_set_hostel].name);
        if(check_maxbers_hostel(current_floor,floor) == 0) {
            floor[current_floor] = floor[current_floor] + 1;
            printf("Enter surname of students ");
            gets_s(students_list[num_set_hostel].name,name_size);
            students_list[num_set_hostel].floor,&current_floor;
        }
        current_floor ++;
        return current_floor ;
    }

    int choice_of_floor( int num_set_hostel)
    {
        num_set_hostel ++ ;
        return num_set_hostel;
    }

    void main()
    {
        int kol_departure = 0;
        int current_floor=0;
        int floor[maxber_of_floors] = {0,0};
        int num_set_hostel = 0 ;
        int current_person_queue = 0;
        struct queue *tail;
        tail=NULL;
        struct settled students_list[150];
        struct queue student_list[150];
        struct departure stud_list[150];
        char choice;
        while(1){
            choice = menu_select();
            switch (choice){
            case 1 :
                if(num_set_hostel < num_max_host) {
                    num_set_hostel = choice_of_floor( num_set_hostel);
                    current_floor = moving_hostel(floor, num_set_hostel, current_floor,students_list);
                    break;
                }
                else {
                    add_to_queue(&tail,student_list, current_person_queue);break;
                }
            case 2:
                if(num_set_hostel != 0)
                    kol_departure ++;
                num_set_hostel = result_of_eviction(floor, num_set_hostel, students_list, &tail, stud_list, kol_departure);
                if(num_set_hostel != 0) {
                    removed_from_the_queue(&tail);
                }break;
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

#ifdef __cplusplus
}
#endif
