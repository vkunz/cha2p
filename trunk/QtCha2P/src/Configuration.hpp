#ifndef _QTCHA2P_CONFIGURATION_HPP_
#define _QTCHA2P_CONFIGURATION_HPP_

#include <QtCore/QString>
#include <QtNetwork/QHostAddress>

namespace QtCha2P
{
	class Configuration
	{
	private:
		// pointer to instance
		static Configuration* m_instance;

		// own nickname
		QString m_nickName;

		// own ipAddress
		QHostAddress m_ipAddress;
		
		// stores threadcounter
		unsigned int m_threads;

	protected:
		// ctor
		Configuration();

		// prevent copying
		// no copy-constructor
		Configuration(const Configuration&);

		// no assignment-operator
		Configuration& operator=(const Configuration&);

	public:

		// dtor
		~Configuration();

		// returns the one and only instance of this class
		static Configuration* getInstance();

		// read config file and store its data
		void readConfigFile(QString filename);

		// return own ipAddress
		const QHostAddress getIpAddress();

		// return own nicknName
		const QString getNickName();
		
		// return maxthreadcounter
		unsigned int getThreadCounter();

		// set own ipAddress
		void setIpAddress(const QHostAddress ipAdress);

		// set own nickName
		void setNickName(const QString nick);
		
		// set maxthreadcounter
		void setThreadCounter(const unsigned int counter);

	}; // class Configuration
} // namespace QtCha2P

#endif // _QTCHA2P_CONFIGURATION_HPP_

