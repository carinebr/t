#include <iostream>
#include <curl/curl.h>
#include <pthread.h>
#include "httputils.h"
#include "excepterr.h"
#include "logger.h"

int get_random (int max)
{
    double val;

    val = (double) max * rand ();
    val = val / (RAND_MAX + 1.0);

    return ((int) val);
}
