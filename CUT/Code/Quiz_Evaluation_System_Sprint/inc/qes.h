#ifndef QES_H
#define QES_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100
#define OUTFILE "../files/output1.csv"
#define USER_PARAMS_W "w+"
#define USER_PARAMS_A "a"
#define USER_PARAMS_R "r"

struct question_paper{
    int question_id;
    int num_of_option;
    int correct_ans;
};

struct answer_sheet{
    char *participant_name;
    int question_id;
    int option_chosen;
};

// struct question_paper_format {
// 	char name[50];
// 	int noOfquestionAttempt;
// 	struct question_paper_format *next;
// }

//Declaration of functions
char *trimwhitespace(char *);
int evaluate(FILE *, FILE *);
int output_csv(char*, int, int, int);

#endif
