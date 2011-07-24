#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main(int argc, char *argv[])
{
  size_t bytesPerChunk;          /* How many bytes each file should be */
  size_t chunks;                 /* Number of chunks per file */

  /* optparse takes bytesPerChunk, chunks, argc, argv
     updates all arguments to the proper values, ready to be used */
  optparse(bytesPerChunk, chunks, argc, argv);

  /* Possibly move this check into a function. */
  /* this might not be a good idea since       */
  /* future functionality might need this      */
  /* check as well                             */
  /* No filename was found */
  if( argc <= 0 ) {
    std::cout << "Error: Missing filename! " << "\n";
    usage();
    exit(1);
  }

  /* split the file (bytes per chunk, number of chunks per file, filename) */
  fsplit(bytesPerChunk, chunks, *++argv);

  return 0;
}
