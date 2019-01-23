
#include <stddef.h>
#include <sys/queue.h>

struct global_confirm {
    TAILQ_ENTRY(global_confirm) entry;
    int *cb;
    void *ctx;
    int ref_count;
};
TAILQ_HEAD(global_confirms, global_confirm);

static struct global_confirms global_confirms =
    TAILQ_HEAD_INITIALIZER(global_confirms);

int main()
{


    return 0;
}
