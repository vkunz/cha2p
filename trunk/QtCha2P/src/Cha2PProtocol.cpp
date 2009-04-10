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
		// set baseport
		m_basePort = 3000;
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
		QDataStream datastream(&array, QIODevice::ReadWrite);
		
		// big-fat-switch-case of all protocol bits
		// the protocol-bits need to be cast into an unsigned char because of the protocol
		switch(bits)
		{
			case REQUESTCONTACTS:
				datastream << static_cast<unsigned char>(REQUESTCONTACTS);
				break;
			case SENDCONTACTS:
				datastream << static_cast<unsigned char>(SENDCONTACTS);
				break;
			case HELLO:
				datastream << static_cast<unsigned char>(HELLO);
				break;
			case GOODBYE:
				datastream << static_cast<unsigned char>(GOODBYE);
				break;
			case CHANNELMESSAGE:
				datastream << static_cast<unsigned char>(CHANNELMESSAGE);
				break;
			case PRIVATEMESSAGE:
				datastream << static_cast<unsigned char>(PRIVATEMESSAGE);
				break;
 		}

		return array;
	}

	// generates output of an given protocolrequst with given message
	QByteArray Cha2PProtocol::generateOutput(Cha2PProtocol::ProtocolBits bits, QString message)
	{
		// QByteArray to store the whole protocol-frame
		QByteArray protocolFrame;

		// get protocol bit into array
		QByteArray protocolBit = generateOutput(bits);

		// QByteArray to store size
		QByteArray protocolSize;

		// QByteArray to store message
		QByteArray protocolMessage;

		// QDataStream to convert into datastream
		QDataStream sizestream(&protocolSize, QIODevice::ReadWrite);

		// add message length as unsigned char
		sizestream << static_cast<unsigned int>(message.size());

		// Bytearray of the message
		protocolMessage = message.toAscii();

		// add bit to frame
		protocolFrame += protocolBit;

		// add size to frame
		protocolFrame += protocolSize;
		
		// add message to frame
		protocolFrame += protocolMessage;

		return protocolFrame;
	}
	
	// generates a requestContactList byte
	QByteArray Cha2PProtocol::generateRequestContacts(QString ip)
	{
		// generate
		return generateOutput(REQUESTCONTACTS, ip);
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
	
	unsigned int Cha2PProtocol::getBasePort()
	{
		return m_basePort;
	}
} // namespace QtCha2P
