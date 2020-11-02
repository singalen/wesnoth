#include <Foundation/Foundation.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <SDL_error.h>

#include "ios/ios_filesystem.h"

#include <dirent.h>
#include <stdio.h>

static void ICloud_StartSync(NSURL *documents)
{
    @try {
        // TODO: Handle errors
        NSError *error = nil;
        NSString *downloadingStatus = nil;

        if ([documents getResourceValue:&downloadingStatus forKey:NSURLUbiquitousItemDownloadingStatusKey error:&error] == YES) {
            if ([downloadingStatus isEqualToString:NSURLUbiquitousItemDownloadingStatusCurrent] == NO) {
                [[NSFileManager defaultManager] startDownloadingUbiquitousItemAtURL:documents error:&error];
            }
            NSLog(@"downloadingStatus[%s] = %@", [documents fileSystemRepresentation], downloadingStatus);
//            [documents getResourceValue:&downloadingStatus forKey:NSURLUbiquitousItemDownloadingStatusKey error:&error];
//            NSLog(@"downloadingStatus 2 = %@", downloadingStatus);

            const char *documents_path = [documents fileSystemRepresentation];
            struct dirent *dir;
            DIR *d = opendir(documents_path);
            if (d) {
              while ((dir = readdir(d)) != NULL) {
                printf("in dir: %s\n", dir->d_name);
              }
              closedir(d);
            }
            
        } else {
            NSLog(@"Error reading %@ for %@", NSURLUbiquitousItemDownloadingStatusKey, [documents absoluteString]);
        }
    }
    @catch (NSException * e) {
        NSLog(@"Exception in GetICloudDocumentsPath: %@: %@", e, documents);
    }
}

void Wesnoth_ICloud_StartSync()
{ @autoreleasepool
{
    NSURL *containerUrl = [[NSFileManager defaultManager] URLForUbiquityContainerIdentifier:nil];
    NSURL *documents = [containerUrl URLByAppendingPathComponent:@"Documents" isDirectory: true];
    NSURL *saves = [documents URLByAppendingPathComponent:@"saves" isDirectory: true];

    ICloud_StartSync(documents);
    ICloud_StartSync(saves);
}
}

char *
Wesnoth_ICloud_GetDocumentsPath()
{ @autoreleasepool
{
	NSURL *containerUrl = [[NSFileManager defaultManager] URLForUbiquityContainerIdentifier:nil];
	NSURL *documents = [containerUrl URLByAppendingPathComponent:@"Documents" isDirectory: true];
	const char *documents_path = [documents fileSystemRepresentation];
	
	NSLog(@"documents_path = %@", documents);
	
	struct stat sb;
	if (stat(documents_path, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
		mkdir(documents_path, 0700);
	}

//	Wesnoth_StartICloudSync();

	if (documents_path) {
		char *retval = strdup(documents_path);
		if (retval == NULL) {
			SDL_OutOfMemory();
		}
		return retval;
	}

	return NULL;
}
}

bool Wesnoth_ICloud_Delete(const char *file_name)
{ @autoreleasepool
{
	NSURL *containerUrl = [[NSFileManager defaultManager] URLForUbiquityContainerIdentifier: nil];
	if (file_name == NULL || containerUrl == nil) {
		return false;
	}
	
	NSURL *documents = [containerUrl URLByAppendingPathComponent:@"Documents/saves" isDirectory: true];
	NSURL *theFile = [documents URLByAppendingPathComponent:[NSString stringWithUTF8String: file_name] isDirectory: false];
	
	NSError *error = nil;
	
	NSString * zzz = [theFile path];
	bool exists = [[NSFileManager defaultManager] fileExistsAtPath: zzz];
	if (!exists) {
		return false;
	}
	
	return [[NSFileManager defaultManager] removeItemAtURL: theFile error: &error];
}
}
