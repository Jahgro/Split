#ifndef MAIN_H
#define MAIN_H

void usage();
void fsplit(size_t bytesPerChunk, size_t chunks, char *filename);
int  optparse(size_t &bytesPerChunk, size_t &chunks, int &argc, char **(&argv));

#endif /* MAIN_H */
