#include "qes.h" 

int evaluate(FILE *questionPaper,FILE *answerSheet)
{
	struct question_paper questions[MAX_SIZE];
    int count = 0;
    int total_marks;
    int scored_marks = 0, invalid_ans = 0;
    int j = 0;
    int found;
    char *name[MAX_SIZE];
    int ansQ_id[MAX_SIZE];
    int ansOption_choosen[MAX_SIZE];
    int i = 0;
    char buff[2024];
    char *token;

    for(; count < sizeof(questions)/sizeof(questions[0]); ++count) 
    {
         found = fscanf(questionPaper, "%d,%d,%d", &questions[count].question_id, &questions[count].num_of_option, &questions[count].correct_ans);
        if (found != 3) break;
    }

    fclose(questionPaper);
    total_marks = count;

    while(fgets(buff, 2024, answerSheet))
    {
        i = 0;
        token = strtok(buff,",");
        name[i] = token;
          // printf( "name: %s\n", name[i]);
        
        while( token != NULL ) {
            token = trimwhitespace(token);  
            token = strtok(NULL, ",<>");
            if(token != NULL) {
                ansQ_id[i] = atoi(token);
                // printf( "question_id: %d\n", ansQ_id[i]);
            }
            token = strtok(NULL, ",<>");
            if(token != NULL){
                ansOption_choosen[i] = atoi(token);
                // printf( "option_chosen: %d\n", ansOption_choosen[i]);
            }
            i++;
        }
        scored_marks = 0, invalid_ans = 0;

        for(j = 0; j < count; j++) {
            if(questions[j].question_id == ansQ_id[j]) {
                if(questions[j].correct_ans == ansOption_choosen[j])
                {
                    scored_marks += 1;
                }
                if(ansOption_choosen[j] > questions[j].num_of_option)
                {
                    invalid_ans += 1;
                }
            }
        }
        output_csv(name[0],total_marks,scored_marks,invalid_ans);
    }
    fclose(answerSheet);
    printf("total_marks %d\n", total_marks);
    return 0;
}
