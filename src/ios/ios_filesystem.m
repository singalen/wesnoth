#include <Foundation/Foundation.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <SDL_error.h>

#include "ios/ios_filesystem.h"

char *
Wesnoth_GetICloudDocumentsPath()
{ @autoreleasepool
{
    NSURL *containerUrl = [[NSFileManager defaultManager] URLForUbiquityContainerIdentifier:nil];
    NSURL *documents = [containerUrl URLByAppendingPathComponent:@"Documents" isDirectory: true];

	const char *documents_path = [documents fileSystemRepresentation];

	struct stat sb;
	if (stat(documents_path, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
		mkdir(documents_path, 0700);
	}

	@try {
        NSError *error = nil;
        NSString *downloadingStatus = nil;
		if ([documents getResourceValue:&downloadingStatus forKey:NSURLUbiquitousItemDownloadingStatusKey error:&error] == YES) {
			if ([downloadingStatus isEqualToString:NSURLUbiquitousItemDownloadingStatusDownloaded] == NO) {
	            [[NSFileManager defaultManager] startDownloadingUbiquitousItemAtURL:documents error:&error];
			} else {
				NSLog(@"downloadingStatus = %s", downloadingStatus );
			}
		} else {
			NSLog(@"Error reading %@ for %s", NSURLUbiquitousItemDownloadingStatusKey, documents_path);
		}
	}
	@catch (NSException * e) {
        NSLog(@"Exception in GetICloudDocumentsPath: %@: %@", e, containerUrl);
	}

	if (documents_path) {
		const char *retval = strdup(documents_path);
		if (retval == NULL) {
			SDL_OutOfMemory();
		} 

		return retval;
	}

	return NULL;
}}
