#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
#include <QtCore/QIODevice>
#include <QtCore/QString>

#include "Cha2PProtocol.hpp"

namespace QtCha2P
{
	// ctor
	Cha2PProtocol::Cha2PProtocol()
	{
	}
	
	// dtor
	Cha2PProtocol::~Cha2PProtocol()
	{
	}
	
	// generates output of an given protocolrequst without message
	QByteArray Cha2PProtocol::generateOutput(Cha2PProtocol::ProtocolBits bits)
	{
		// QByteArray to store the data
		QByteArray array;
		
		// QDataStream to convert into datastream
		QDataStream datastream(&array, QIODevice::WriteOnly);
		
		// big-fat-switch-case of all protocol bits
		switch(bits)
		{
			case REQUESTCONTACTS:
				datastream << REQUESTCONTACTS;
				break;
			case SENDCONTACTS:
				datastream << SENDCONTACTS;
				break;
			case HELLO:
				datastream << HELLO;
				break;
			case GOODBYE:
				datastream << GOODBYE;
				break;
			case CHANNELMESSAGE:
				datastream << CHANNELMESSAGE;
				break;
			case PRIVATEMESSAGE:
				datastream << PRIVATEMESSAGE;
				break;
 		}
		
		return array;
	}

	// generates output of an given protocolrequst with given message
	QByteArray Cha2PProtocol::generateOutput(Cha2PProtocol::ProtocolBits bits, QString message)
	{
		// QByteArray to store the data
		QByteArray array = generateOutput(bits);
		
		// QDataStream to convert into datastream
		QDataStream datastream(&array, QIODevice::WriteOnly);
		
		// add message to the ByteArray
		datastream << message;
		
		return array;
	}
	
	// generates a requestContactList byte
	QByteArray Cha2PProtocol::generateRequestContacts()
	{
		// generate
		return generateOutput(REQUESTCONTACTS);
	}
	
	// generates a replyContactList byte
	QByteArray Cha2PProtocol::generateSendContacts(QString contacts)
	{
		// generate
		return generateOutput(SENDCONTACTS, contacts);
	}

	// generates a hello byte
	QByteArray Cha2PProtocol::generateHello(QString nickname)
	{
		// generate
		return generateOutput(HELLO, nickname);
	}
	
	// generates a goodbye byte
	QByteArray Cha2PProtocol::generateGoodBye()
	{
		// generate
		return generateOutput(GOODBYE);
	}
	
	// generates a channelmessage
	QByteArray Cha2PProtocol::generateChannelMessage(QString message)
	{
		// generate
		return generateOutput(CHANNELMESSAGE, message);
	}
	
	// generates a privatemessage
	QByteArray Cha2PProtocol::generatePrivateMessage(QString message)
	{
		// generate
		return generateOutput(PRIVATEMESSAGE, message);
	}
} // namespace QtCha2P
