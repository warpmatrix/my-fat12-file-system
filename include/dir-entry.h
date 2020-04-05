#if !defined(DIR_ENTRY_H)
#define DIR_ENTRY_H

#include "entry.h"

void parseEnts(const Entry *entries, size_t entCnt, unsigned char *block);
size_t parseEntBlock(const unsigned char *block, Entry *entries);

size_t getFreeEntIdx(unsigned char *block);
size_t getDirFreeEnt(size_t *blockIdx, unsigned short dirClus,
                     unsigned char *ramFDD144);

Entry getEntByName(const char *entname, unsigned short dirClus,
                   const unsigned char *ramFDD144);
Entry getEntByClus(unsigned short entClus, unsigned short dirClus,
                   const unsigned char *ramFDD144);

#endif  // DIR_ENTRY_H
