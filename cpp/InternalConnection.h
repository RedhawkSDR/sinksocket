/*
 * InternalConnection.h
 *
 *  Created on: Mar 12, 2015
 *      Author: pcwolfr
 */

#ifndef INTERNALCONNECTION_H_
#define INTERNALCONNECTION_H_

#include "BoostClient.h"
#include "BoostServer.h"
#include "quickstats.h"
#include "struct_props.h"


typedef std::map<unsigned short, double> portBytesMap;
typedef std::map<unsigned short, unsigned short> portByteSwapMap;
typedef std::map<unsigned short, client *> portClientMap;
typedef std::map<unsigned short, server *> portServerMap;
typedef std::map<unsigned short, QuickStats *> portStatsMap;

/*
 * This class manages server or client connections
 * based on a Connection_struct, returning
 * ConnectionStat_struct(s) to notify the owner of
 * an object of this type's current status
 */
class InternalConnection {
	ENABLE_LOGGING
public:
	InternalConnection();
	InternalConnection(const Connection_struct &connection);
	virtual ~InternalConnection();

private:
	/* Make the copy constructor private so that it
	 * can't be called by anyone else.  The internal
	 * pointers require move semantics as opposed to
	 * copy semantics
	 */
	InternalConnection(const InternalConnection &copy);

public:
	std::vector<unsigned short> getByteSwaps() const;

	bool operator==(const Connection_struct &connection) const;
	std::vector<ConnectionStat_struct> setConnection(const Connection_struct &connection);

	template <typename T, typename U>
	std::vector<ConnectionStat_struct> write(std::vector<T, U> &data);

	std::vector<ConnectionStat_struct> writeByteSwap(std::map<unsigned short, std::vector<char> > &dataMap);

private:
	void cleanUp();
	ConnectionStat_struct createClientConnection(const unsigned short &port, const std::string &ip, const unsigned short &byteSwap);
	ConnectionStat_struct createServerConnection(const unsigned short &port, const unsigned short &byteSwap);
	std::vector<ConnectionStat_struct> populateClientMap(const Connection_struct &connection);
	std::vector<ConnectionStat_struct> populateServerMap(const Connection_struct &connection);

private:
	portStatsMap bytesPerSec;
	portByteSwapMap byteSwaps;
	portBytesMap bytesSent;
	portClientMap *clients;
	Connection_struct connectionInfo;
	portServerMap *servers;
};

#include "InternalConnectionTemplate.h"

#endif /* INTERNALCONNECTION_H_ */
