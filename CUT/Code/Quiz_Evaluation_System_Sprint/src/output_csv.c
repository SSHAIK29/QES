#include "qes.h"

int output_csv(char* name,int total_marks,int scored_marks,int invalid_ans){   
	FILE *output;

	if(fopen(OUTFILE, USER_PARAMS_R) == NULL)
	{
		output = fopen(OUTFILE, USER_PARAMS_W);
		fprintf(output, "Participant_name, Total_marks, scored_marks, invalid_answers, wrong_ans\n"); 
		fprintf(output, "%s, %d, %d, %d, %d\n", name, total_marks, scored_marks, invalid_ans, (total_marks-scored_marks));
    }
	output = fopen(OUTFILE, USER_PARAMS_A);
	fprintf(output, "%s, %d, %d, %d, %d\n", name, total_marks, scored_marks, invalid_ans, (total_marks-scored_marks));
	fclose(output);

	//printf("Total Questions: %d\nCorrect Answers Selected: %d\nInvalid Answers: %d\n",total_marks, scored_marks, invalid_ans);

	return 0;
}
