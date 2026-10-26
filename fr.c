#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, char **argv) {
    struct statvfs s;
    if (statvfs(argc > 1 ? argv[1] : "/", &s)) { perror("statvfs"); return 1; }

    double free = (double)s.f_bavail * s.f_frsize;
    const char *u[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB"};
    int i = 0;
    while (free >= 1024 && i < 5) { free /= 1024; i++; }

    printf("%.1f%s\n", free, u[i]);
    return 0;
}   
