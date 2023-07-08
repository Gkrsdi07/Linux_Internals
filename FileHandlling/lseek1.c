/* seek_io.c

   Demonstrate the use of lseek() and file I/O system calls.

   Usage: seek_io file {r<length>|R<length>|w<string>|s<offset>}...

   This program opens the file named on its command line, and then performs
   the file I/O operations specified by its remaining command-line arguments:

           r<length>    Read 'length' bytes from the file at current
                        file offset, displaying them as text.

           R<length>    Read 'length' bytes from the file at current
                        file offset, displaying them in hex.

           w<string>    Write 'string' at current file offset.

           s<offset>    Set the file offset to 'offset'.

   Example:

        seek_io myfile wxyz s1 r2
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>

#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXIT_SUCCESS and EXIT_FAILURE constants */

#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
#include <stdbool.h>    /* 'bool' type plus 'true' and 'false' constants */

#include <sys/file.h>           /* Has definition of FASYNC */

#include <stdarg.h>


#define GN_NONNEG       01      /* Value must be >= 0 */
#define GN_GT_0         02      /* Value must be > 0 */
                                /* By default, integers are decimal */
#define GN_ANY_BASE   0100      /* Can use any base - like strtol(3) */
#define GN_BASE_8     0200      /* Value is expressed in octal */
#define GN_BASE_16    0400      /* Value is expressed in hexadecimal */


#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

typedef enum { FALSE, TRUE } Boolean;



long getLong(const char *arg, int flags, const char *name);




/* Convert a numeric command-line argument ('arg') into a long integer,
   returned as the function result. 'flags' is a bit mask of flags controlling
   how the conversion is done and what diagnostic checks are performed on the
   numeric result; see get_num.h for details.

   'fname' is the name of our caller, and 'name' is the name associated with
   the command-line argument 'arg'. 'fname' and 'name' are used to print a
   diagnostic message in case an error is detected when processing 'arg'. */
static long getNum(const char *fname, const char *arg, int flags, const char *name)
{
    long res;
    char *endptr;
    int base;

    if (arg == NULL || *arg == '\0')
    {
        perror("null or empty string arg, name");
    }

    base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;

    errno = 0;
    res = strtol(arg, &endptr, base);
    if (errno != 0)
    {
        perror("fname, strtol() failed, arg, name");
    }

    if (*endptr != '\0')
    {
        perror("fname, nonnumeric characters, arg, name");
    }

    if ((flags & GN_NONNEG) && res < 0)
    {
        perror("fname, negative value not allowed, arg, name");
    }

    if ((flags & GN_GT_0) && res <= 0)
    {
        perror("fname, value must be > 0, arg, name");
    }

    return res;
}


/* Convert a numeric command-line argument string to a long integer. See the
   comments for getNum() for a description of the arguments to this function. */
long getLong(const char *arg, int flags, const char *name)
{
    return getNum("getLong", arg, flags, name);
}
/* Convert a numeric command-line argument string to an integer. See the
   comments for getNum() for a description of the arguments to this function. */







int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    
    int fd, ap, j;
    
    unsigned char *buf;
    
    ssize_t numRead, numWritten;

    if (argc < 3||strcmp(argv[1], "--help") == 0)
        perror("file {r<length>|R<length>|w<string>|s<offset>}...\n");

    fd = open(argv[1], O_RDWR | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH);                     /* rw-rw-rw- */

    if (fd == -1)
    {
        perror("opening error");
        exit(EXIT_FAILURE);
    }

    for (ap = 2; ap < argc; ap++) 
    {
        switch (argv[ap][0]) {
        case 'r':   /* Display bytes at current offset, as text */
        case 'R':   /* Display bytes at current offset, in hex */
            len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);

            buf = malloc(len);
            if (buf == NULL)
            {
                perror("error in malloc buf len\n");
                exit(EXIT_FAILURE);
            }

            numRead = read(fd, buf, len);
            if (numRead == -1)
            {
                perror("reading error");
                exit(EXIT_FAILURE);
            }

            if (numRead == 0) 
            {
                printf("%s: end-of-file\n", argv[ap]);
            } 
            else 
            {
                printf("%s: ", argv[ap]);
                for (j = 0; j < numRead; j++) 
                {
                    if (argv[ap][0] == 'r')
                    {
                        printf("%c", isprint(buf[j]) ?  buf[j] : '?');
                    }
                    else
                    {
                        printf("%02x ", buf[j]);
                    }
                }
                printf("\n");
            }

            free(buf);
            break;

        case 'w':   /* Write string at current offset */
            numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
            
            if (numWritten == -1)
            {
                perror("writing error");
                exit(EXIT_FAILURE);
            }
            /*FIXME: should use %zd here, and remove (long) cast */
            printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
            break;

        case 's':   /* Change file offset */
            offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
            if (lseek(fd, offset, SEEK_SET) == -1)
            {
                perror("lseek error");
                exit(EXIT_FAILURE);
            }
            printf("%s: seek succeeded\n", argv[ap]);
            break;

        default:
            perror("Argument must start with [rRws]: argv[ap]");
        }
    }

    if (close(fd) == -1)
    {
        perror("closing error");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
