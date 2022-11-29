#include "qes.h"

int main(int argc, char *argv[]){
	if(argc == 3){
		FILE *questionPaper = fopen(argv[1],USER_PARAMS_R);
		FILE *answerSheet = fopen(argv[2],USER_PARAMS_R);
		evaluate(questionPaper,answerSheet);
		printf("\n***New Record Successfully Updated in output.csv***\n");
	}
	if(argc < 3) {
		printf("\nInvalid Argument");
	}
	return 0;    
}
