#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

/* Parse the options */
int  optparse(size_t &bytesPerChunk, size_t &chunks, int &argc, char **(&argv))
{
  int c;                       /* Used for argument parsing */

  /* check the first argument, it should begin with '-' */
  if(--argc > 0 && (*++argv)[0] == '-') {
    switch(c = *++argv[0]) {
      /* User wants help */
      case 'h':
        --argc;
        usage();
        exit(0);
        break;
      case 'b':   /* user inputs size in bytes */
        /* Option b needs an argument with it. */
        if( argc <= 1 ) {
          usage();
          exit(0);
        }
        bytesPerChunk = atoi(*++argv);
        argc -= 2;
        if(bytesPerChunk > 1024 * 1024) {
          std::cerr << "Error: too many bytes, use kilobytes, megabytes or gigabytes\n";
        }
        chunks = 1;              /* How many times to loop */
        break;
      case 'k':   /* user inputs size in kilobytes */
        /* Option k needs an argument with it. */
        if( argc <= 1 ) {
          usage();
          exit(0);
        }
        chunks = atoi(*++argv);               /* How many times to loop */
        argc -= 2;
        bytesPerChunk = 1024;                /* Size of array */
        break;
      case 'm':   /* user inputs size in megabytes */
        /* Option m needs an argument with it. */
        if( argc <= 1 ) {
          usage();
          exit(0);
        }
        chunks = atoi(*++argv);               /* How many times to loop */
        argc -= 2;
        bytesPerChunk = 1024 * 1024;         /* Size of array */
        break;
      case 'g':   /* user inputs size in gigabytes */
        /* Option g needs an argument with it. */
        if( argc <= 1 ) {
          usage();
          exit(0);
        }
        chunks = atoi(*++argv) * 1024;        /* How many times to loop */
        argc -= 2;
        bytesPerChunk = 1024 * 1024;         /* Size of array */
        break;
      default:
        std::cout << "Error: Invalid option! " << c << "\n";
        usage();
        exit(1);
        break;
    }
  }
  else {
    std::cout << "Error: Missing option! " << "\n";
    usage();
    exit(1);
  }

  return 0;
}
