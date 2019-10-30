#include <Foundation/Foundation.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <SDL_error.h>

#include "ios/ios_filesystem.h"

char *
Wesnoth_GetICloudDocumentsPath()
{ @autoreleasepool
{
	NSURL *url = [[[NSFileManager defaultManager] URLForUbiquityContainerIdentifier:nil] URLByAppendingPathComponent:@"Documents"];

	const char *base = [url fileSystemRepresentation];
	if (base) {
		const char *retval = strdup(base);
		if (retval == NULL) {
			SDL_OutOfMemory();
		} 

		mkdir(retval, 0700);
		return retval;
	}

	return NULL;
}}
