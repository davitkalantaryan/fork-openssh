
#include <stddef.h>
#include <sys/queue.h>
#include <bsd/stdlib.h>
#include <bsd/unistd.h>
//#include <bsd/str>
#include <termios.h>
#include <lwres/netdb.h>

struct global_confirm {
    TAILQ_ENTRY(global_confirm) entry;
    int *cb;
    void *ctx;
    int ref_count;
};
TAILQ_HEAD(global_confirms, global_confirm);

static struct global_confirms global_confirms =
    TAILQ_HEAD_INITIALIZER(global_confirms);

winsize g_win;

int main()
{


    return 0;
}
