#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int allow=3;
struct patient{
    char name[20];
    char address[15];
    int age;
    char sex;
    char disease[80];
    int specilist_room;
    char department[10];
};
struct patient arr[200];
int password=1911;
void menu();
void add();
void edit();
void search_patient();
void del();
void list();
int main(){
    int q;
    int password_temp;
    printf("\n\t~~~~~~~~~~~~~Welcome to Zagazig University  Hospital~~~~~~~~~~~~~");
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~Signin~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    fflush(stdin);
    printf("\n\t\tEnter Password :");
    scanf("%d",&password_temp);
    q= password_temp - password ;
    if(q==0){
        menu();
    }else{
        printf("\n\t\tWrong data input.");
        allow--;
        printf("You have: %d tries",allow);
        if(allow==0){
            exit(1);
        }else{
            main();
        }
    }
    return 0;
}
void menu(){
    int h;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t 1)ADD New Patient.");
    printf("\n\t\t 2)Edit Patient.");
    printf("\n\t\t 3)List Record.");
    printf("\n\t\t 4)Search for Patient.");
    printf("\n\t\t 4)Delete Patient.");
    printf("\n\t\t 5)Log out.");
    printf("\n\tEnter your choice:");
    scanf("%d",&h);
    if(h==1){
        add();
    }else if(h==2){
        edit();
    }else if(h==3){
        list();
    }else if(h==4){
        search_patient();
    }else if(h==5){
        del();
    }else if(h==6){
        main();
    }else{
        printf("\n\t\tWrong data input.");
        menu();
    }
}
void add(){
    static int i=0;
    int j;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~ADD~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t 1) O.P.D service.");
    printf("\n\t 2) Emergency service.");
    printf("\n\t Option Number : ");
    fflush(stdin);
    scanf("%d",&j);
    if(j==1){
        strcpy(arr[i].department,"O.P.D");
    }else if(j==2){
        strcpy(arr[i].department,"Emergency");
    }
    fflush(stdin);
    printf("\n\t Patient Name:");
    fflush(stdin);
    gets(arr[i].name);
    fflush(stdin);
    printf("\n\t Patient Address:");
    gets(arr[i].address);
    printf("\n\t Patient Age:");
    scanf("%d",&arr[i].age);
    fflush(stdin);
    printf("\n\t Patient Sex (M||F):");
    scanf("%c",&arr[i].sex);
    fflush(stdin);
    printf("\n\t Patient Disease description:");
    gets(arr[i].disease);
    printf("\n\t Patient Specialist Room Number :");
    scanf("%d",&arr[i].specilist_room);
    i++;
    menu();
}
void edit(){
    char name[20];
    int k,a;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~Edit~~~~~~~~~~~~~~~~~~~~~~~~~~");
    fflush(stdin);
    printf("\n\tPatient Name:");
    gets(name);
    for(k=0;k<200;k++){
        if(strcmp(name,arr[k].name)==0){
            printf("\n\t 1) Edit Name.");
            printf("\n\t 2) Edit Address.");
            printf("\n\t 3) Edit Age.");
            printf("\n\t 4) Edit Sex.");
            printf("\n\t 5) Edit Disease Description.");
            printf("\n\t 6) Edit Specialist Room.");
            printf("\n\t 7) Edit Department.");
            printf("\n\t Option:");
            scanf("%d",&a);
            if(a==1){
                fflush(stdin);
                printf("\n\tEnter New Name:");
                gets(arr[k].name);
                menu();
            }else if(a==2){
                fflush(stdin);
                printf("\n\tEnter New Address:");
                gets(arr[k].address);
                menu();
            }else if(a==3){
                printf("\n\tEnter New Age:");
                scanf("%d",&arr[k].age);
                menu();
            }else if(a==4){
                fflush(stdin);
                printf("\n\tEnter New Sex:");
                scanf("%c",&arr[k].sex);
                menu();
            }else if(a==5){
                fflush(stdin);
                printf("\n\tEnter New Disease Description :");
                gets(arr[k].disease);
                menu();
            }else if(a==6){
                printf("\n\tEnter New Specialist Room:");
                scanf("%d",&arr[k].specilist_room);
                menu();
            }else if(a==7){
                fflush(stdin);
                printf("\n\tEnter New Department :");
                gets(arr[k].department);
                menu();
            }
        }
    }
    printf("\n\tWrong Name.");
    edit();
}
void search_patient(){
    char name[20];
    int k;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~Search~~~~~~~~~~~~~~~~~~~~~~~~~~");
    fflush(stdin);
    printf("\n\tPatient Name:");
    gets(name);
    for(k=0;k<200;k++){
        if(strcmp(name,arr[k].name)==0){
            printf("\n\t 1)  Name: %s",arr[k].name);
            printf("\n\t 2)  Address: %s",arr[k].address);
            printf("\n\t 3)  Age: %d",arr[k].age);
            printf("\n\t 4)  Sex: %c",arr[k].sex);
            printf("\n\t 5)  Disease Description: %s",arr[k].disease);
            printf("\n\t 6)  Specialist Room: %d",arr[k].specilist_room);
            printf("\n\t 7)  Department :%s",arr[k].department);
            menu();
        }
    }
    printf("\n\tWrong Name.");
    search_patient();
}
void del(){
    char name[20];
    int k;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~Delete~~~~~~~~~~~~~~~~~~~~~~~~~~");
    fflush(stdin);
    printf("\n\tPatient Name:");
    gets(name);
    for(k=0;k<200;k++){
        if(strcmp(name,arr[k].name)==0){
            strcpy(arr[k].name,"");
            strcpy(arr[k].address,"");
            strcpy(arr[k].disease,"");
            strcpy(arr[k].department,"");
            arr[k].age=0;
            arr[k].sex=0;
            arr[k].specilist_room=0;
            printf("\n\tData Deleted Successfully.");
            menu();
        }
    }
    printf("\n\tWrong Name.");
    search_patient();
}
void list(){
    int a,i;
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~List~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t 1)O.P.D");
    printf("\n\t 2)Emergency");
    printf("\n\t Option:");
    scanf("%d",&a);
    if(a==1){
        printf("\n\t Name          Address      Age      Sex      Specialist Room       Department        Disease ");
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for(i=0;i<200;i++){
            if(strcmp(arr[i].department,"O.P.D")==0){
                if(arr[i].age!=0){
                    printf("\n\t %-10s    %-10s    %-2d        %c             %-3d             %-s          %-s",arr[i].name,arr[i].address,arr[i].age,arr[i].sex,arr[i].specilist_room,arr[i].department,arr[i].disease);
                }
            }
        }
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        menu();
    }else if(a==2){
        printf("\n\t Name          Address      Age      Sex      Specialist Room       Department        Disease ");
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for(i=0;i<200;i++){
            if(strcmp(arr[i].department,"Emergency")==0){
                if(arr[i].age!=0){
                    printf("\n\t %-10s    %-10s    %-2d        %c             %-3d             %-s          %-s",arr[i].name,arr[i].address,arr[i].age,arr[i].sex,arr[i].specilist_room,arr[i].department,arr[i].disease);
                }
            }
        }
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        menu();
    }
}
