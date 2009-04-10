#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

enum messageType    {   RECEIVE,
                        SENDMSG
                    };

enum protocol       {   REQUESTCONTACTS = 1,
                        SENDCONTACTS,
                        HELLO,
                        GOODBYE,
                        CHANNELMESSAGE
                    };

enum guiEventType   {   DISPLAYMESSAGE,
                        CONNECT,
                        DISCONNECT
                    };

#endif // ENUM_H_INCLUDED
