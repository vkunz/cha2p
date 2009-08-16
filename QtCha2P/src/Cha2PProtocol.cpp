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

		// set entryport
		m_entryPort = 3001;
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
			case REQUESTENTRY:
				datastream << static_cast<unsigned char>(REQUESTENTRY);
				break;
			case SENDENTRY:
				datastream << static_cast<unsigned char>(SENDENTRY);
				break;
 		}

#if defined(_DEBUG_)
		// extract protobyte
		m_protocolBits = bits;
#endif

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

#if defined(_DEBUG_)
		// set messagesize
		m_messageLength = message.size();
		
		// set message
		m_message = message;
		
		debug(false);
#endif
		return protocolFrame;
	}
	
	// analyze incoming protocol Frame
	void Cha2PProtocol::analyzeInput(QHostAddress& host, QByteArray& input)
	{
		// data stream to extract protbit and length
		QDataStream stream(&input, QIODevice::ReadOnly);

		// get message and store into bytearray
		QByteArray tmp = input.right(input.length() - (sizeof(unsigned char) + sizeof(unsigned int)));

		// extract protbit
		stream >> m_protocolBits;

		// extract length
		stream >> m_messageLength;

		// get message
		m_message = tmp;

#if defined(_DEBUG_)
		// debug incoming
		debug(true, host);
#endif

		// big-fat-switch-case of all protocol bits
		switch(m_protocolBits)
		{
			case REQUESTCONTACTS:
				// emit signal
				emit sendContactsList(m_message, host);
				break;
			case SENDCONTACTS:
				// emit signal
				emit receivedContactList(m_message);
				break;
			case HELLO:
				// emit signal
				emit receivedHello(host, m_message);
				break;
			case GOODBYE:
				// emit signal
				emit receivedHello(host, m_message);
				break;
			case CHANNELMESSAGE:
				// emit signal
				emit receivedChannelMessage(host, m_message);
				break;
			case PRIVATEMESSAGE:
				// emit signal
				emit receivedPrivateMessage(host, m_message);
				break;
			case REQUESTENTRY:
				// emit signal
				emit sendEntry(m_message, host);
				break;
			case SENDENTRY:
				// emit signal
				emit receivedEntry(m_message);
				break;
 		}
		
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
	
	// generate requestentry
	QByteArray Cha2PProtocol::generateRequestEntry(QString message)
	{
		// generate
		return generateOutput(REQUESTENTRY, message);
	}

	// generate sendentry
	QByteArray Cha2PProtocol::generateSendEntry(QString message)
	{
		// generate
		return generateOutput(SENDENTRY, message);
	}
	
	unsigned short Cha2PProtocol::getBasePort()
	{
		return m_basePort;
	}
	
	unsigned short Cha2PProtocol::getEntryPort()
	{
		return m_entryPort;
	}
	
#if defined(_DEBUG_)
	void Cha2PProtocol::debug(bool inc, QHostAddress host)
	{
		// check if incoming or outgoing
		if(inc)
		{
			qDebug() << "----------INCOMING-----------------";
		}
		else
		{
			qDebug() << "----------OUTGOING-----------------";
		}
		
		qDebug() << "Protocol: " << m_protocolBits;
		qDebug() << "Length: " << m_messageLength;
		qDebug() << "Message: " << m_message;
		qDebug() << "Client-IP: " << host.toString();
		qDebug() << "-----------------------------------";
	}
#endif
} // namespace QtCha2P
