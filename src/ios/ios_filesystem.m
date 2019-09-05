#include <Foundation/Foundation.h>

#include <sys/stat.h>
#include <SDL_error.h>
#include <SDL_stdinc.h>

#include "ios/ios_filesystem.h"

char *
Wesnoth_GetDocumentsPath(const char *org, const char *app)
{ @autoreleasepool
{
    char *retval = NULL;

    NSURL *url = [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];

    const char *base = [url fileSystemRepresentation];
    if (base) {
        const size_t len = SDL_strlen(base) + SDL_strlen(org) + SDL_strlen(app) + 4;
        retval = (char *) SDL_malloc(len);
        if (retval == NULL) {
            SDL_OutOfMemory();
        } else {
            char *ptr;
            SDL_snprintf(retval, len, "%s/%s/%s/", base, org, app);
            for (ptr = retval+1; *ptr; ptr++) {
                if (*ptr == '/') {
                    *ptr = '\0';
                    mkdir(retval, 0700);
                    *ptr = '/';
                }
            }
            mkdir(retval, 0700);
        }
    }

    return retval;
}}
