/*
 * Copyright (C) 2022 David Cantrell <dcantrell@burdell.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *     1. Redistributions of source code must retain the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer.
 *     2. Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *     3. Neither the name of the copyright holder nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Doom sndserver for A/UX
 * only developed and tested on A/UX 3.1.1
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <mac/sm.h>
#include <sys/types.h>
#include <sys/ssioctl.h>
#include <sys/sm_aux.h>

#include "auxhelp.h"
#include "soundsrv.h"

/* the raw audio device on A/UX */
#define SND_DEV "/dev/snd/raw"

/*
 * Doom sound samples are 11 kHz.  The Mac device defaults to 22 kHz.  To
 * set it to 11 kHz we make an ioctl() and give it a new value.  Divide
 * 11025/22050 and multiply by 65536.  In this case that's:
 *     (11025/22050) * 65536 = 32678 = 0x8000
 */
#define SAMPLERATE 0x8000

int audio_fd;

void I_InitMusic(void)
{
    return;
}

void I_InitSound(int samplerate, int samplesize)
{
    struct rawSndCtl rsi;
    extern int errno;

    audio_fd = open(SND_DEV, O_WRONLY);

    if (audio_fd < 0) {
        fprintf(stderr, "Could not open %s\n", SND_DEV);
        return;
    }

    rsi.sampleRate = SAMPLERATE;
    rsi.flags = 0;

    if (ioctl(audio_fd, SND_RAW_CTL, &rsi) < 0) {
        fprintf(stderr, "ioctl(%s, SND_CTL_RAW, arg) failed\n", SND_DEV);
        fprintf(stderr, "errno=%d\n", errno);
        exit(-1);
    }

    return;
}

void I_SubmitOutputBuffer(void *samples, int samplecount)
{
    write(audio_fd, samples, samplecount * 4);
    return;
}

void I_ShutdownSound(void)
{
    close(audio_fd);
    return;
}

void I_ShutdownMusic(void)
{
    return;
}
