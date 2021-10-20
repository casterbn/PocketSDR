/*---------------------------------------------------------------------------*/
/**
 *  Pocket SDR - SDR Common Functions.
 *
 *  Author:
 *  T.TAKASU
 *
 *  History:
 *  2021/10/03  0.1  new
 *
 */

#include "pocket.h"

/*---------------------------------------------------------------------------*/
/*
 *  Allocate memory. If no memory allocated, it exits the AP immediately with
 *  an error message.
 *  
 *  args:
 *      size     (I)  memory size (bytes)
 *
 *  return:
 *      memory pointer allocated.
 */
void *sdr_malloc(size_t size)
{
    void *p;
    
    if (!(p = calloc(size, 1))) {
        fprintf(stderr, "memory allocation error size=%lu\n", size);
        exit(-1);
    }
    return p;
}

/*---------------------------------------------------------------------------*/
/*
 *  Free memory allocated by sdr_malloc()
 *  
 *  args:
 *      p        (I)  memory pointer allocated.
 *
 *  return:
 *      none
 */
void sdr_free(void *p)
{
    free(p);
}

/*---------------------------------------------------------------------------*/
/*
 *  Get system tick (msec).
 *  
 *  args:
 *      none
 *
 *  return:
 *      system tick (ms)
 */
uint32_t sdr_get_tick(void)
{
    struct timeval tv = {0};
    
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000u + tv.tv_usec / 1000u;
}

/*---------------------------------------------------------------------------*/
/*
 *  Sleep for milli-seconds.
 *  
 *  args:
 *      msec     (I)  mill-seconds to sleep
 *
 *  return:
 *      none
 */
void sdr_sleep_msec(int msec)
{
    struct timespec ts = {0};
    
    if (msec <= 0) return;
    ts.tv_nsec = (long)(msec * 1000000);
    nanosleep(&ts, NULL);
}

