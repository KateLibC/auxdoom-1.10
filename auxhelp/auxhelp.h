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

#include <limits.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>

#ifndef __AUXHELP_H
#define __AUXHELP_H

/* Various missing function prototypes from A/UX headers. */
int gettimeofday(struct timeval *tp, struct timezone *tzp);
unsigned usleep(unsigned useconds);
int bzero(char *b, int length);
int select(int nfds, int *readfds, int *writefds, int *execptfds, struct timeval *timeout);
char *shmat(int shmid, char *shmaddr, int shmflg);
int shmdt(char *shmaddr);
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
int shmget(key_t key, int size, int shmflg);
int ioctl(int fildes, int request, void *arg);
int socket(int af, int type, int protocol);
int bind(int s, struct sockaddr *name, int namelen);
int sendto(int s, char *msg, int len, int flags, struct sockaddr *to, int tolen);
int recvfrom(int s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
int gethostname(char *name, int namelen);
int strcasecmp(char *s1, char *s2);
int setitimer(int which, struct itimerval *value, struct itimerval *ovalue);
void *alloca(size_t size);

/* strncasecmp.c */
int strncasecmp(char *s1, char *s2, size_t n);

#endif /* __AUXHELP_H */
