#include <stdio.h>


typedef struct {
    int id;
    char s_name[100];
    char a_name[100];
    char m_name[100];
    double cgpa;
} stud_a_info;
    



int main(){
    FILE*  infp = fopen("Section07_Data.txt", "r");
    FILE* opfp =fopen("StudentsOnProbation.txt", "w") ;








    return 0;
}