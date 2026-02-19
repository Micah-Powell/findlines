#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void search_file(FILE * file, char * search_query) {
  /**
  Searches `file` for lines containing `search_query` and prints matching lines
  */
  char *line = malloc(100);

  while (fgets(line, sizeof(line), file)) {
    while (strchr(line, "\n") == NULL){
      char *line = malloc(sizeof(*line * 2)); 
      fgets(line, sizeof(line), file);
    }
    if (strstr(line, search_query)) {
      printf("%s", line);
    }
  }

  free(line);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    printf("Exactly one search parameter required\n");
    exit(1);
  }

  search_file(stdin, argv[1]);
}
