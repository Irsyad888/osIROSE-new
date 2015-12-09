#ifndef _CLOGINCLIENT_H_
#define _CLOGINCLIENT_H_

#include "croseclient.h"

class CLoginClient : public CRoseClient
{
public:
	CLoginClient( );
	CLoginClient( tcp::socket _sock );

protected:
	bool HandlePacket( uint8_t* _buffer );
};

#endif
