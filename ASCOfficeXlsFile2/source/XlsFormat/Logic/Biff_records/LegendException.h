#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of LegendException record in BIFF8
class LegendException: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(LegendException)
	BASE_OBJECT_DEFINE_CLASS_NAME(LegendException)
public:
	LegendException();
	~LegendException();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	_UINT16	iss;
	bool	fDelete;
	bool	fLabel;

	int serialize(std::wostream & _stream);


};

} // namespace XLS

