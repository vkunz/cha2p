#ifndef _QTCHA2P_CONFIGURATION_H_
#define _QTCHA2P_CONFIGURATION_H_

#include <QString>

namespace QtCha2P
{
	class Configuration
	{
	private:
		// pointer to instance
		static Configuration* m_instance;

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

	}; // class Configuration
} // namespace QtCha2P

#endif // _QTCHA2P_CONFIGURATION_H_

