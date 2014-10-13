#include "precompiled_xls.h"
#include "DataFormat.h"

namespace XLS
{;

DataFormat::DataFormat()
{
}


DataFormat::~DataFormat()
{
}


BaseObjectPtr DataFormat::clone()
{
	return BaseObjectPtr(new DataFormat(*this));
}


void DataFormat::writeFields(CFRecord& record)
{
	unsigned __int16 flags = 0;
	SETBIT(flags, 0, fUnknown);
	record << xi << yi << iss << flags;
}


void DataFormat::readFields(CFRecord& record)
{
	unsigned __int16 flags;
	record >> xi >> yi >> iss >> flags;
	fUnknown = GETBIT(flags, 0);
}

} // namespace XLS
