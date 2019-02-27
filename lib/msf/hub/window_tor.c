/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** window
*/

#include "msf/msf.h"

sfRenderWindow *window_new(char *title, sfVector2i size, sfUint32 style)
{
    sfVideoMode mode = {size.x, size.y, 32};
    sfRenderWindow *window = NULL;
    sfImage *img = sfImage_createFromFile("assets/img/icon.png");
    const sfUint8 *icon = sfImage_getPixelsPtr(img);

    window = sfRenderWindow_create(mode, title, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 144);
    sfRenderWindow_setIcon(window, 256, 256, icon);
    sfImage_destroy(img);
    return (window);
}

void window_destroy(sfRenderWindow *window)
{
    if (window)
        sfRenderWindow_destroy(window);
}