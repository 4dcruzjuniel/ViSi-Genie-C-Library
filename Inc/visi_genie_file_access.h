/*
 * visi_genie_file_access.h
 *
 *  Created on: Sep 13, 2019
 *      Author: cruzj
 */


#ifndef __VISI_GENIE_FILE_ACCESS_H__
#define __VISI_GENIE_FILE_ACCESS_H__

//#define GENIE_BETA

#ifdef GENIE_BETA
#include "visi_genie_beta.h"
#else
#include "visi_genie.h"
#endif

#define GENIEM_FILE_CMD_BUF_SIZE	255

typedef enum {
	GENIEM_FILE_READ,
	GENIEM_FILE_WRITE,
	GENIEM_FILE_APPEND,
	GENIEM_FILE_ERASE,
	GENIEM_FILE_DIR,
	GENIEM_FILE_SCREEN_CAPTURE,
	GENIEM_FILE_SIZE,
	GENIEM_FILE_WRITE_ROW
} GenieFileCommand;

uint8_t magicFileBuffer[GENIEM_FILE_CMD_BUF_SIZE];
uint8_t magicFileIndex;
bool magicFileBusy;

void genieFileBegin(uint8_t index);
void genieFileAccessIsReady();
void genieFileDir(char * filename);
void genieFileRead(char * filename);
void genieFileWriteStr(char * filename, char * str);
void genieFileWriteStrToRow(uint8_t row, char * str);
void genieFileWriteBytes(char * filename, uint8_t * data, uint8_t count);
void genieFileAppendStr(char * filename, char * str);
void genieFileAppendBytes(char * filename, uint8_t * data, uint8_t count);
void genieFileErase(char * filename);
void genieFileSize(char * filename);

#endif // __VISI_GENIE_FILE_ACCESS_H__
