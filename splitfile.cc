#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "buffer.h"

/* Function that will do the work to split the file */
void fsplit(size_t bytesPerChunk, size_t chunks, char *filename)
{
  unsigned int j;                             /* For loop Variables */
  char filepart[100];                         /* Holds filename_part_xxx */

  FILE* fp;                                   /* Output File pointer */
  FILE* fg;                                   /* Input File pointer  */

  buffer<char> line_buffer(bytesPerChunk+1);  /* buffer that holds the input */
  size_t in_amount;                           /* Used for checking fread and fwrite returns */
  size_t out_amount;                          /* Used for checking fread and fwrite returns */
  unsigned int done_reading = 0;              /* flag to tell when all input has been written out */
  //char *filename = *++argv;                 /* filename passed as argument */

  /* Open input file, and check if it was successful */
  if((fg = fopen( filename, "rb"))) {
    /* Check if file is all done */
    for(j = 0; done_reading == 0; ++j) {
      /* Create output file name, and check if it was successful */
      if( sprintf(filepart, "%s_part_%.3d", filename, j) == 0) {
        std::cerr << "Error creating output file\n";
        exit(1);
      }
      /* Open output file */
      if((fp = fopen(filepart, "wb"))) {
        /* loop until all chunks for this file are read and printed to the output file */
        for(size_t k = 0; k != chunks && done_reading != 1; ++k) {
          in_amount = fread(line_buffer.get_line(), 1, bytesPerChunk, fg); /* Get the next line */
  
          /* Write the data to the file */
          if( (out_amount = fwrite(line_buffer.get_line(), 1, in_amount, fp)) != in_amount) {
            std::cerr << "Error writing output to file\n";
            exit(1);
          }
          /* Need to check for error */
          /* You are done reading in */
          if( out_amount != bytesPerChunk ) {
            done_reading = 1;
          }
        }
      }
      else {
        std::cerr << "Error: Can not open file\n";
        exit(1);
      }

    fclose(fp);
    }
  fclose(fg);
  }
  else {
    std::cerr << "Error: File named " << filename << " does not exist\n";
    exit(1);
  }
  return;
}
