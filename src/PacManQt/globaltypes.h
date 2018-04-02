#ifndef GLOBALTYPES_H
#define GLOBALTYPES_H

typedef enum widgetType_
{
        GAME_OPTION_WIDGET = 0
    ,   GAME_WIDGET
    ,   SERVER_WIDGET
    ,   CLIENT_WIDGET
}widgetType;

typedef enum directionType_
{
        DIRECTION_LEFT = 0
    ,   DIRECTION_RIGHT
    ,   DIRECTION_UP
    ,   DIRECTION_DOWN
    ,   DONT_MOVE
}directionType;

typedef enum connectionRoleType_
{
        SERVER_ROLE = 0
    ,   CLIENT_ROLE
}connectionRoleType;


#define TCP_CMD_START_GAME  "START_GAME"

#endif // GLOBALTYPES_H
