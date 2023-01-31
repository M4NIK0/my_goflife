/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** signal gestion
*/

#ifndef SIGNAL_GEST_H
    #define SIGNAL_GEST_H

void sig_handler(int signo, siginfo_t *info, void *context);
void start_sig_monitor(void);
void send_int(int content);
int get_int(void);

#endif /* !SIGNAL_GEST_H */
