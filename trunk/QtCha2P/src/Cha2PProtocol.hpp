#ifndef _QTCHA2P_CHA2PPROTOCOL_HPP_
#define _QTCHA2P_CHA2PPROTOCOL_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QString>

#include "AbstractProtocol.hpp"

namespace QtCha2P
{
	class Cha2PProtocol : public AbstractProtocol
	{
		private:
			// enumeration of all protocoll bits
			enum ProtocolBits
			{
				REQUESTCONTACTS = 1,			// flag to request all contacts of connection-entry
				SENDCONTACTS,					// flag to send all contacts to host
				HELLO,							// say hello to sign in to actual chat and announce himself
				GOODBYE,						// sign off from actual chat, this is the proper way to sign off
				CHANNELMESSAGE,					// flag to sign message as ChannelMessage sent to the whole channel
				PRIVATEMESSAGE,					// flag to sign message as PrivateMessage sent to one contact
			};

			// protocol consists of 3 parts
			// first part is an unsigned char with protocolbits as flags of what kind of message
			// second part is an unsigned char, this value stores information how long the message is
			// third part is the message consists of a string of ansi-bytes

			// unsigned char to store protocolbits
			unsigned char m_protocolBits;

			// unsigned char to store the message-length
			unsigned int m_messageLength;

			// QString to store the message
			QString m_Message;

			// stores the baseport this protocol is working on
			unsigned int m_basePort;

			// generates output of an given protocolrequst without message
			QByteArray generateOutput(ProtocolBits bits);

			// generates output of an given protocolrequst with given message
			QByteArray generateOutput(ProtocolBits bits, QString message);

		public:
			// ctor
			Cha2PProtocol();

			// dtor
			~Cha2PProtocol();

			// generates a requestContactList byte
			QByteArray generateRequestContacts(QString ip);

			// generates a replyContactList byte
			QByteArray generateSendContacts(QString contacts);

			// generates a hello byte
			QByteArray generateHello(QString nickname);

			// generates a goodbye byte
			QByteArray generateGoodBye();

			// generates a channelmessage
			QByteArray generateChannelMessage(QString message);

			// generates a privatemessage
			QByteArray generatePrivateMessage(QString message);

			// return baseport
			unsigned int getBasePort();

	}; // class Cha2PProtocol
} // namespace QtCha2P
#endif // _QTCHA2P_CHA2PPROTOCOL_HPP_
