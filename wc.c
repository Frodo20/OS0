#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void wc(FILE *ofile, FILE *infile, char *inname) {
  int characters, lines, words, state;
  char c;
  state = characters = lines = words = 0;
  if(inname == NULL){
  while((c = getchar()) != '0') {
        characters++;
        if(c == '\n') {
            lines++;
            state = 0;
            continue;
        } else if(c == ' ') {
            state = 0;
            continue;
        } else if(c == '\t') {
            state = 0;
            continue;
        } else {
            if(state == 0) {
                state = 1;
                words++;
            }
            continue;
        }
    }
}

  else if(inname != NULL){

	fp=fopen(inname,"r");
	
    while((c=fgetc(fp)) != '0') {
        characters++;
        if(c == '\n') {
            lines++;
            state = 0;
            continue;
        } else if(c == ' ') {
            state = 0;
            continue;
        } else if(c == '\t') {
            state = 0;
            continue;
        } else {
            if(state == 0) {
                state = 1;
                words++;
            }
            continue;
        }
    }
	fclose(fp);

    if (ofile != NULL){
    fp=fopen(ofile,"w+");
	fprintf(fp, "%d characters. %d words. %d lines.\n", characters, words, lines);
	fclose(fp);
    }
}

    printf("%d characters. %d words. %d lines.\n", characters, words, lines);

	return (0);

}

int main (int argc, char *argv[]) {

  char* out_file_name = NULL;
	char* inname = NULL;
	if(argc == 1) wc(NULL,NULL,NULL);
	else if(argc == 2){
		inname = argv[1];
		FILE *infile = fopen(inname,"r");
		if(!infile){
			perror("Input file opening failed");
			exit(1);
		}
		wc(NULL,infile,inname);
	}
	else if(argc == 3){
		inname = argv[1];
		FILE *infile = fopen(inname,"r");
		if(!infile){
			perror("Input file opening failed");
			exit(1);
		}
		FILE *out_file = fopen(argv[2],"w");
		if(!out_file){
			perror("Output file opening failed");
			exit(1);
		}
		wc(out_file,infile,inname);
	}
	else{
		printf("arguments error\n");
		exit(1);
	}
	return 0;

}
