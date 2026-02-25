#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void search_file(FILE * file, char * search_query) {
  /**
  Searches `file` for lines containing `search_query` and prints matching lines
  */
  char *line = malloc(100);
  if (!line) {
    exit(1);
  }
  int linesize = 100;
  while (fgets(line, linesize, file)) {
    
    size_t len = strlen(line);

    while (len > 0 && line[len - 1] != '\n'){
      char *temp = realloc(line, linesize * 2); 
      if (!temp){
        free(line);
        exit(2);
      }
      line = temp;
      linesize = linesize * 2;
      
      
      if (!fgets(line + len, linesize - len, file)){
        
        break;
      }
      len = strlen(line);
      
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
    exit(3);
  }

  search_file(stdin, argv[1]);
}