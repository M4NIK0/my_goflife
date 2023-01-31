/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** objects gestion
*/

#ifndef OBJECTS_GEST_H_
    #define OBJECTS_GEST_H_

world *gen_world(void);
void world_kill(world *world);
char get_orientation(int *pos, int *pos_to);
int add_boat_n_nb(int *pos, int size, char orientation, world *world);
int place_boats(world *world);

#endif /* !OBJECTS_GEST_H_ */
