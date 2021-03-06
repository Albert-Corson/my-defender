/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** evt
*/

#ifndef MSF_EVT_H_
#define MSF_EVT_H_

#include "msf/types.h"

/*
**  ENUMS
*/
enum msf_evt_scope_e {
    context,
    inputs
};

/*
**  STRUCTS
*/

/*
**  Game Event
**      scope       scope of the event (trigger condition)
**      evt         function to be triggered by the event
*/
struct msf_game_evt_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    evt_scope scope;
    void (*evt)(hub_t *hub, sfEvent evt);
};

/*
**  PROTOTYPES
*/
// EVT TOR
void *evt_new(void (*fn)(hub_t *, sfEvent), evt_scope scope);
void evt_ctor(void *evt, void (*fn)(hub_t *, sfEvent), evt_scope scope);
void evt_destroy(void *evt);

// EVT MET
void evt_trigger_scope(void *evts, evt_scope scope, hub_t *hub, sfEvent data);
void evt_trigger(void *evt, hub_t *hub, sfEvent data);

#endif /* !MSF_EVT_H_ */