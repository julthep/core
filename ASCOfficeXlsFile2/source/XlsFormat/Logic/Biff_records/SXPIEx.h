#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of SXPIEx record in BIFF8
class SXPIEx: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SXPIEx)
	BASE_OBJECT_DEFINE_CLASS_NAME(SXPIEx)
public:
	SXPIEx();
	~SXPIEx();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeSXPIEx;
};

} // namespace XLS

