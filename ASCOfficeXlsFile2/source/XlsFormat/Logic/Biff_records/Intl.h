#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of Intl record in BIFF8
class Intl: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Intl)
	BASE_OBJECT_DEFINE_CLASS_NAME(Intl)
public:
	Intl();
	~Intl();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeIntl;
};

} // namespace XLS

