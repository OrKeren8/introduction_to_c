// Or Keren
// 315155531

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 11
#define MAX_FULL_NAME_LEN ((MAX_NAME_LEN*2))
#define MAX_COURSES 2
#define NUM_OF_GROUPS 3
#define NUM_OF_STUDENTS_IN_GROUP 6
#define GROUPS_NAMES "ABC"

typedef struct CourseInfo{
    int courseNum;
    int grade;
} COURSE_INFO;

typedef struct Student{
    char name[MAX_NAME_LEN];
    int identity;
    int nofCourses; //number of courses taken in semesterA
    COURSE_INFO course_info[MAX_COURSES];
} STUDENT;

void welcomeCall();
void getStudentsData(STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP]);
void getStudentData(STUDENT *student, char semesterName);
void getStudentName(char fullName[]);
int getIDNumber();
int getNumberOfCourses(char semesterName);



void main()
{
    STUDENT groups[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP] = {0};

    welcomeCall();
    getStudentsData(groups);
}

void welcomeCall()
{
    /*welcome text

    Args: none
    return: none
    */
    printf(" ********************\n"
        "* Welcome Students *\n"
        "********************\n\n");
}

void getStudentsData(STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP])
{
    for (int group=0; group<NUM_OF_GROUPS; group++){
        printf("Enter students data for GROUP %c\n", GROUPS_NAMES[group]);
        printf("________________________________\n\n");
        for(int student=0; student<NUM_OF_STUDENTS_IN_GROUP; student++){
            getStudentData(&groups[group][student], GROUPS_NAMES[group]);
        }
    }
}

// int getSemesterCourses(char semester, COURSE_INFO courseArr[])
// {
//     /*get courses data from the user of a specific semester

//     Args:
//         char semester: the name of the semester
//         COURSE_INFO courseArr[]: array of course info structure
//     return: int numOfCourses: the number of courses a student took in a semester
//     */
//     int numOfCourses;
//     printf("Please enter number of courses in semester %c: \n", semester);
//     scanf("%d", &numOfCourses);
//     for (int i = 0; i < numOfCourses; i++)
//     {
//         printf("Enter course number and grade: \n");
//         scanf("%d %d", &courseArr[i].courseNum, &courseArr[i].grade);
//     }
//     return numOfCourses;
// }

void getStudentData(STUDENT *student, char semesterName)
{
    getStudentName(student->name);
    student->identity = getIDNumber();
    // student->nofCourses = getNumberOfCourses(semesterName);
}

void getStudentName(char fullName[])
{
    /*get a full name from the user

    get the first name and last name separated by " "
    and create a string of full name
    Args: 
        string fullName: full name to fill in
    return: None
    */
    char firstName[MAX_NAME_LEN] = "";
    char lastName[MAX_NAME_LEN] = "";

    printf("Enter student first name and last name (seperated by spaces): ");
    scanf("%s %s", firstName, lastName);
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
}

int getIDNumber()
{
    /*get user ID number
    get student id number
    
    Args: none
    return: 
        int id: the id number of a student
    */
    int id;
    printf("Enter student ID: \n");
    scanf("%d", &id);
    return id;
}