#ifndef _QTCHA2P_ABSTRACTPROTOCOL_HPP_
#define _QTCHA2P_ABSTRACTPROTOCOL_HPP_

#include <QtCore/QObject>

namespace QtCha2P
{
	class AbstractProtocol : public QObject
	{
		private:
		
		public:
			// ctor
			AbstractProtocol();
			
			// dtor
			~AbstractProtocol();

	}; // class AbstractProtocol
} // namespace QtCha2P 
#endif // _QTCHA2P_ABSTRACTPROTOCOL_HPP_
