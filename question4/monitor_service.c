// monitor_service.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t running = 1;

// Signal Handlers
void handle_sigint(int sig) {
    (void)sig;
    printf("\nMonitor Service shutting down safely.\n");
    running = 0;
}

void handle_sigusr1(int sig) {
    (void)sig;
    printf("\nSystem status requested by administrator.\n");
}

void handle_sigterm(int sig) {
    (void)sig;
    printf("\nEmergency shutdown signal received.\n");
    exit(0);
}

int main() {
    // Register signal handlers
    signal(SIGINT, handle_sigint);   // Ctrl+C
    signal(SIGUSR1, handle_sigusr1); // User-defined
    signal(SIGTERM, handle_sigterm); // Termination

    printf("[Monitor Service] Starting...\n");

    while (running) {
        printf("[Monitor Service] System running normally...\n");
        sleep(5); // Wait 5 seconds
    }

    printf("[Monitor Service] Exiting program.\n");
    return 0;
}