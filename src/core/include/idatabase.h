#ifndef _IDATABASE_H_
#define _IDATABASE_H_

#include <stdint.h>
#include <string>
#include <memory>

class	IResult
{
	public:
		IResult() : row(0) {}
		virtual ~IResult() {}

		virtual void	useRow(uint32_t _row) {row = _row;}

		// return false if the value is NULL, true otherwise
		virtual	bool	getString(std::string const&, std::string &data) = 0;
		virtual bool	getInt(std::string const&, uint32_t &data) = 0;
		virtual bool	getFloat(std::string const&, float &data) = 0;

	protected:
		uint32_t	row;
};

class IDatabase
{
public:
	virtual ~IDatabase() {};

	virtual void	Connect(std::string _host, std::string _database, std::string _user, std::string _password) = 0;

	virtual void	QExecute(std::string _query) = 0;
	virtual std::unique_ptr<IResult>	QStore(std::string	_query) = 0;
};

#endif
