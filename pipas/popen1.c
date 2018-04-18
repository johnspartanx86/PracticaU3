/*****************************************************************************
Excerpt from "Linux Programmer’s Guide - Chapter 6"
(C)opyright 1994-1995, Scott Burkett
*****************************************************************************
MODULE: popen1.c
*****************************************************************************/
#include <stdio.h>
#define MAXSTRS 5

int main(void){
	int cntr;
	FILE *pipe_fp;
	char *strings[MAXSTRS] = {
		"echo",
		"bravo",
		"alpha",
		"charlie",
		"delta"
	};
	/* Create one way pipe line with call to popen() */
	if (( pipe_fp = popen("sort", "w")) == NULL){
		perror("popen");
		//exit(1);
		return 1;
	}
	/* Processing loop */
	for(cntr=0; cntr<MAXSTRS; cntr++) {
		fputs(strings[cntr], pipe_fp);
		fputc(1, pipe_fp);
	}
	/* Close the pipe */
	pclose(pipe_fp);
	return(0);
}