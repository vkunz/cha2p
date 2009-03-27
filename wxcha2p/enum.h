#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

enum messageType    {   RECEIVE,
                        SENDMSG
                    };

enum protocol       {   REQUESTCONTACTS = 1,
                        SENDCONTACTS,
                        CHANNELMESSAGE
                    };

enum guiEventType   {   DISPLAYMESSAGE
                    };

#endif // ENUM_H_INCLUDED
